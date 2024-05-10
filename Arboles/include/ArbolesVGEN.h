#ifndef ARBOLESVGEN
#define ARBOLESVGEN
#include <cassert>
#include "listaSD.h"

template <typename T>
class ArbolVGEN
{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    explicit ArbolVGEN(const size_t& nodos);

    bool vacio() const;
    void insertarRaiz(const T& e);
    void insertarHizqui(nodo n, const T& e);
    void insertarHerdere(nodo n, const T& e);
    void eliminarRaiz();
    void eliminarHizqui(nodo n);
    void eliminarHerdere(nodo n);
    const T& element(nodo n) const;
    T& element(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo Hizqui(nodo n) const;
    nodo Herdere(nodo n) const;

    ArbolVGEN(const ArbolVGEN<T>& arb);
    ArbolVGEN<T>& operator =(const ArbolVGEN<T>& arb);
    ~ArbolVGEN();
private:
    struct celda
    {
        T elem;
        nodo Padre;
        listaSD<nodo> hijos;
    };
    celda *vect;
    size_t maxNodos;
    size_t numNodos;
};

template <typename T>
const typename ArbolVGEN<T>::nodo ArbolVGEN<T>::NODO_NULO(SIZE_MAX);

template <typename T>
ArbolVGEN<T>::ArbolVGEN(const size_t& nodos)
{
    int i;
    vect = new celda[nodos];
    maxNodos = nodos;
    numNodos = 0;
    for(i = 0; i < maxNodos; ++i)
    {
        vect[i].Padre = ArbolVGEN<T>::NODO_NULO;
    }
}

template <typename T>
bool ArbolVGEN<T>::vacio() const
{
    return numNodos == 0;
}

template <typename T>
void ArbolVGEN<T>::insertarRaiz(const T& e)
{
    assert(numNodos == 0);
    vect[0].elem = e;
    numNodos = 1;
}

template <typename T>
void ArbolVGEN<T>::insertarHizqui(nodo n, const T& e)
{
    nodo i;
    assert(numNodos != 0);
    assert(n >= 0 && n <= maxNodos - 1);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    assert(numNodos < maxNodos);

    for(i = 1; vect[i].Padre != ArbolVGEN<T>::NODO_NULO; ++i);
    vect[i].elem = e;
    vect[i].Padre = n;

    listaSD<nodo>& lis = vect[n].hijos;
    lis.insertar(lis.primera(), i);

    ++numNodos;
}

template <typename T>
void ArbolVGEN<T>::insertarHerdere(nodo n, const T& e)
{
    int i;
    listaSD<nodo>::posicion p;
    assert(numNodos != 0);
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    assert(numNodos < maxNodos);

    for(i = 1; vect[i].Padre != ArbolVGEN<T>::NODO_NULO; ++i);
    vect[i].elem = e;
    vect[i].Padre = vect[n].Padre;
    p = vect[vect[n].Padre].hijos.primera();
    while(vect[vect[n].Padre].hijos.elemento(p) != n)
    {
        p = vect[vect[n].Padre].hijos.siguiente(p);
    }
    vect[vect[n].Padre].hijos.insertar(vect[vect[n].Padre].hijos.siguiente(p), i);
    ++numNodos;
}

template <typename T>
void ArbolVGEN<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    numNodos = 0;
}

template <typename T>
void ArbolVGEN<T>::eliminarHizqui(nodo n)
{
    int i;
    assert(numNodos != 0);
    assert(n >= 0 && n <= maxNodos - 1);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    assert(!vect[n].hijos.vacia());
    assert(vect[vect[n].hijos.elemento(vect[n].hijos.primera())].hijos.vacia());

    vect[vect[n].hijos.elemento(vect[n].hijos.primera())].Padre = ArbolVGEN<T>::NODO_NULO;
    vect[n].hijos.eliminar(vect[n].hijos.primera());
    --numNodos;
}

template <typename T>
void ArbolVGEN<T>::eliminarHerdere(nodo n)
{
    int i;
    listaSD<nodo>::posicion p;
    assert(numNodos != 0);
    assert(n >= 0 && n <= maxNodos - 1);
    listaSD<nodo>& lis = vect[vect[n].Padre].hijos;
    p = lis.primera();
    while(lis.elemento(p) != n)
    {
        p = lis.siguiente(p);
    }
    p = lis.siguiente(p);
    assert(p != lis.fin());
    assert(vect[lis.elemento(p)].hijos.vacia());
    vect[lis.elemento(p)].Padre = ArbolVGEN<T>::NODO_NULO;
    lis.eliminar(p);
    --numNodos;
}

template <typename T>
const T& ArbolVGEN<T>::element(nodo n) const
{
    assert(numNodos > 0);
    assert(n >= 0 && n <= maxNodos - 1);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    return vect[n].elem;
}

template <typename T>
T& ArbolVGEN<T>::element(nodo n)
{
    assert(numNodos > 0);
    assert(n >= 0 && n <= maxNodos - 1);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    return vect[n].elem;
}

template <typename T>
typename ArbolVGEN<T>::nodo ArbolVGEN<T>::raiz() const
{
    if(numNodos == 0)
    {
        return ArbolVGEN<T>::NODO_NULO;
    }
    else
    {
        return 0;
    }
}

template <typename T>
typename ArbolVGEN<T>::nodo ArbolVGEN<T>::padre(nodo n) const
{
    assert(numNodos > 0);
    assert(n >= 0 && n <= maxNodos);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    return vect[n].Padre;
}

template <typename T>
typename ArbolVGEN<T>::nodo ArbolVGEN<T>::Hizqui(nodo n) const
{
    assert(numNodos > 0);
    assert(n >= 0 && n <= maxNodos);
    assert(n == 0 || vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    listaSD<nodo>& lis = vect[n].hijos;
    if(lis.vacia())
    {
        return ArbolVGEN<T>::NODO_NULO;
    }
    else
    {
        return lis.elemento(lis.primera());
    }
}

template <typename T>
typename ArbolVGEN<T>::nodo ArbolVGEN<T>::Herdere(nodo n) const
{
    listaSD<nodo>::posicion p;
    assert(numNodos > 0);
    assert(n >= 0 && n <= maxNodos);
    assert(vect[n].Padre != ArbolVGEN<T>::NODO_NULO);
    if(n == 0)
    {
        return ArbolVGEN<T>::NODO_NULO;
    }
    else
    {
        p = vect[vect[n].Padre].hijos.primera();
        while(vect[vect[n].Padre].hijos.elemento(p) != n)
        {
            p = vect[vect[n].Padre].hijos.siguiente(p);
        }
        p = vect[vect[n].Padre].hijos.siguiente(p);
        if(p == vect[vect[n].Padre].hijos.fin())
        {
            return ArbolVGEN<T>::NODO_NULO;
        }
        else
        {
            return vect[vect[n].Padre].hijos.elemento(p);
        }
    }
}

template <typename T>
ArbolVGEN<T>::ArbolVGEN(const ArbolVGEN<T>& arb)
{
    int i = 0;
    vect = new celda[arb.maxNodos];
    maxNodos = arb.maxNodos;
    numNodos = arb.numNodos;
    for(i = 0; i < maxNodos; ++i)
    {
        vect[i] = arb.vect[i];
    }
}

template <typename T>
ArbolVGEN<T>& ArbolVGEN<T>::operator =(const ArbolVGEN<T>& arb)
{
    int i;
    if(this != &arb)
    {
        if(maxNodos != arb.maxNodos)
        {
            delete[] vect;
            vect = new celda[arb.maxNodos];
            maxNodos = arb.maxNodos;
        }
        numNodos = arb.numNodos;
        for(i = 0; i < maxNodos; ++i)
        {
            vect[i] = arb.vect[i];
        }
    }
    return *this;
}

template <typename T>
ArbolVGEN<T>::~ArbolVGEN()
{
    delete[] vect;
}


#endif // ARBOLESVGEN
