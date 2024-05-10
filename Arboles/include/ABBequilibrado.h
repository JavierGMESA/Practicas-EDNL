#ifndef ABBEQUILIBRADO
#define ABBEQUILIBRADO
#include "ArbolesELBIBUS.h"
#include <iostream>

template <typename T>
void ABBequilibrado(ArbolELBIBUS<T>& arb)
{
    int n_e = numNodos(arb);
    int izq = 0;
    int der = n_e - 1;
    T* elementos = new T[n_e];
    ColaelemABB(arb, elementos);
    ArbolELBIBUS<T> arbEqui;
    insertarElem(arbEqui, elementos, izq, der);
    delete[] elementos;
    arb = arbEqui;
}

template <typename T>
void insertarElem(ArbolELBIBUS<T>& arb, T* elementos, int izq, int der)
{
    if(izq <= der)
    {
        if(izq == der)
        {
            arb.insertar(elementos[izq]);
        }
        else
        {
            arb.insertar(elementos[izq + (der - izq) / 2]);
            insertarElem(arb, elementos, izq, (izq + (der - izq) / 2) - 1);
            insertarElem(arb, elementos, (izq + (der - izq) / 2) + 1, der);
        }
    }
}

template <typename T>
int numNodos(const ArbolELBIBUS<T>& arb)
{
    if(arb.vacio())
    {
        return 0;
    }
    else
    {
        return 1 + numNodos(arb.izqu()) + numNodos(arb.dere());
    }
}

template <typename T>
void ColaelemABB(const ArbolELBIBUS<T>& arb, T* elementos)
{
    int index = 0;
    ColaelemABBR(arb, elementos, index);
}

template <typename T>
void ColaelemABBR(const ArbolELBIBUS<T>& arb, T* elementos, int& index)
{
    if(!arb.vacio())
    {
        ColaelemABBR(arb.izqu(), elementos, index);
        elementos[index] = arb.element();
        ++index;
        ColaelemABBR(arb.dere(), elementos, index);
    }
}


#endif