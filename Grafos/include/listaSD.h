#ifndef LISTASD
#define LISTASD
#include <cassert>

template <typename T>
class listaSD
{
    struct nodo;
public:
    typedef nodo* posicion;
    listaSD();
    bool vacia() const;
    unsigned n_elementos() const;
    const T& elemento(posicion) const;
    T& elemento(posicion);
    void insertar(posicion, const T&);
    void eliminar(posicion);
    posicion primera() const;
    posicion fin() const;
    posicion siguiente(posicion) const;
    posicion anterior(posicion) const;
    listaSD(const listaSD&);
    listaSD& operator =(const listaSD&);
    ~listaSD();
private:
    struct nodo
    {
        T elem;
        nodo *sig;
    };
    unsigned n_elem;
    nodo *L;
    void copiar(const listaSD&);
};

template <typename T>
listaSD<T>::listaSD()
{
    L=new nodo;
    L->sig=L;
    n_elem=0;
}

template <typename T>
bool listaSD<T>::vacia() const
{
    return n_elem==0;
}

template <typename T>
unsigned listaSD<T>::n_elementos() const
{
    return n_elem;
}

template <typename T>
const T& listaSD<T>::elemento(posicion p) const
{
    return p->sig->elem;
}

template <typename T>
T& listaSD<T>::elemento(posicion p)
{
    return p->sig->elem;
}

template <typename T>
void listaSD<T>::insertar(posicion p, const T& a)
{
    posicion q=p->sig;
    p->sig=new nodo;
    p->sig->elem=a;
    p->sig->sig=q;
    ++n_elem;
    if(p==fin())
    {
        L=p->sig;
    }
}

template <typename T>
void listaSD<T>::eliminar(posicion p)
{
    assert(!vacia());
    posicion q=p->sig->sig;
    if(p->sig==L)
    {
        L=p;
    }
    delete p->sig;
    p->sig=q;
    --n_elem;
}

template <typename T>
typename listaSD<T>::posicion listaSD<T>::primera() const
{
    return L->sig;
}

template <typename T>
typename listaSD<T>::posicion listaSD<T>::fin() const
{
    return L;
}

template <typename T>
typename listaSD<T>::posicion listaSD<T>::siguiente(posicion p) const
{
    assert(p!=fin());
    return p->sig;
}

template <typename T>
typename listaSD<T>::posicion listaSD<T>::anterior(posicion p) const
{
    assert(p!=primera());
    nodo *q=primera();
    while(q->sig!=p)
    {
        q=q->sig;
    }
    return q;
}

template <typename T>
listaSD<T>::listaSD(const listaSD<T>& lis) : listaSD()
{
    copiar(lis);
}

template <typename T>
listaSD<T>& listaSD<T>::operator =(const listaSD<T>& lis)
{
    if(this!=&lis)
    {
        while(!vacia())
        {
            eliminar(primera());
        }
        copiar(lis);
    }
    return *this;
}

template <typename T>
listaSD<T>::~listaSD()
{
    posicion p=L->sig;
    while(L!=L->sig)
    {
        p=p->sig;
        delete L->sig;
        L->sig=p;
    }
    delete L;
}

template <typename T>
void listaSD<T>::copiar(const listaSD<T>& lis)
{
    posicion p=lis.L->sig;
    posicion q=L->sig;
    while(n_elem<lis.n_elem)
    {
        L->sig=new nodo;
        L->sig->elem=p->sig->elem;
        L->sig->sig=q;
        q=q->sig;
        p=p->sig;
        L=L->sig;
        ++n_elem;
    }
}

#endif // LISTASD
