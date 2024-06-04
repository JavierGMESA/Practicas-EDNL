#include "laberintoNxN.hpp"
#include "grafoMC.hpp"
#include "alg_grafoPMC.hpp"
#include <iostream>

std::ostream& operator <<(std::ostream& os, coordenada C)
{
    os << C.x << " " << C.y;
    return os;
}

typename GrafoMC<int>::vertice nodoC(const coordenada& c, size_t N)
{
    return c.x * N + c.y;
}

coordenada casillaN(typename GrafoMC<int>::vertice C, size_t N)
{
    return coordenada(C / N, C % N);
}

Lista<coordenada> laberintoNxN(size_t N, const Lista<pared>& lis, coordenada o, coordenada d, typename GrafoMC<int>::tCoste& coste)
{
    GrafoMC<int> lab(N*N);
    std::vector<GrafoMC<int>::vertice> P(N*N);

    //RELLENAMOS EL LABERINTO
    size_t i, j;
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(j != 0)
            {
                lab[nodoC(coordenada(i, j), N)][nodoC(coordenada(i, j - 1), N)] = 1;
            }
            if(i != 0)
            {
                lab[nodoC(coordenada(i, j), N)][nodoC(coordenada(i - 1, j), N)] = 1;
            }
            if(i < N - 1)
            {
                lab[nodoC(coordenada(i, j), N)][nodoC(coordenada(i + 1, j), N)] = 1;
            }
            if(j < N - 1)
            {
                lab[nodoC(coordenada(i, j), N)][nodoC(coordenada(i, j + 1), N)] = 1;
            }
        }
    }

    //COLOCAMOS LAS PAREDES
    Lista<pared>::posicion p;
    int a1, b1, a2, b2;
    for(p = lis.primera(); p != lis.fin(); p = lis.siguiente(p))
    {
        a1 = lis.elemento(p).a.x;
        b1 = lis.elemento(p).a.y;
        a2 = lis.elemento(p).b.x;
        b2 = lis.elemento(p).b.y;
        lab[nodoC(coordenada(a1, b1), N)][nodoC(coordenada(a2, b2), N)] = lab[nodoC(coordenada(a2, b2), N)][nodoC(coordenada(a1, b1), N)] = GrafoMC<int>::INFINITO;
    }

    //OBTENEMOS EL CAMINO
    std::vector<GrafoMC<int>::tCoste> D = Dijkstra(lab, nodoC(o, N), P);
    Lista<coordenada> res;
    GrafoMC<int>::tCamino l = camino<int>(nodoC(o, N), nodoC(d, N), P);
    GrafoMC<int>::tCamino::posicion cam;
    for(cam = l.primera(); cam != l.fin(); cam = l.siguiente(cam))
    {
        res.insertar(casillaN(l.elemento(cam), N), res.fin());
    }
    coste = D[nodoC(d, N)];
    return res;
}