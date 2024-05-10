#ifndef ARBOLESELBIBUS
#define ARBOLESELBIBUS
#include <cassert>

template <typename T>
class ArbolELBIBUS
{
public:
    ArbolELBIBUS();
    bool vacio() const;
    const ArbolELBIBUS& buscar(const T& e) const;
    void insertar(const T& e);
    void eliminar(const T& e);
    const T& element() const;
    const ArbolELBIBUS& izqu() const;
    const ArbolELBIBUS& dere() const;

    ArbolELBIBUS(const ArbolELBIBUS<T>& arb);
    ArbolELBIBUS& operator=(const ArbolELBIBUS<T>& arb);
    ~ArbolELBIBUS();
private:
    struct celda
    {
        T elem;
        ArbolELBIBUS izq, der;
        celda(const T& e): elem{e}, izq{}, der{} {}
    };
    celda *r;
    T borraMin();
};

template <typename T>
ArbolELBIBUS<T>::ArbolELBIBUS(): r{nullptr} {}

template <typename T>
bool ArbolELBIBUS<T>::vacio() const
{
    return r == nullptr;
}

template <typename T>
const ArbolELBIBUS<T>& ArbolELBIBUS<T>::buscar(const T& e) const
{
    if(r == nullptr) //if(r == nullptr || r->elem == e)
    {
        return *this;
    }
    else
    {
        if(r->elem < e)
        {
            return r->izq.buscar(e);
        }
        else
        {
            if(r->elem > e)
            {
                return r->der.buscar(e);
            }
            else
            {
                return *this;
            }
        }
    }
}

template <typename T>
void ArbolELBIBUS<T>::insertar(const T& e)
{
    if(r == nullptr)
    {
        r = new celda(e);
    }
    else
    {
        if(r->elem < e)
        {
            r->der.insertar(e);
        }
        else
        {
            if(r->elem > e)
            {
                r->izq.insertar(e);
            }
        }
    }
}

template <typename T>
void ArbolELBIBUS<T>::eliminar(const T& e)
{
    if(r != nullptr)
    {
        if(r->elem > e)
        {
            r->izq.eliminar(e);
        }
        else
        {
            if(r->elem < e)
            {
                r->der.eliminar(e);
            }
            else
            {
                if(r->izq.r == nullptr && r->der.r == nullptr)
                {
                    delete r;
                    r = nullptr;
                }
                else
                {
                    if(r->izq.r == nullptr)
                    {
                        celda *arb = r->der.r;
                        r->der.r = nullptr;
                        delete r;
                        r = arb;
                    }
                    else
                    {
                        if(r->der.r == nullptr)
                        {
                            celda *arb = r->izq.r;
                            r->izq.r = nullptr;
                            delete r;
                            r = arb;
                        }
                        else
                        {
                            r->elem = r->der.borraMin();
                        }
                    }
                }
            }
        }
    }
}

template <typename T>
T ArbolELBIBUS<T>::borraMin()
{
    if(r->izq.r == nullptr)
    {
        T e = r->elem;
        celda *arb = r->der.r;
        r->der.r = nullptr;
        delete r;
        r = arb;
        return e;
    }
    else
    {
        return r->izq.borraMin();
    }
}

template <typename T>
const T& ArbolELBIBUS<T>::element() const
{
    assert(r != nullptr);
    return r->elem;
}

template <typename T>
const ArbolELBIBUS<T>& ArbolELBIBUS<T>::izqu() const
{
    assert(r != nullptr);
    return r->izq;
}

template <typename T>
const ArbolELBIBUS<T>& ArbolELBIBUS<T>::dere() const
{
    assert(r != nullptr);
    return r->der;
}

template <typename T>
ArbolELBIBUS<T>::ArbolELBIBUS(const ArbolELBIBUS<T>& arb): r{nullptr}
{
    if(arb.r != nullptr)
    {
        r = new celda(*arb.r);
    }
}

template <typename T>
ArbolELBIBUS<T>& ArbolELBIBUS<T>::operator=(const ArbolELBIBUS<T>& arb)
{
    if(this != &arb)
    {
        this->~ArbolELBIBUS();
        if(arb.r != nullptr)
        {
            r = new celda(*arb.r);
        }
    }
    return *this;
}

template <typename T>
ArbolELBIBUS<T>::~ArbolELBIBUS()
{
    if(r != nullptr)
    {
        delete r;
    }
}



#endif // ARBOLESELBIBUS
