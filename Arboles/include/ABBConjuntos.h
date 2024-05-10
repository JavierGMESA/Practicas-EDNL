#ifndef ABBCONJUNTOS
#define ABBCONJUNTOS
#include "ArbolesELBIBUS.h"
#include "ABBequilibrado.h"

template <typename T>
class Conjunto
{
public:
    void insertar(const T& e);
    void eliminar(const T& e);
    bool pertecece(const T& e) const;
    void mostrarRaizHijos() const;
    bool vacio() const;

    template <typename U>
    friend Conjunto<U> operator+(Conjunto<U> con1, const Conjunto<U>& con2);
    template <typename U>
    friend Conjunto<U> operator-(Conjunto<U> con1, const Conjunto<U>& con2);
    template <typename U>
    friend Conjunto<U> operator/(const Conjunto<U>& con1, const Conjunto<U>& con2);
private:
    ArbolELBIBUS<T> arb;
    void mostrar(const ArbolELBIBUS<T>& arb) const;
};

template <typename T>
void Conjunto<T>::insertar(const T& e)
{
    arb.insertar(e);
    ABBequilibrado(arb);
    std::cout << "Termina de insertar" << std::endl;
}

template <typename T>
void Conjunto<T>::eliminar(const T& e)
{
    arb.eliminar(e);
    ABBequilibrado(arb);
}

template <typename T>
bool Conjunto<T>::pertecece(const T& e) const
{
    if(arb.buscar(e).vacio())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
void Conjunto<T>::mostrarRaizHijos() const
{
    mostrar(arb);
    std::cout << std::endl;
}

template <typename T>
void Conjunto<T>::mostrar(const ArbolELBIBUS<T>& arb) const
{
    if(!arb.vacio())
    {
        std::cout << arb.element() << ' ';
        mostrar(arb.izqu());
        mostrar(arb.dere());
    }
}

template <typename T>
bool Conjunto<T>::vacio() const
{
    return arb.vacio();
}

template <typename U>
Conjunto<U> operator+(Conjunto<U> con1, const Conjunto<U>& con2)
{
    unionConjunto(con1.arb, con2.arb);
    return con1;
}

template <typename T>
void unionConjunto(ArbolELBIBUS<T>& arb1, const ArbolELBIBUS<T>& arb2)
{
    if(!arb2.vacio())
    {
        unionConjunto(arb1, arb2.izqu());
        arb1.insertar(arb2.element());
        unionConjunto(arb1, arb2.dere());
    }
}

template <typename U>
Conjunto<U> operator-(Conjunto<U> con1, const Conjunto<U>& con2)
{
    diffeABB(con1.arb, con2.arb);
    return con1;
}

template <typename T>
void diffeABB(ArbolELBIBUS<T>& arb1, const ArbolELBIBUS<T>& arb2)
{
    if(!arb2.vacio())
    {
        diffeABB(arb1, arb2.izqu());
        arb1.eliminar(arb2.element());
        diffeABB(arb1, arb2.dere());
    }
}

template <typename U>
Conjunto<U> operator/(const Conjunto<U>& con1, const Conjunto<U>& con2)
{
    return (con1 - con2) + (con2 - con1);
}

#endif