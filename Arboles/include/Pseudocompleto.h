#ifndef PSEUDOCOMPLETO
#define PSEUDOCOMPLETO
#include <cassert>
#include "AlturaArbol.h"

template <typename T>
bool ArbolPseudoC(const ArbolELBIN<T>& arb)
{
    if(AlturaArbol(arb) == 0)
    {
        return false;
    }
    else
    {
        return ArbolPseudoCR(arb.raiz(), 0, arb);
    }
}

template <typename T>
bool ArbolPseudoCR(typename ArbolELBIN<T>::nodo n, int i, const ArbolELBIN<T>& arb)
{
    if(i == AlturaArbol(arb) - 1)
    {
        return (arb.Hizqui(n) != ArbolELBIN<T>::NODO_NULO && arb.Hdere(n) != ArbolELBIN<T>::NODO_NULO);
    }
    else
    {
        if(arb.Hizqui(n) == ArbolELBIN<T>::NODO_NULO && arb.Hdere(n) == ArbolELBIN<T>::NODO_NULO)
        {
            return true;
        }
        else
        {
            if(arb.Hizqui(n) != ArbolELBIN<T>::NODO_NULO && arb.Hdere(n) != ArbolELBIN<T>::NODO_NULO)
            {
                return ArbolPseudoCR(arb.Hizqui(n), i + 1, arb) && ArbolPseudoCR(arb.Hdere(n), i + 1, arb);
            }
            else
            {
                if(arb.Hizqui(n) != ArbolELBIN<T>::NODO_NULO)
                {
                    return ArbolPseudoCR(arb.Hizqui(n), i + 1, arb);
                }
                else
                {
                    return ArbolPseudoCR(arb.Hdere(n), i + 1, arb);
                }
            }
        }
    }
}



#endif // PSEUDOCOMPELTO
