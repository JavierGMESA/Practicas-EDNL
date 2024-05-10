#ifndef GRAFOMA
#define GRAFOMA

#include <vector>
//#include <csttdef>
class GrafoMA 
{
    public:
        typedef std::size_t vertice; // un valor entre 0 y Grafo::numVert()-1
        explicit GrafoMA(std::size_t n): ady(n, std::vector<bool>(n, false)) {}
        std::size_t numVert() const {return ady.size();}
        const std::vector<bool>& operator [](vertice v) const {return ady[v];}
        std::vector<bool>& operator [](vertice v) {return ady[v];}
    private:
        std::vector<std::vector<bool>> ady;
};

#endif