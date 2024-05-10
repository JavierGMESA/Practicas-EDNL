#ifndef ARBOLESVPSBIN
#define ARBOLESVPSBIN
#include <cassert>


template <typename T>
class ArbolVPSBIN
{
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    ArbolVPSBIN(const size_t& maximo, const T& E_NULO);
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

    ArbolVPSBIN(const ArbolVPSBIN<T>& arb);
    ArbolVPSBIN<T>& operator =(const ArbolVPSBIN<T>& arb);
    ~ArbolVPSBIN();
private:
    T* vect;
    size_t maxNodos;
    T NULO;
};

template <typename T>
const typename ArbolVPSBIN<T>::nodo ArbolVPSBIN<T>::NODO_NULO(SIZE_MAX);

template <typename T>
ArbolVPSBIN<T>::ArbolVPSBIN(const size_t& maximo, const T& E_NULO)
{
    int i;
    vect = new T[maximo];
    maxNodos = maximo;
    NULO = E_NULO;
    for(i = 0; i < maxNodos; ++i)
    {
        vect[i] = NULO;
    }
}

template <typename T>
bool ArbolVPSBIN<T>::vacio() const
{
    return vect[0] == NULO;
}

template <typename T>
void ArbolVPSBIN<T>::insertarRaiz(const T& e)
{
    assert(vect[0] == NULO);
    vect[0] = e;
}

template <typename T>
void ArbolVPSBIN<T>::insertarHizqui(nodo n, const T& e)
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    assert(2 * n + 1 < maxNodos);
    assert(vect[2 * n + 1] == NULO);
    vect[2 * n + 1] = e;
}

template <typename T>
void ArbolVPSBIN<T>::insertarHdere(nodo n, const T& e)
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    assert(2 * n + 2 < maxNodos);
    assert(vect[2 * n + 2] == NULO);
    vect[2 * n + 2] = e;
}

template <typename T>
const T& ArbolVPSBIN<T>::element(nodo n) const
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    return vect[n];
}

template <typename T>
T& ArbolVPSBIN<T>::element(nodo n)
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    return vect[n];
}

template <typename T>
void ArbolVPSBIN<T>::eliminarRaiz()
{
    assert(vect[0] != NULO);
    if(2 < maxNodos)
    {
        assert(vect[1] == NULO && vect[2] == NULO);
    }
    else
    {
        if(1 < maxNodos)
        {
            assert(vect[1] == NULO);
        }
    }
    vect[0] = NULO;
}

template <typename T>
void ArbolVPSBIN<T>::eliminarHizqui(nodo n)
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    assert(2 * n + 1 < maxNodos);
    assert(vect[2 * n + 1] != NULO);
    if(2 * (2 * n + 1) + 2 < maxNodos)
    {
        assert(vect[2 * (2 * n + 1) + 1] == NULO && vect[2 * (2 * n + 1) + 2] == NULO);
    }
    else
    {
        if(2 * (2 * n + 1) + 1 < maxNodos)
        {
            assert(vect[2 * (2 * n + 1) + 1] == NULO);
        }
    }
    vect[2 * n + 1] = NULO;
}

template <typename T>
void ArbolVPSBIN<T>::eliminarHdere(nodo n)
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    assert(2 * n + 2 < maxNodos);
    assert(vect[2 * n + 2] != NULO);
    if(2 * (2 * n + 2) + 2 < maxNodos)
    {
        assert(vect[2 * (2 * n + 2) + 1] == NULO && vect[2 * (2 * n + 2) + 2] == NULO);
    }
    else
    {
        if(2 * (2 * n + 2) + 1 < maxNodos)
        {
            assert(vect[2 * (2 * n + 2) + 1] == NULO);
        }
    }
    vect[2 * n + 2] = NULO;
}

template <typename T>
typename ArbolVPSBIN<T>::nodo ArbolVPSBIN<T>::Raiz() const
{
    if(vect[0] == NULO)
    {
        return NODO_NULO;
    }
    else
    {
        return 0;
    }
}

template <typename T>
typename ArbolVPSBIN<T>::nodo ArbolVPSBIN<T>::Padre(nodo n) const
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    if(n == 0)
    {
        return NODO_NULO;
    }
    else
    {
        return (n - 1) / 2;
    }
}

template <typename T>
typename ArbolVPSBIN<T>::nodo ArbolVPSBIN<T>::Hizqui(nodo n) const
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    if(2 * n + 1 < maxNodos && vect[2 * n + 1] != NULO)
    {
        return 2 * n + 1;
    }
    else
    {
        return NODO_NULO;
    }
}

template <typename T>
typename ArbolVPSBIN<T>::nodo ArbolVPSBIN<T>::Hdere(nodo n) const
{
    assert(n >= 0 && n <= maxNodos - 1);
    assert(vect[n] != NULO);
    if(2 * n + 2 < maxNodos && vect[2 * n + 2] != NULO)
    {
        return 2 * n + 2;
    }
    else
    {
        return NODO_NULO;
    }
}

template <typename T>
ArbolVPSBIN<T>::ArbolVPSBIN(const ArbolVPSBIN<T>& arb)
{
    int i;
    vect = new T[arb.maxNodos];
    maxNodos = arb.maxNodos;
    NULO = arb.NULO;
    for(i = 0; i < maxNodos; ++i)
    {
        vect[i] = arb.vect[i];
    }
}

template <typename T>
ArbolVPSBIN<T>& ArbolVPSBIN<T>::operator =(const ArbolVPSBIN<T>& arb)
{
    int i;
    if(this != &arb)
    {
        if(maxNodos != arb.maxNodos)
        {
            delete[] vect;
            vect = new T[arb.maxNodos];
            maxNodos = arb.maxNodos;
        }
        NULO = arb.NULO;
        for(i = 0; i < maxNodos; ++i)
        {
            vect[i] = arb.vect[i];
        }
    }
    return *this;
}

template <typename T>
ArbolVPSBIN<T>::~ArbolVPSBIN()
{
    delete[] vect;
}


#endif // ARBOLESVPSBIN
