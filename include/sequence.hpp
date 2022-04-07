#pragma once

template <class CLAVE>
class Sequence
{
public:
  virtual bool search(const CLAVE &k) const = 0;
  virtual bool insert(const CLAVE &k) = 0;
  virtual bool isFull() const = 0;
};