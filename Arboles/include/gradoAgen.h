#ifndef GRADOAGEN
#define GRADOAGEN

template <typename T>
int gradoAgen(const ArbolELGEN<T>& arb)
{
    return gradoAgenR(arb.raiz(), arb);
}

template <typename T>
int gradoAgenR(typename ArbolELGEN<T>::nodo n, const ArbolELGEN<T>& arb)
{
    int g = 0;
    int hi = 0;
    typename ArbolELGEN<T>::nodo na;
    if(n != ArbolELGEN<T>::NODO_NULO)
    {
        na = arb.Hizqui(n);
        while(na != ArbolELGEN<T>::NODO_NULO)
        {
            ++hi;
            na = arb.Herdere(na);
        }
        if(hi > gradoAgenR(arb.Hizqui(n), arb) && hi > gradoAgenR(arb.Herdere(n), arb))
        {
            return hi;
        }
        else
        {
            if(gradoAgenR(arb.Hizqui(n), arb) > hi && gradoAgenR(arb.Hizqui(n), arb) > gradoAgenR(arb.Herdere(n), arb))
            {
                return gradoAgenR(arb.Hizqui(n), arb);
            }
            else
            {
                return gradoAgenR(arb.Herdere(n), arb);
            }
        }
    }
    else
    {
        return hi;
    }
}

#endif // GRADOAGEN
