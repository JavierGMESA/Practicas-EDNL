#include <iostream>
#include "grafoMA.hpp"
#include "grafoMC.hpp"
#include "grafoL.hpp"
#include "listaSD.h"
#include "listaenla.h"
#include "alg_grafoPMC.hpp"

#include "diamPseudoC.hpp"

#include <vector>


void pruebaGrafo();
void pruebaDijkstra();
void pruebaDPC();


int main()
{
    //pruebaGrafo();
    //pruebaDijkstra();
    pruebaDPC();
    
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