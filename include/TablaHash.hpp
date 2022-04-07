#pragma once
#include <sequence.hpp>
#include <Celda.hpp>
#include <list.hpp>
#include <fDispersion.hpp>
#include <fD_aleatoria.hpp>
#include <fD_modulo.hpp>
#include <fD_suma.hpp>
#include <fExplorar.hpp>
#include <fE_lineal.hpp>
#include <fE_doble.hpp>
#include <fE_cuadratica.hpp>
#include <fE_redisp.hpp>

template <class CLAVE>
class TablaHash
{
private:
    int tableSize; // tablesize
    int nBloques;

    Sequence<CLAVE> **vCelda;

    fDispersion<CLAVE> *dispersion;
    fExplorar<CLAVE> *exploracion;

public:
    TablaHash(int celdas, fDispersion<CLAVE> *funcion_h,int bloques = 0, fExplorar<CLAVE> *funcion_g = nullptr);
    ~TablaHash();

    bool search(const CLAVE clave) const;
    bool insert(const CLAVE clave) const;
};

template <class CLAVE>
TablaHash<CLAVE>::TablaHash(int celdas, fDispersion<CLAVE> *funcion_h, int bloques, fExplorar<CLAVE> *funcion_g) : tableSize(celdas), nBloques(bloques),
                                                                                                                   dispersion(funcion_h), exploracion(funcion_g)
{
    vCelda = new Sequence<CLAVE> *[tableSize];

    if (exploracion == nullptr)
    {
        for (int i = 0; i < tableSize; i++)
            vCelda[i] = new List<CLAVE>();
    }
    else
    {
        for (int i = 0; i < tableSize; i++)
            vCelda[i] = new Celda<CLAVE>(nBloques);
    }
}

template <class CLAVE>
TablaHash<CLAVE>::~TablaHash()
{
    if (vCelda != NULL)
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (vCelda[i] != NULL)
            {
                delete[] vCelda[i];
                vCelda[i] = NULL;
            }
        }
        delete[] vCelda;
        nBloques = 0;
        tableSize = 0;
    }
}

template <class CLAVE>
bool TablaHash<CLAVE>::search(const CLAVE clave) const
{
    bool encontrado = false;
    int intento = 1;
    int posicion = dispersion->h(clave);

    if (!(vCelda[posicion]->search(clave)))
    {
        while (!encontrado && intento < tableSize)
        {
            int posicion2 = exploracion->g(clave, intento);
            encontrado = vCelda[posicion2]->search(clave);
            intento++;
        }
        return encontrado;
    }

    else
        return true;
}

template <class CLAVE>
bool TablaHash<CLAVE>::insert(const CLAVE clave) const
{
    int intento = 1;
    bool insert = false;
    int posicion = dispersion->h(clave);
    if (!(vCelda[posicion]->insert(clave)))
    {
        while (insert==false && intento <= tableSize)
        {
            int posicion2 = exploracion->g(clave, intento);
            insert = vCelda[posicion2]->insert(clave);
            intento++;
        }

        return insert;
    }
    else
        return true;
}