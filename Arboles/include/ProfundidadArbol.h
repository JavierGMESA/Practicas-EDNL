#ifndef PROFUNDIDADARBOL
#define PROFUNDIDADARBOL
#include <cassert>
#include "ArbolesELBIN.h"

template <typename T>
int ProfundidadArbol(const ArbolELBIN<T>& arb, typename ArbolELBIN<T>::nodo n)
{
    assert(n != ArbolELBIN<T>::NODO_NULO);
    int res = 0;
    while(arb.padre(n) != ArbolELBIN<T>::NODO_NULO)
    {
        ++res;
        n = arb.padre(n);
    }
    return res;
}


#endif // PROFUNDIDADARBOL
