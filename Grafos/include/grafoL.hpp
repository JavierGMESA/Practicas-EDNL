#ifndef GRAFOL
#define GRAFOL


#include <vector>
#include "listaSD.h"

class GrafoL
{
    public:
        typedef std::size_t vertice; // un valor entre 0 y Grafo::numVert()-1
        explicit GrafoL(std::size_t n): ady(n) {}
        std::size_t numVert() const {return ady.size();}
        const listaSD<vertice>& adyacentes(vertice v) const {return ady[v];}
        listaSD<vertice>& adyacentes(vertice v) {return ady[v];}
    private:
        std::vector<listaSD<vertice>> ady; // vector de listas de vértices
 };

template <typename T> 
class GrafoLP 
{   // Grafo ponderado
    public:
        typedef T tCoste;
        typedef std::size_t vertice; // un valor entre 0 y GrafoP::numVert()-1
        typedef listaSD<vertice> tCamino;
        struct vertice_coste
        {  // vértice adyacente y coste
            vertice v;
            tCoste c;
            // requerido por Lista<vertice_coste>::buscar()
            bool operator ==(const vertice_coste& vc) const {return v == vc.v;}
        };
        static const tCoste INFINITO;   // peso de arista inexistente
        GrafoLP(size_t n): ady(n) {}
        size_t numVert() const {return ady.size();}
        const listaSD<vertice_coste>& adyacentes(vertice v) const {return ady[v];}
        listaSD<vertice_coste>& adyacentes(vertice v) {return ady[v];}
    private:
        std::vector<listaSD<vertice_coste> > ady; // vector de listas de vértice-coste
 };


#endif