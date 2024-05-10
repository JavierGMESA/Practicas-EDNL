#ifndef ARBOLESELBIN
#define ARBOLESELBIN
#include <cassert>

template <typename T>
class ArbolELBIN
{
    struct celda;
public:
    typedef celda* nodo;
    static const nodo NODO_NULO;

    ArbolELBIN();
    bool vacio() const;
    void insertarRaiz(const T& e);
    void insertarHizqui(nodo n, const T& e);
    void insertarHdere(nodo n, const T& e);
    const T& element(nodo n) const;
    T& element(nodo n);
    void eliminarRaiz();
    void eliminarHizqui(nodo n);
    void eliminarHdere(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo Hizqui(nodo n) const;
    nodo Hdere(nodo n) const;

    ArbolELBIN(const ArbolELBIN<T>& arb);
    ArbolELBIN<T>& operator =(const ArbolELBIN<T>& arb);
    ~ArbolELBIN();
private:
    struct celda
    {
        T elem;
        nodo padre, hizqui, hdere;
        celda(const T& e, nodo p = NODO_NULO): elem(e), padre(p), hizqui(NODO_NULO), hdere(NODO_NULO){}
    };
    nodo r;
    void destroyNodo(nodo n);
    nodo copiar(nodo n);
};

//DEFINIMOS EL PUNTERO NULO
template <typename T>
const typename ArbolELBIN<T>::nodo ArbolELBIN<T>::NODO_NULO(nullptr);

template <typename T>
ArbolELBIN<T>::ArbolELBIN()
{
    r = NODO_NULO;
}

template <typename T>
bool ArbolELBIN<T>::vacio() const
{
    return r == NODO_NULO;
}

template <typename T>
void ArbolELBIN<T>::insertarRaiz(const T& e)
{
    assert(r == NODO_NULO);
    r = new celda(e); //NO HACE FALTA PONER r->padre = NODO_NULO pues esto se pone por defecto
}

template <typename T>
void ArbolELBIN<T>::insertarHizqui(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n->hizqui == NODO_NULO);
    n->hizqui = new celda(e, n);
}

template <typename T>
void ArbolELBIN<T>::insertarHdere(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n->hdere == NODO_NULO);
    n->hdere = new celda(e, n);
}

template <typename T>
const T& ArbolELBIN<T>::element(nodo n) const
{
    assert(n != NODO_NULO);
    return n->elem;
}

template <typename T>
T& ArbolELBIN<T>::element(nodo n)
{
    assert(n != NODO_NULO);
    return n->elem;
}

template <typename T>
void ArbolELBIN<T>::eliminarRaiz()
{
    assert(r != NODO_NULO);
    assert(r->hizqui == NODO_NULO && r->hdere == NODO_NULO);
    delete r;
    r = NODO_NULO;
}

template <typename T>
void ArbolELBIN<T>::eliminarHizqui(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hizqui != NODO_NULO);
    assert(n->hizqui->hizqui == NODO_NULO && n->hizqui->hdere == NODO_NULO);
    delete n->hizqui;
    n->hizqui = NODO_NULO;
}

template <typename T>
void ArbolELBIN<T>::eliminarHdere(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hdere != NODO_NULO);
    assert(n->hdere->hizqui == NODO_NULO && n->hdere->hdere == NODO_NULO);
    delete n->hdere;
    n->hdere = NODO_NULO;
}

template <typename T>
typename ArbolELBIN<T>::nodo ArbolELBIN<T>::raiz() const
{
    return r;
}

template <typename T>
typename ArbolELBIN<T>::nodo ArbolELBIN<T>::padre(nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename T>
typename ArbolELBIN<T>::nodo ArbolELBIN<T>::Hizqui(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizqui;
}

template <typename T>
typename ArbolELBIN<T>::nodo ArbolELBIN<T>::Hdere(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hdere;
}

template <typename T>
ArbolELBIN<T>::ArbolELBIN(const ArbolELBIN<T>& arb)
{
    r = copiar(arb.r);
}

template <typename T>
ArbolELBIN<T>& ArbolELBIN<T>::operator =(const ArbolELBIN<T>& arb)
{
    if(this != &arb)
    {
        destroyNodo(r);
        r = copiar(arb.r);
    }
    return *this;
}

template <typename T>
ArbolELBIN<T>::~ArbolELBIN()
{
    destroyNodo(r);
}

template <typename T>
void ArbolELBIN<T>::destroyNodo(nodo n)
{
    if(n != NODO_NULO)
    {
        destroyNodo(n->hizqui);
        destroyNodo(n->hdere);
        delete n;
        n = NODO_NULO; //PUES AL FINAL DEBE QUEDAR EL NODO RAIZ COMO NULO
    }
}

template <typename T>
typename ArbolELBIN<T>::nodo ArbolELBIN<T>::copiar(nodo n)
{
    nodo m = NODO_NULO; //creamos un nodo auxiliar inicializado a NODO_NULO POR SI SE ALCANZA UNA HOJA
    if(n != NODO_NULO)
    {
        m = new celda(n->elem); //creamos nuevo nodo con el elemento de n
        m->hizqui = copiar(n->hizqui); //creamos un subárbol como hijo izquierdo de m
        if(m->hizqui != NODO_NULO) //SI ES NULO, NO SE HACE NADA PUES EL CONSTRUCTOR DE CELDA COLOCARÁ NODO_NULO
        {
            m->hizqui->padre = m; //enganchamos con m
        }
        m->hdere = copiar(n->hdere); //creamos un subárbol como hijo derecho de m
        if(m->hdere != NODO_NULO) //SI ES NULO, NO SE HACE NADA PUES EL CONSTRUCTOR DE CELDA COLOCARÁ NODO_NULO
        {
            m->hdere->padre = m; //enganchamos con m
        }
    }
    return m;
}


#endif // ARBOLESELBIN
