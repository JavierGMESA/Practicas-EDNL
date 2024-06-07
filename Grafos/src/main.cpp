#include <iostream>
#include "grafoMA.hpp"
#include "grafoMC.hpp"
#include "grafoL.hpp"
#include "listaSD.h"
#include "listaenla.h"
#include "alg_grafoPMC.hpp"

#include "diamPseudoC.hpp"
#include "laberintoNxN.hpp"
#include "tumbuctu2.hpp"

#include <vector>


void pruebaGrafo();
void pruebaDijkstra();
void pruebaDPC();
void pruebaLaberintoNxN();
void PruebaAT2();


int main()
{
    //pruebaGrafo();
    //pruebaDijkstra();
    //pruebaDPC();
    //pruebaLaberintoNxN();
    PruebaAT2();
    std::cout << std::endl << std::endl << "System Pause" << std::endl;
}

void pruebaGrafo()
{
    GrafoMA g{3};
    std::cout << "Termina de crear" << std::endl;
    g[0][1] = true;
    std::cout << "termina de asignar: " << g[0][2] << std::endl;

    GrafoMC<int> p{3};
    std::cout << "Termina de crear" << std::endl;
    p[0][1] = 200;
    std::cout << "termina de asignar: " << p[0][1] << ' ' << p[0][2] << std::endl;

    GrafoL l{3};
    listaSD<GrafoL::vertice> lis;
    lis = l.adyacentes(1);
    lis.insertar(lis.primera(), 0);
    std::cout << "Termina de asignar" << std::endl; 

    GrafoLP<int> k{3};
    listaSD<GrafoLP<int>::vertice_coste> lis2;
    lis2 = k.adyacentes(1);
    GrafoLP<int>::vertice_coste i;
    i.v = 4;
    i.c = 5;
    lis2.insertar(lis2.primera(), i);
    std::cout << "Termina de asignar" << std::endl;
}

void pruebaDijkstra()
{
    GrafoMC<int> g{5};
    g[0][1] = 10;
    g[0][3] = 30;
    g[0][4] = 100;
    g[1][2] = 50;
    g[2][4] = 10;
    g[3][2] = 20;
    g[3][4] = 60;
    std::vector<size_t> P{5};
    std::vector<int> D = Dijkstra(g, 0, P);
    for(int i = 0; i < 5; ++i)
    {
        std::cout << D[i] << ' ';
    }
    std::cout << std::endl;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << P[i] << ' ';
    }
}

void pruebaDPC()
{
    GrafoMC<int> g{4};
    for(int i = 0; i < 4; ++i)
    {
        g[i][i] = 0;
    }
    g[0][1] = g[1][0] = 100;
    g[1][3] = g[3][1] = 150;
    g[3][2] = g[2][3] = 200;
    g[2][0] = g[0][2] = 50;
    std::cout << diamPseudoC(g) << std::endl;
}

void pruebaLaberintoNxN()
{
    std::cout << "Empieza" << std::endl;
    Lista<pared> paredes;
    pared pa;
    pa.a = coordenada(4, 0);
    pa.b = coordenada(3, 0);
    paredes.insertar(pa, paredes.fin());
    pa.a = coordenada(0, 2);
    pa.b = coordenada(0, 3);
    paredes.insertar(pa, paredes.fin());
    pa.a = coordenada(2, 3);
    pa.b = coordenada(3, 3);
    paredes.insertar(pa, paredes.fin());
    int coste;
    Lista<coordenada> res = laberintoNxN(5, paredes, coordenada(0, 0), coordenada(4, 4), coste);
    Lista<coordenada>::posicion p;
    for(p = res.primera(); p != res.fin(); p = res.siguiente(p))
    {
        std::cout << res.elemento(p) << ", ";
    }
    std::cout << std::endl << "El coste ha sido " << coste << std::endl;
}

void PruebaAT2()
{
    GrafoMA g(7);
    std::vector<coordenada> v(7);
    g[0][1] = g[0][2] = g[2][3] = g[4][5] = true;
    v[0] = coordenada(0, 0);
    v[1] = coordenada(0, 1);
    v[2] = coordenada(1, 0);
    v[3] = coordenada(1, 1);
    v[4] = coordenada(0, 2);
    v[5] = coordenada(1, 2);
    v[6] = coordenada(2, 1);
    matriz<Linea> m = ArchiTumbuctu2(v, g);
    for(int i = 0; i < m.dimension(); ++i)
    {
        for(int j = 0; j < m.dimension(); ++j)
        {
            std::cout << "De la isla " << i << " a la isla " << j << " la linea es:" << std::endl;
            std::cout << "De la ciudad " << m[i][j].a << " a la ciudad " << m[i][j].b;
            std::cout << " con coste " << m[i][j].c << std::endl << std::endl;
        }
    }
}