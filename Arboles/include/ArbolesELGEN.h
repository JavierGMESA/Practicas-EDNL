#ifndef ARBOLESELGEN
#define ARBOLESELGEN
#include <cassert>

template <typename T>
class ArbolELGEN
{
    struct celda;
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;

    ArbolELGEN();
    bool vacio() const;
    void insertarRaiz(const T& e);
    void insertarHizqui(nodo n, const T& e);
    void insertarHerdere(nodo n, const T& e);
    void eliminarRaiz();
    void eliminarHizqui(nodo n);
    void eliminarHerdere(nodo n);
    const T& element(nodo n) const;
    T& element(nodo n);
    nodo raiz() const;
    nodo Padre(nodo n) const;
    nodo Hizqui(nodo n) const;
    nodo Herdere(nodo n) const;

    ArbolELGEN(const ArbolELGEN& arb);
    ArbolELGEN& operator =(const ArbolELGEN& arb);
    ~ArbolELGEN();
private:
    struct celda
    {
        T elem;
        nodo padre, hermano, hizqui;
        celda(const T& e, nodo p = NODO_NULO): elem(e), padre(p), hermano(NODO_NULO), hizqui(NODO_NULO){}
    };
    nodo r;
    void destruirN(nodo& n);
    nodo copiar(nodo n);
};

template <typename T>
const typename ArbolELGEN<T>::nodo ArbolELGEN<T>::NODO_NULO(nullptr);

template <typename T>
ArbolELGEN<T>::ArbolELGEN()
{
    r = nullptr;
}

template <typename T>
bool ArbolELGEN<T>::vacio() const
{
    return r == NODO_NULO;
}

template <typename T>
void ArbolELGEN<T>::insertarRaiz(const T& e)
{
    assert(r == NODO_NULO);
    r = new celda(e);
}

template <typename T>
void ArbolELGEN<T>::insertarHizqui(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    nodo hizqui = n->hizqui;
    n->hizqui = new celda(e, n);
    n->hizqui->hermano = hizqui;
}

template <typename T>
void ArbolELGEN<T>::insertarHerdere(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n->padre != NODO_NULO);
    nodo herdere = n->hermano;
    n->hermano = new celda(e, n->padre);
    n->hermano->hermano = herdere;
}

template <typename T>
void ArbolELGEN<T>::eliminarRaiz()
{
    assert(r != NODO_NULO);
    assert(r->hizqui == NODO_NULO);
    delete r;
    r = NODO_NULO;
}

template <typename T>
void ArbolELGEN<T>::eliminarHizqui(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hizqui != NODO_NULO);
    assert(n->hizqui->hizqui == NODO_NULO);
    nodo hizqui = n->hizqui;
    n->hizqui = n->hizqui->hermano;
    delete hizqui;
}

template <typename T>
void ArbolELGEN<T>::eliminarHerdere(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hermano != NODO_NULO);
    assert(n->hermano->hizqui == NODO_NULO);
    nodo herdere = n->hermano;
    n->hermano = n->hermano->hermano;
    delete herdere;
}

template <typename T>
const T& ArbolELGEN<T>::element(nodo n) const
{
    assert(n != NODO_NULO);
    return n->elem;
}

template <typename T>
T& ArbolELGEN<T>::element(nodo n)
{
    assert(n != NODO_NULO);
    return n->elem;
}

template <typename T>
typename ArbolELGEN<T>::nodo ArbolELGEN<T>::raiz() const
{
    return r;
}

template <typename T>
typename ArbolELGEN<T>::nodo ArbolELGEN<T>::Padre(nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename T>
typename ArbolELGEN<T>::nodo ArbolELGEN<T>::Hizqui(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizqui;
}

template <typename T>
typename ArbolELGEN<T>::nodo ArbolELGEN<T>::Herdere(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hermano;
}

template <typename T>
ArbolELGEN<T>::ArbolELGEN(const ArbolELGEN<T>& arb)
{
    r = copiar(arb.r);
}

template <typename T>
ArbolELGEN<T>& ArbolELGEN<T>::operator=(const ArbolELGEN<T>& arb)
{
    if(this != &arb)
    {
        destruirN(r);
        r = copiar(arb.r);
    }
    return *this;
}

template <typename T>
ArbolELGEN<T>::~ArbolELGEN()
{
    destruirN(r);
}

template <typename T>
void ArbolELGEN<T>::destruirN(nodo& n)
{
    nodo herdere;
    if(n != NODO_NULO)
    {
        if(n->hizqui != NODO_NULO)
        {
            herdere = n->hizqui->hermano;
            while(herdere != NODO_NULO)
            {
                n->hizqui->hermano = herdere->hermano;
                destruirN(herdere);
                herdere = n->hizqui->hermano;
            }
            destruirN(n->hizqui);
        }
        delete n;
        n = NODO_NULO;
    }
}

template <typename T>
typename ArbolELGEN<T>::nodo ArbolELGEN<T>::copiar(nodo n)
{
    nodo m = NODO_NULO;
    if(n != NODO_NULO)
    {
        m = new celda(n->elem);
        if(n->hizqui != NODO_NULO)
        {
            m->hizqui = copiar(n->hizqui);
            m->hizqui->padre = m;

            nodo hijo = m->hizqui;
            nodo herdere = n->hizqui->hermano;
            while(herdere != NODO_NULO)
            {
                hijo->hermano = copiar(herdere);
                hijo = hijo->hermano;
                hijo->padre = m;
                herdere = herdere->hermano;
            }
        }
    }
    return m;
}


#endif // ARBOLESELGEN
