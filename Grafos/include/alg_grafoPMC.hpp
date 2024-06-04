#ifndef DIJKSTRA
#define DIJKSTRA

#include "grafoMC.hpp"
#include "grafoMA.hpp"
#include "grafoL.hpp"
#include "listaSD.h"
#include "listaenla.h"
#include "particion.hpp"
#include "apo.h"
#include <vector>

// Suma de costes
template <typename tCoste>
tCoste suma(tCoste x, tCoste y)
{
    const tCoste INFINITO = GrafoMC<tCoste>::INFINITO;
    if (x == INFINITO || y == INFINITO)
        return INFINITO;
    else
        return x + y;
}

template <typename tCoste>
std::vector<tCoste> Dijkstra(const GrafoMC<tCoste>& G, typename GrafoMC<tCoste>::vertice origen, std::vector<typename GrafoMC<tCoste>::vertice>& P)
{
    typedef typename GrafoMC<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert();
    std::vector<bool> S(n, false); // Conjunto de vértices vacío (VECTOR S)
    std::vector<tCoste> D; // Costes mínimos desde origen.
    // Iniciar D y P con caminos directos desde el vértice origen.
    D = G[origen]; //Le asignamos la fila del origen
    D[origen] = 0; // Coste origen-origen es 0.
    P = std::vector<typename GrafoMC<tCoste>::vertice>(n, origen);
    // Calcular caminos de coste mínimo hasta cada vértice.
    S[origen] = true; // Incluir vértice origen en S.
    for (size_t i = 1; i <= n-2; i++)
    {
        // Localizar vértice w no incluido en S con menor coste desde origen
        tCoste costeMin = GrafoMC<tCoste>::INFINITO;
        for (v = 0; v <= n-1; v++)
            if (!S[v] && D[v] <= costeMin)
            {
                costeMin = D[v]; //buscamos el mínimo
                w = v;
            }
        S[w] = true; // Incluir vértice w en S.
        // Recalcular coste hasta cada v no incluido en S, a través de w.
        for (v = 0; v <= n-1; v++)
            if (!S[v]) //Comprobamos solo los que están a false
            {
                tCoste Owv = suma(D[w], G[w][v]);
                if (Owv < D[v])
                {
                    D[v] = Owv;
                    P[v] = w;
                }
            }
    }
    return D;
}

template <typename tCoste>
std::vector<tCoste> DijkstraInv(const GrafoMC<tCoste>& G, typename GrafoMC<tCoste>::vertice destino, std::vector<typename GrafoMC<tCoste>::vertice>& P)
{
    typedef typename GrafoMC<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert();
    std::vector<bool> S(n, false); // Conjunto de vértices vacío (VECTOR S)
    std::vector<tCoste> D; // Costes mínimos desde origen.
    // Iniciar D y P con caminos directos desde el vértice origen.
    for(int i = 0; i < n; ++i)
    {
        D[i] = G[i][destino];
    }
    D[destino] = 0; // Coste origen-origen es 0.
    P = std::vector<typename GrafoMC<tCoste>::vertice>(n, destino);
    // Calcular caminos de coste mínimo hasta cada vértice.
    S[destino] = true; // Incluir vértice origen en S.
    for (size_t i = 1; i <= n-2; i++)
    {
        // Localizar vértice w no incluido en S con menor coste desde origen
        tCoste costeMin = GrafoMC<tCoste>::INFINITO;
        for (v = 0; v <= n-1; v++)
            if (!S[v] && D[v] <= costeMin)
            {
                costeMin = D[v]; //buscamos el mínimo
                w = v;
            }
        S[w] = true; // Incluir vértice w en S.
        // Recalcular coste hasta cada v no incluido en S, a través de w.
        for (v = 0; v <= n-1; v++)
            if (!S[v]) //Comprobamos solo los que están a false
            {
                tCoste vwD = suma(D[w], G[v][w]);
                if (vwD < D[v])
                {
                    D[v] = vwD;
                    P[v] = w;
                }
            }
    }
    return D;
}

template <typename tCoste> 
typename GrafoMC<tCoste>::tCamino camino(typename GrafoMC<tCoste>::vertice orig, typename GrafoMC<tCoste>::vertice v, const std::vector<typename GrafoMC<tCoste>::vertice>& P)
// Devuelve el camino de orig a v a partir de un vector
// P obtenido mediante la función Dijkstra().
{
    typename GrafoMC<tCoste>::tCamino C;
    C.insertar(v, C.primera());
    do {
        C.insertar(P[v], C.primera());
        v = P[v];
    } while (v != orig);
    return C;
}

template <typename tCoste> 
typename GrafoMC<tCoste>::tCamino caminoInv(typename GrafoMC<tCoste>::vertice destino, typename GrafoMC<tCoste>::vertice v, const std::vector<typename GrafoMC<tCoste>::vertice>& P)
// Devuelve el camino de orig a v a partir de un vector
// P obtenido mediante la función Dijkstra().
{
    typename GrafoMC<tCoste>::tCamino C;
    C.insertar(v, C.fin());
    do {
        C.insertar(P[v], C.fin());
        v = P[v];
    } while (v != destino);
    return C;
}

template <typename T> 
class matriz 
{
public:
    matriz() {}
    explicit matriz(size_t n, const T& x = T()): m(n, std::vector<T>(n, x)) {}
    std::size_t dimension() const { return m.size(); }
    const std::vector<T>& operator [](std::size_t i) const { return m[i]; }
    std::vector<T>& operator [](std::size_t i) { return m[i]; }
private:
    std::vector<std::vector<T> > m;
};

template <typename tCoste>
matriz<tCoste> Floyd(const GrafoMC<tCoste>& G, matriz<typename GrafoMC<tCoste>::vertice>& P)
{
    typedef typename GrafoMC<tCoste>::vertice vertice;
    const std::size_t n = G.numVert();
    matriz<tCoste> A(n); // matriz de costes mínimos
    // Iniciar A y P con caminos directos entre cada par de vértices.
    P = matriz<vertice>(n);
    for (vertice i = 0; i <= n-1; i++) 
    {
        A[i] = G[i]; // copia costes del grafo
        A[i][i] = 0; // diagonal a 0
        P[i] = std::vector<vertice>(n, i); // caminos directos
    }
    // Calcular costes mínimos y caminos correspondientes
    // entre cualquier par de vértices i, j
    for (vertice k = 0; k <= n-1; k++)
    for (vertice i = 0; i <= n-1; i++)
    for (vertice j = 0; j <= n-1; j++) 
    {
        tCoste ikj = suma(A[i][k], A[k][j]);
        if (ikj < A[i][j]) 
        {
            A[i][j] = ikj;
            P[i][j] = k;
        }
    }
    return A;
}

template <typename tCoste> 
typename GrafoMC<tCoste>::tCamino caminoAux(typename GrafoMC<tCoste>::vertice v, typename GrafoMC<tCoste>::vertice w, const matriz<typename GrafoMC<tCoste>::vertice>& P)
{ // Devuelve el camino de coste mínimo entre v y w, exluidos estos,
// a partir de una matriz P obtenida mediante la función Floyd().
    typename GrafoMC<tCoste>::tCamino C1, C2;
    typename GrafoMC<tCoste>::vertice u;
    u = P[v][w];
    if (u != v) 
    {
        C1 = caminoAux<tCoste>(v, u, P);
        C1.insertar(u, C1.fin());
        C2 = caminoAux<tCoste>(u, w, P);
        C1 += C2; // Lista<vertice>::operator +=(), concatena C1 y C2
    }
    return C1;
}

//matriz<bool> Warshall(GrafoMA G)
//{
//    typedef GrafoMA::vertice vertice;
//    const size_t n = G.numVert();
//    matriz<bool> A(n);
//    // Inicializar A con la matriz de adyacencia de G
//    for (vertice i = 0; i <= n-1; i++) 
//    {
//        A[i] = G[i];
//        A[i][i] = true;
//    }
//    // Comprobar camino entre cada par de vértices i, j
//    // a través de cada vértice k
//    for (vertice k = 0; k <= n-1; k++)
//    for (vertice i = 0; i <= n-1; i++)
//    for (vertice j = 0; j <= n-1; j++)
//    if (!A[i][j]) A[i][j] = A[i][k] && A[k][j];
//    return A;
//}

template <typename tCoste>
GrafoMC<tCoste> Kruskall(const GrafoMC<tCoste>& G)
// Devuelve un árbol generador de coste mínimo
// de un grafo no dirigido ponderado y conexo G.
{
    typedef typename GrafoMC<tCoste>::vertice vertice;
    typedef typename GrafoMC<tCoste>::arista arista;
    const tCoste INFINITO = GrafoMC<tCoste>::INFINITO;
    const size_t n = G.numVert();
    GrafoMC<tCoste> g(n); // Árbol generador de coste mínimo.
    Particion P(n); // Partición inicial de los vértices de G.
    Apo<arista> A(n*(n-1)/2);// Aristas de G ordenadas por coste.

    // Copiar aristas del grafo G en el APO A.
    for (vertice u = 0; u <= n-2; u++)
        for (vertice v = u+1; v <= n-1; v++)
            if (G[u][v] != INFINITO)
                A.insertar(arista(u, v, G[u][v]));
    size_t i = 1;
    
    while (i <= n-1) 
    { // Seleccionar n-1 aristas.
        arista a = A.cima(); // arista de menor coste
        A.suprimir();
        vertice u = P.encontrar(a.orig);
        vertice v = P.encontrar(a.dest);
        if (u != v) 
        {
            // extremos de a pertenecen a distintos componentes
            P.unir(u, v);
            // Incluir la arista a en el árbol g.
            g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
            i++;
        }
    }
    return g;
}

#endif