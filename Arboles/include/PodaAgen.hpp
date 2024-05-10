#ifndef PODAAGEN
#define PODAAGEN
#include "ArbolesELGEN.h"

template <typename T>
typename ArbolELGEN<T>::nodo buscarElem(typename ArbolELGEN<T>::nodo n, const T& e, const ArbolELGEN<T>& arb)
{
    typename ArbolELGEN<T>::nodo buscado = ArbolELGEN<T>::NODO_NULO;
    if(n == ArbolELGEN<T>::NODO_NULO)
    {
        return buscado;
    }
    else
    {
        if(arb.element(n) == e)
        {
            return n;
        }
        else
        {
            n = arb.Hizqui(n);
            while(n != ArbolELGEN<T>::NODO_NULO && buscado == ArbolELGEN<T>::NODO_NULO)
            {
                if(buscarElem(n, e, arb) != ArbolELGEN<T>::NODO_NULO)
                {
                    buscado = buscarElem(n, e, arb);
                }
                n = arb.Herdere(n);
            }
            return buscado;
        }
    }
}

template <typename T>
void finDescendencia(typename ArbolELGEN<T>::nodo n, ArbolELGEN<T>& arb)
{
    typename ArbolELGEN<T>::nodo na = arb.Hizqui(n);
    while(na != ArbolELGEN<T>::NODO_NULO)
    {
        if(arb.Hizqui(na) != ArbolELGEN<T>::NODO_NULO)
        {
            finDescendencia(na, arb);
        }
        arb.eliminarHizqui(n);
        na = arb.Hizqui(n);
    }
}

template <typename T>
void podar(const T& e, ArbolELGEN<T>& arb)
{
    typename ArbolELGEN<T>::nodo n = buscarElem(arb.raiz(), e, arb);
    if(n != ArbolELGEN<T>::NODO_NULO)
    {
        finDescendencia(n, arb);
        if(n == arb.raiz())
        {
            arb.eliminarRaiz();
        }
        else
        {
            if(arb.Hizqui(arb.Padre(n)) == n)
            {
                arb.eliminarHizqui(arb.Padre(n));
            }
            else
            {
                typename ArbolELGEN<T>::nodo na = arb.Hizqui(arb.Padre(n));
                while(arb.Herdere(na) != n)
                {
                    na = arb.Herdere(na);
                }
                arb.eliminarHerdere(na);
            }
        }
    }
}


#endif