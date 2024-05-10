#include "particion.hpp"

//int Particion::encontrar(int x) const
//{
//    while (padre[x] != -1)
//    x = padre[x];
//    return x;
//}

void Particion::unir(int a, int b)
{
    if (padre[b] < padre[a])
        padre[a] = b;
    else 
    {
        if (padre[a] == padre[b])
            padre[a]--; // El árbol resultante tiene un nivel más.
        padre[b] = a;
    }
}

int Particion::encontrar(int x) const
{
    std::vector<int> p = padre;
    int y, raiz = x;
    while (p[raiz] > -1)
        raiz = p[raiz];
        // Compresión del camino de x a raíz: Los nodos
        // del camino se hacen hijos de la raíz.
    while (padre[x] > -1) 
    {
        y = p[x];
        p[x] = raiz;
        x = y;
    }
    return raiz;
}
