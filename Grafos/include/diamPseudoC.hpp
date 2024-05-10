#ifndef DIAMPSEUDOC
#define DIAMPSEUDOC

#include "grafoMC.hpp"
#include "alg_grafoPMC.hpp"
#include <cassert>
#include <vector>

template <typename tCoste>
tCoste diamPseudoC(const GrafoMC<tCoste>& G)
{
    assert(G.numVert() > 2);
    std::vector<tCoste> D(G.numVert());
    std::vector<typename GrafoMC<tCoste>::vertice> P(G.numVert());
    tCoste max1, max2, diametro = GrafoMC<tCoste>::INFINITO;
    for(typename GrafoMC<tCoste>::vertice i = 0; i < G.numVert(); ++i)
    {
        D = Dijkstra(G, i, P);
        if(D[0] > D[1])
        {
            max1 = D[0];
            max2 = D[1];
        }
        else
        {
            max1 = D[1];
            max2 = D[0];
        }
        for(typename GrafoMC<tCoste>::vertice j = 2; j < G.numVert(); ++j)
        {
            if(D[j] > max1)
            {
                max2 = max1;
                max1 = D[j];
            }
            else if(D[j] > max2)
            {
                max2 = D[j];
            }
        }
        if(max1 + max2 < diametro)
        {
            diametro = max1 + max2;
        }
    }
    return diametro;
}

#endif