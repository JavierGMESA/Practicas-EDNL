#ifndef ARBOLESVBIN
#define ARBOLESVBIN
#include <cassert>
#include <cstdlib>

template <typename T>
class ArbolVBIN
{
    struct celda;
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    ArbolVBIN(const size_t& m);
    bool vacio() const;
    void insertarRaiz(const T& e);
    void insertarHizqui(nodo n, const T& e);
    void insertarHdere(nodo n, const T& e);
    const T& element(nodo n) const;
    T& element(nodo n);
    void eliminarRaiz();
    void eliminarHizqui(nodo n);
    void eliminarHdere(nodo n);
    nodo Raiz() const;
    nodo Padre(nodo n) const;
    nodo Hizqui(nodo n) const;
    nodo Hdere(nodo n) const;
    ArbolVBIN(const ArbolVBIN& arb);
    ArbolVBIN& operator =(const ArbolVBIN& arb);
    ~ArbolVBIN();
private:
    struct celda
    {
        T elem;
        size_t padre, hizqui, hdere;
    };
    celda *arbol;
    size_t numNodos, maxNodos;
};

template <typename T>
const typename ArbolVBIN<T>::nodo ArbolVBIN<T>::NODO_NULO(SIZE_MAX);

template <typename T>
ArbolVBIN<T>::ArbolVBIN(const size_t& m)
{
    arbol = new celda[m];
    maxNodos = m;
    numNodos = 0;
}

template <typename T>
bool ArbolVBIN<T>::vacio() const
{
    return numNodos == 0;
}

template <typename T>
void ArbolVBIN<T>::insertarRaiz(const T& e)
{
    assert(numNodos == 0);
    arbol[0].elem = e;
    arbol[0].padre = NODO_NULO;
    arbol[0].hizqui = NODO_NULO;
    arbol[0].hdere = NODO_NULO;
    ++numNodos;
}

template <typename T>
void ArbolVBIN<T>::insertarHizqui(nodo n, const T& e)
{
    assert(n >= 0 && n <= numNodos - 1);
    assert(arbol[n].hizqui == NODO_NULO);
    assert(numNodos < maxNodos);

    arbol[n].hizqui = numNodos;
    arbol[numNodos].elem = e;
    arbol[numNodos].hizqui = NODO_NULO;
    arbol[numNodos].hdere = NODO_NULO;
    ++numNodos;
}

template <typename T>
void ArbolVBIN<T>::insertarHdere(nodo n, const T& e)
{
    assert(n >= 0 && n <= numNodos - 1);
    assert(arbol[n].hdere == NODO_NULO);
    assert(numNodos < maxNodos);

    arbol[n].hdere = numNodos;
    arbol[numNodos].elem = e;
    arbol[numNodos].hizqui = NODO_NULO;
    arbol[numNodos].hdere = NODO_NULO;
    ++numNodos;
}

template <typename T>
const T& ArbolVBIN<T>::element(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return arbol[n].elem;
}

template <typename T>
T& ArbolVBIN<T>::element(nodo n)
{
    assert(n >= 0 && n <= numNodos - 1);
    return arbol[n].elem;
}

template <typename T>
void ArbolVBIN<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    --numNodos;
}

template <typename T>
void ArbolVBIN<T>::eliminarHizqui(nodo n)
{
    assert(n >= 0 && n <= numNodos - 1); //Que pertenezca al arbol
    assert(arbol[n].hizqui != NODO_NULO); //Que exista hijo izquierdo
    assert(arbol[arbol[n].hizqui].hizqui == NODO_NULO && arbol[arbol[n].hizqui].hdere == NODO_NULO); //Que sea una hoja

    if(arbol[n].hizqui != numNodos - 1)
    {
        arbol[arbol[n].hizqui] = arbol[numNodos - 1]; //Copiamos el último en el hueco
        if(arbol[arbol[numNodos - 1].padre].hizqui == numNodos - 1) //Si el último nodo era hijo izquierdo, hacemos que el padre apunte al hueco
        {
            arbol[arbol[numNodos - 1].padre].hizqui = arbol[n].hizqui;
        }
        else
        {
            arbol[arbol[numNodos - 1].padre].hdere = arbol[n].hizqui;
        }
        if(arbol[numNodos - 1].hizqui != NODO_NULO) //Si el último tiene un hijo izquierdo, hay que actualizar la posición del padre
        {                                           //que este tiene
            arbol[arbol[arbol[n].hizqui].hizqui].padre = arbol[n].hizqui;
        }
        if(arbol[numNodos - 1].hdere != NODO_NULO)
        {
            arbol[arbol[arbol[n].hizqui].hdere].padre = arbol[n].hizqui;
        }
    }
    arbol[n].hizqui = NODO_NULO;
    --numNodos;
}

template <typename T>
void ArbolVBIN<T>::eliminarHdere(nodo n)
{
    assert(n >= 0 && n <= numNodos - 1); //Que pertenezca al arbol
    assert(arbol[n].hdere != NODO_NULO); //Que exista hijo izquierdo
    assert(arbol[arbol[n].hdere].hizqui == NODO_NULO && arbol[arbol[n].hdere].hdere == NODO_NULO); //Que sea una hoja

    if(arbol[n].hdere != numNodos - 1)
    {
        arbol[arbol[n].hdere] = arbol[numNodos - 1]; //Copiamos el último en el hueco
        if(arbol[arbol[numNodos - 1].padre].hizqui == numNodos - 1) //Si el último nodo era hijo izquierdo, hacemos que el padre apunte al hueco
        {
            arbol[arbol[numNodos - 1].padre].hizqui = arbol[n].hdere;
        }
        else
        {
            arbol[arbol[numNodos - 1].padre].hdere = arbol[n].hdere;
        }
        if(arbol[numNodos - 1].hizqui != NODO_NULO) //Si el último tiene un hijo izquierdo, hay que actualizar la posición del padre
        {                                           //que este tiene
            arbol[arbol[arbol[n].hizqui].hizqui].padre = arbol[n].hdere;
        }
        if(arbol[numNodos - 1].hdere != NODO_NULO)
        {
            arbol[arbol[arbol[n].hizqui].hdere].padre = arbol[n].hdere;
        }
    }
    arbol[n].hdere = NODO_NULO;
    --numNodos;
}

template <typename T>
typename ArbolVBIN<T>::nodo ArbolVBIN<T>::Raiz() const
{
    nodo res = 0;
    if(numNodos == 0)
    {
        res = NODO_NULO;
    }
    return res;
}

template <typename T>
typename ArbolVBIN<T>::nodo ArbolVBIN<T>::Padre(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return arbol[n].padre;
}

template <typename T>
typename ArbolVBIN<T>::nodo ArbolVBIN<T>::Hizqui(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return arbol[n].hizqui;
}

template <typename T>
typename ArbolVBIN<T>::nodo ArbolVBIN<T>::Hdere(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return arbol[n].hdere;
}

template <typename T>
ArbolVBIN<T>::ArbolVBIN(const ArbolVBIN<T>& arb)
{
    int i;
    arbol = new celda[arb.maxNodos];
    maxNodos = arb.maxNodos;
    numNodos = arb.numNodos;
    for(i = 0; i < numNodos; ++i)
    {
        arbol[i] = arb.arbol[i];
    }
}

template <typename T>
ArbolVBIN<T>& ArbolVBIN<T>::operator =(const ArbolVBIN<T>& arb)
{
    int i;
    if(this != &arb)
    {
        if(maxNodos != arb.maxNodos)
        {
            delete[] arbol;
            arbol = new celda[arb.maxNodos];
            maxNodos = arb.maxNodos;
        }
        numNodos = arb.numNodos;
        for(i = 0; i < numNodos; ++i)
        {
            arbol[i] = arb.arbol[i];
        }
    }
    return *this;
}

template <typename T>
ArbolVBIN<T>::~ArbolVBIN()
{
    delete[] arbol;
    numNodos = 0;
}

#endif // ARBOLESVBIN
