#ifndef ARBOLREFLEJADO
#define ARBOLREFLEJADO
#include <string>
#include "ArbolesELBIN.h"

template <typename T>
ArbolELBIN<T> ArbolRefle(const ArbolELBIN<T>& B)
{
    ArbolELBIN<T> BR;
    if(!B.vacio())
    {
        BR.insertarRaiz(B.element(B.raiz()));
        ArbolRefleR(B.raiz(), BR.raiz(), B, BR);
    }
    return BR;
}

template <typename T>
void ArbolRefleR(typename ArbolELBIN<T>::nodo n1, typename ArbolELBIN<T>::nodo n2, const ArbolELBIN<T>& B, ArbolELBIN<T>& BR)
{
    if(B.Hizqui(n1) != ArbolELBIN<T>::NODO_NULO)
    {
        BR.insertarHdere(n2, B.element(B.Hizqui(n1)));
        ArbolRefleR(B.Hizqui(n1), BR.Hdere(n2), B, BR);
    }
    if(B.Hdere(n1) != ArbolELBIN<T>::NODO_NULO)
    {
        BR.insertarHizqui(n2, B.element(B.Hdere(n1)));
        ArbolRefleR(B.Hdere(n1), BR.Hizqui(n2), B, BR);
    }
}


#endif // ARBOLREFLEJADO
