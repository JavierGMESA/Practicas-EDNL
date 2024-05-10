#ifndef ALTURAARBOL
#define ALTURAARBOL
#include "ArbolesELBIN.h"

template <typename T>
int AlturaArbol(const ArbolELBIN<T>& arb)
{
    return AlturaArbolR(arb, arb.raiz());
}

template <typename T>
int AlturaArbolR(const ArbolELBIN<T>& arb, typename ArbolELBIN<T>::nodo n)
{
    if(n == ArbolELBIN<T>::NODO_NULO)
    {
        return -1;
    }
    else
    {
        if(AlturaArbolR(arb, arb.Hizqui(n)) > AlturaArbolR(arb, arb.Hdere(n)))
        {
            return 1 + AlturaArbolR(arb, arb.Hizqui(n));
        }
        else
        {
            return 1 + AlturaArbolR(arb, arb.Hdere(n));
        }
    }
}


#endif // ALTURAARBOL
