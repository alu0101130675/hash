#pragma once

#include <list>

#include "sequence.hpp"

template <class CLAVE>
class List : public Sequence<CLAVE>
{
private:
    std::list<CLAVE> list_;

public:
    List() = default;
    ~List() = default;
    bool insert(const CLAVE &x);
    bool search(const CLAVE &x) const;
    bool isFull() const;
};
template <class CLAVE>
bool List<CLAVE>::insert(const CLAVE &x)
{
    if (!search(x))
    {
        list_.push_back(x);
        return true;
    }
    return false;
}

template <class CLAVE>
bool List<CLAVE>::search(const CLAVE &x) const
{
    for (auto &i : list_)
    {
        if (i == x)
        {
            return true;
        }
    }
    return false;
}

template <class CLAVE>
bool List<CLAVE>::isFull() const
{
    return false;
}
