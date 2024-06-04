#ifndef LABERINTONXN
#define LABERINTONXN

#include "grafoMC.hpp"
#include "alg_grafoPMC.hpp"
#include <iostream>

struct coordenada
{
    int x, y;
    coordenada(int a = 0, int b = 0): x{a}, y{b} {}
};

std::ostream& operator <<(std::ostream& os, coordenada C);

struct pared
{
    coordenada a, b;
    pared(coordenada x = coordenada(), coordenada y = coordenada()): a{x}, b{y} {}
};

Lista<coordenada> laberintoNxN(size_t N, const Lista<pared>& lis, coordenada o, coordenada d, typename GrafoMC<int>::tCoste& coste);

typename GrafoMC<int>::vertice nodoC(const coordenada& c, size_t N);

coordenada casillaN(typename GrafoMC<int>::vertice C, size_t N);

#endif