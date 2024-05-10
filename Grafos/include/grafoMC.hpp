#ifndef GRAFOMC
#define GRAFOMC

#include <vector>
#include <limits>
#include "listaenla.h"
template <typename T> 
class GrafoMC 
{   // Grafo ponderado
    public:
        typedef T tCoste;
        typedef std::size_t vertice; // un valor entre 0 y GrafoP::numVert()-1
        typedef Lista<vertice> tCamino;

        struct arista 
        {
            vertice orig, dest;
            tCoste coste;
            
            explicit arista(vertice v=vertice(), vertice w=vertice(),
            tCoste c=tCoste()): orig(v), dest(w), coste(c) {}
            // Orden de aristas para Prim y Kruskall
            bool operator <(const arista& a) const { return coste < a.coste; }
        };

        static const tCoste INFINITO; // peso arista inexistente
        explicit GrafoMC(std::size_t n): costes(n, std::vector<GrafoMC::tCoste>(n,INFINITO)){}
        size_t numVert() const {return costes.size();}
        const std::vector<tCoste>& operator [](vertice v) const {return costes[v];}
        std::vector<tCoste>& operator [](vertice v) {return costes[v];}
        bool esDirigido() const;
    private:
        std::vector< std::vector<tCoste> > costes;
 };

template <typename T> 
const typename GrafoMC<T>::tCoste GrafoMC<T>::INFINITO = std::numeric_limits<T>::max();

#endif