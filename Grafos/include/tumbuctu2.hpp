#ifndef TUMBUCTU2
#define TUMBUCTU2

#include "alg_grafoPMC.hpp"
#include "particion.hpp"
#include "laberintoNxN.hpp"
#include "grafoMA.hpp"
#include "listaenla.h"

#include <vector>

struct Linea
{
    float c;
    std::size_t a, b;
    Linea(float coste = 0, std::size_t x = 0, std::size_t y = 0): c{coste}, a{x}, b{y} {}
};

typedef coordenada vect_alg;

vect_alg operator -(coordenada a, coordenada b);

float modulo(vect_alg c);

matriz<Linea> ArchiTumbuctu2(const std::vector<coordenada>& ciudades, const GrafoMA& g);

int BuscarIslas(Particion& P, const GrafoMA& g);

void Ciudades(std::vector<Lista<std::size_t>>& isl, const Particion& Islas, int n_islas, int n);

matriz<Linea> Lineas(const std::vector<Lista<std::size_t>>& isl, const std::vector<coordenada>& v, int n_islas);


#endif