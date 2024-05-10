#ifndef CUENTANODOS
#define CUENTANODOS
#include "ArbolesELBIN.h"

template <typename T>
int CuentaNodos(const ArbolELBIN<T>& arb)
{
    return CuentaNodosR(arb, arb.raiz());
}

template <typename T>
int CuentaNodosR(const ArbolELBIN<T>& arb, typename ArbolELBIN<T>::nodo n)
{
    if(n == ArbolELBIN<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + CuentaNodosR(arb, arb.Hizqui(n)) + CuentaNodosR(arb, arb.Hdere(n));
    }
}


#endif // CUENTANODOS
