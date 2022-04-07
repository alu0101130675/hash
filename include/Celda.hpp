#pragma once
#include <iostream>
#include <sequence.hpp>
#include <vector>

template <class CLAVE>
class Celda : public Sequence<CLAVE> {
  private:
    int nBloques;//tamaño del vector
    int lleno; //posicion para meter
    std::vector<CLAVE> V;

  public:
    Celda(void);
    Celda(int size);
    //~Celda(void);
    bool search(const CLAVE &clave) const;
    bool insert(const CLAVE &clave);
    bool isFull(void) const;
};

template <class CLAVE>
Celda<CLAVE>::Celda(void) : nBloques(0)
{
}
template <class CLAVE>
Celda<CLAVE>::Celda(int size) : nBloques(size)
{
    V.resize(nBloques);
    lleno = 0;
}

/*template <class CLAVE>
Celda<CLAVE>::~Celda()
{
    if (V != NULL)
    {
        delete[] V;
        V = NULL;
        nBloques = 0;
    }
}
*/
template <class CLAVE>
bool Celda<CLAVE>::search(const CLAVE &clave) const
{
    for (int i = 0; i < nBloques; i++)
        if (V[i] == clave)
            return true;

    return false;
}

template <class CLAVE>
bool Celda<CLAVE>::insert(const CLAVE &clave)
{
   if(!isFull() && !search(clave))
   {
       V[lleno] = clave;
       lleno++;
       return true;
   }

    return false;
}

template <class CLAVE>
bool Celda<CLAVE>::isFull() const
{
    if (lleno == nBloques)
            return true;

    return false;
}
