#ifndef DESEQUILIBRIO
#define DESEQUILIBRIO
#include "AlturaArbol.h"

template <typename T>
int ArbolDesequilibrado(const ArbolELBIN<T>& arb)
{
    return ArbolDesequilibradoR(arb.raiz(), arb);
}

template <typename T>
int ArbolDesequilibradoR(typename ArbolELBIN<T>::nodo n, const ArbolELBIN<T>& arb)
{
    int res;
    if(n == ArbolELBIN<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        res = AlturaArbolR(arb, arb.Hizqui(n)) - AlturaArbolR(arb, arb.Hdere(n));
        if(res < 0)
        {
            res = -res;
        }
        if(ArbolDesequilibradoR(arb.Hizqui(n), arb) > res || ArbolDesequilibradoR(arb.Hdere(n), arb) > res)
        {
            if(ArbolDesequilibradoR(arb.Hizqui(n), arb) > ArbolDesequilibradoR(arb.Hdere(n), arb))
            {
                return ArbolDesequilibradoR(arb.Hizqui(n), arb);
            }
            else
            {
                return ArbolDesequilibradoR(arb.Hdere(n), arb);
            }
        }
        else
        {
            return res;
        }
    }
}


#endif // DESEQUILIBRIO
