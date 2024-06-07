#include "tumbuctu2.hpp"
#include <math.h>

vect_alg operator -(coordenada a, coordenada b)
{
    vect_alg res = a;
    res.x -= b.x;
    res.y -= b.y;
    return res;
}

float modulo(vect_alg c)
{
    return sqrt(pow(c.x, 2) + pow(c.y, 2));
}

matriz<Linea> ArchiTumbuctu2(const std::vector<coordenada>& ciudades, const GrafoMA& g)
{
    const std::size_t n = g.numVert();
    Particion Islas(n);
    int n_islas = BuscarIslas(Islas, g);
    std::vector<Lista<std::size_t>> isl(n_islas);
    Ciudades(isl, Islas, n_islas, n);
    return Lineas(isl, ciudades, n_islas);
}

int BuscarIslas(Particion& P, const GrafoMA& g)
{
    int n_islas = g.numVert();
    const std::size_t n = n_islas;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(g[i][j] && P.encontrar(i) != P.encontrar(j))
            {
                P.unir(P.encontrar(i), P.encontrar(j));
                --n_islas;
            }
        }
    }
    return n_islas;
}

void Ciudades(std::vector<Lista<std::size_t>>& isl, const Particion& Islas, int n_islas, int n)
{
    std::vector<bool> v(n);
    int j, k = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!v[i])
        {
            j = 0;
            while(j < k && isl[j].elemento(isl[j].primera()) != Islas.encontrar(i))
            {
                ++j;
            }
            if(j == k)
            {
                isl[k].insertar(Islas.encontrar(i), isl[k].primera());
                v[Islas.encontrar(i)] = true;
                ++k;
                if(i != Islas.encontrar(i))
                {
                    isl[k].insertar(i, isl[k].fin());
                }
            }
            else
            {
                isl[j].insertar(i, isl[j].fin());
            }
            v[i] = true;
        }
    }
}

matriz<Linea> Lineas(const std::vector<Lista<std::size_t>>& isl, const std::vector<coordenada>& v, int n_islas)
{
    matriz<Linea> Res(n_islas);
    std::size_t ma, mb;
    float mini;
    Lista<std::size_t>::posicion p1, p2;

    for(int i = 0; i < n_islas; ++i)
    {
        Res[i][i] = Linea(0, isl[i].elemento(isl[i].primera()), isl[i].elemento(isl[i].primera()));
        for(int j = i + 1; j < n_islas; ++j)
        {
            mini = SIZE_MAX;
            for(p1 = isl[i].primera(); p1 != isl[i].fin(); p1 = isl[i].siguiente(p1))
            {
                for(p2 = isl[j].primera(); p2 != isl[j].fin(); p2 = isl[j].siguiente(p2))
                {
                    int mod = modulo(v[isl[i].elemento(p1)] - v[isl[j].elemento(p2)]);
                    if(mod < mini)
                    {
                        mini = mod;
                        ma = isl[i].elemento(p1);
                        mb = isl[j].elemento(p2);
                    }
                }
            }
            Res[i][j] = Res[j][i] = Linea(mini, ma, mb);
        }
    }

    return Res;
}