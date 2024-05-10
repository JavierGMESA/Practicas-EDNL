#ifndef DESEQUILIBRIOGEN
#define DESEQUILIBRIOGEN
#include <iostream>
#include "ArbolesELGEN.h"
#include "colaD.h"

template <typename T>
struct elem
{
    typename ArbolELGEN<T>::nodo no;
    int prof;
};

//template <typename T>
//int DesequilibrioGen(const ArbolELGEN<T>& arb)
//{
//    return DesequilibrioGenR(arb.raiz(), arb);
//}
//
//template <typename T>
//int DesequilibrioGenR(typename ArbolELGEN<T>::nodo n, const ArbolELGEN<T>& arb)
//{
//    int mini, maxi;
//    int des = 0;
//    typename ArbolELGEN<T>::nodo na;
//    if(n == ArbolELGEN<T>::NODO_NULO)
//    {
//        return 0;
//    }
//    else
//    {
//        if(arb.Hizqui(n) == ArbolELGEN<T>::NODO_NULO)
//        {
//            return 0;
//        }
//        else
//        {
//            maxi = mini = altura(arb.Hizqui(n), arb);
//            des = DesequilibrioGenR(arb.Hizqui(n), arb);
//            na = arb.Herdere(arb.Hizqui(n));
//            while(na != ArbolELGEN<T>::NODO_NULO)
//            {
//                if(altura(na, arb) > maxi)
//                {
//                    maxi = altura(na, arb);
//                }
//                if(altura(na, arb) < mini)
//                {
//                    mini = altura(na, arb);
//                }
//                if(DesequilibrioGenR(na, arb) > des)
//                {
//                    des = DesequilibrioGenR(na, arb);
//                }
//                na = arb.Herdere(na);
//            }
//            if(maxi - mini > des)
//            {
//                return maxi - mini;
//            }
//            else
//            {
//                return des;
//            }
//        }
//    }
//}

template <typename T>
int DesequilibrioGen(const ArbolELGEN<T>& arb)
{
    elem<T> e;
    e.no = arb.raiz();
    e.prof = 0;
    int p = 0;
    int mini = 0;
    int maxi = 0;
    int dese = 0;
    colaD<elem<T>> C;
    typename ArbolELGEN<T>::nodo aux = arb.Hizqui(arb.raiz());
    e.prof = 1;
    while(aux != ArbolELGEN<T>::NODO_NULO)
    {
        e.no = aux;
        C.push(e);
        aux = arb.Herdere(aux);
    }
    while(!C.vacia())
    {
        e = C.frente();
        C.pop();
        if(e.no != ArbolELGEN<T>::NODO_NULO)
        {
            if(e.prof > p)
            {
                if(maxi - mini > dese)
                {
                    dese = maxi - mini;
                }
                maxi = mini = altura(e.no, arb);
                p = e.prof;
            }
            if(altura(e.no, arb) < mini)
            {
                mini = altura(e.no, arb);
            }
            if(altura(e.no, arb) > maxi)
            {
                maxi = altura(e.no, arb);
            }
            aux = arb.Hizqui(e.no);
            while(aux != ArbolELGEN<T>::NODO_NULO)
            {
                e.no = aux;
                e.prof = p + 1;
                C.push(e);
                aux = arb.Herdere(aux);
            }
        }
    }
    return dese;
}

template <typename T>
int altura(typename ArbolELGEN<T>::nodo n, const ArbolELGEN<T>& arb)
{
    int a = -1;
    typename ArbolELGEN<T>::nodo na;
    if(n != ArbolELGEN<T>::NODO_NULO)
    {
        na = arb.Hizqui(n);
        while(na != ArbolELGEN<T>::NODO_NULO)
        {
            if(altura(na, arb) >= a)
            {
                a = altura(na, arb);
            }
            na = arb.Herdere(na);
        }
        ++a;
    }
    return a;
}

#endif // DESEQUILIBRIOGEN
