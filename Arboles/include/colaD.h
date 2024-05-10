#ifndef COLAD
#define COLAD

template <typename T>
class colaD
{
public:
    colaD();
    bool vacia() const;
    unsigned n_elementos() const;
    T& frente() const;
    void push(T);
    void pop();
    colaD(const colaD&);
    colaD& operator =(colaD&);
    ~colaD();
private:
    struct nodo
    {
        T elem;
        nodo *next;
    };
    nodo *inicio, *fin;
    unsigned n_elem;
    void copiar (colaD&);
};

template <typename T>
colaD<T>::colaD()
{
    inicio=nullptr;
    fin=nullptr;
    n_elem=0;
}

template <typename T>
bool colaD<T>::vacia() const
{
    return n_elem==0;
}

template <typename T>
unsigned colaD<T>::n_elementos() const
{
    return n_elem;
}

template <typename T>
T& colaD<T>::frente() const
{
    return inicio->elem;
}

template <typename T>
void colaD<T>::push(T a)
{
    if(vacia())
    {
        fin=new nodo;
        fin->elem=a;
        fin->next=nullptr;
        inicio=fin;
    }
    else
    {
        fin->next=new nodo;
        fin=fin->next;
        fin->elem=a;
    }
    ++n_elem;
}

template <typename T>
void colaD<T>::pop()
{
    if(!vacia())
    {
        nodo* p=inicio;
        inicio=p->next;
        delete p;
        --n_elem;
        if(n_elem==0)
        {
            fin=nullptr;
        }
    }
}

template <typename T>
colaD<T>::colaD(const colaD& C)
{
    inicio=nullptr;
    fin=nullptr;
    n_elem=0;
    copiar(C);
}

//constructor de copia
template <typename T>
colaD<T>& colaD<T>::operator =(colaD& C)
{
    if(this!=&C)
    {
        this->~colaD();
        inicio=nullptr;
        fin=nullptr;
        n_elem=0;
        copiar(C);
    }
    return *this;
}

template <typename T>
void colaD<T>::copiar(colaD& C)
{
    if(!C.vacia())
    {
        nodo *p, *q;
        p=C.inicio;
        q=new nodo;
        inicio=q;
        fin=q;
        q->elem=p->elem; //copiamos el elemento del frente
        p=p->next; //
        while(p!=nullptr)
        {
            q->next=new nodo;
            q=q->next;
            fin=q;
            q->elem=p->elem;
            q->next=nullptr;
            p=p->next;
        }
        n_elem=C.n_elem;
    }
}

template <typename T>
colaD<T>::~colaD()
{
    nodo *p;
    while(n_elem>1)
    {
        p=inicio->next;
        delete inicio;
        inicio=p;
        --n_elem;
    }
}


#endif // COLAD
