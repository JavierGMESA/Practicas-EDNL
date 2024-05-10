#ifndef AGEN_E_S_H
#define AGEN_E_S_H

#include <cassert>
#include <iostream>
#include <fstream>
#include "ArbolesELGEN.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void rellenarAgen(ArbolELGEN<T>& A, const T& fin)
// Pre: A está vacío.
// Post: Rellena el árbol A con la estructura y elementos
//       leídos en preorden de la entrada estándar, usando
//       fin como elemento especial para introducir nodos nulos.
{
   T e;

   assert(A.vacio());
   cout << "Raíz (Fin = " << fin << "): "; cin >> e;
   if (e != fin) {
      A.insertarRaiz(e);
      rellenarDescendientes(A.raiz(), A, fin);
   }
}

template <typename T>
void rellenarDescendientes(typename ArbolELGEN<T>::nodo n, ArbolELGEN<T>& A, const T& fin)
// Pre: n es un nodo hoja de A.
// Post: Lee de la entrada estándar y en preorden los descendientes de n,
//       usando fin para introducir nodos nulos.
{
   T ehi, ehd;

   assert(A.Hizqui(n) == ArbolELGEN<T>::NODO_NULO);
   cout << "Hijo izqdo. de " << A.element(n)
        << " (Fin = " << fin << "): ";
   cin >> ehi;
   if (ehi != fin) {
      A.insertarHizqui(n, ehi);
      rellenarDescendientes(A.Hizqui(n), A, fin);
      typename ArbolELGEN<T>::nodo hijo = A.Hizqui(n);
      cout << "Hermano drcho. de " << A.element(hijo)
           << " (Fin = " << fin << "): ";
      cin >> ehd;
      while (ehd != fin) {
         A.insertarHerdere(hijo, ehd);
         rellenarDescendientes(A.Herdere(hijo), A, fin);
         hijo = A.Herdere(hijo);
         cout << "Hermano drcho. de " << A.element(hijo)
              << " (Fin = " << fin << "): ";
         cin >> ehd;
      }
   }
}

template <typename T>
void rellenarAgen(istream& is, ArbolELGEN<T>& A)
// Pre: A está vacío.
// Post: Extrae los nodos de A del flujo de entrada is,
//       que contendrá el elemento especial que denota
//       un nodo nulo seguido de los elementos en preorden,
//       incluyendo los correspondientes a nodos nulos.
{
   T e, fin;

   assert(A.vacio());
   if (is >> fin && is >> e && e != fin) {
      A.insertarRaiz(e);
      rellenarDescendientes(is, A.raiz(), A, fin);
   }
}

template <typename T>
void rellenarDescendientes(istream& is, typename ArbolELGEN<T>::nodo n, ArbolELGEN<T>& A, const T& fin)
// Pre: n es un nodo hoja de A.
// Post: Lee del flujo de entrada is y en preorden los descendientes de n,
//       usando fin para los nodos nulos.
{
   T ehi, ehd;

   assert(A.Hizqui(n) == ArbolELGEN<T>::NODO_NULO);
   if (is >> ehi && ehi != fin) {
      A.insertarHizqui(n, ehi);
      rellenarDescendientes(is, A.Hizqui(n), A, fin);
      typename ArbolELGEN<T>::nodo hijo = A.Hizqui(n);
      while (is >> ehd && ehd != fin) {
         A.insertarHerdere(hijo, ehd);
         rellenarDescendientes(is,A.Herdere(hijo), A, fin);
         hijo = A.Herdere(hijo);
      }
   }
}

template <typename T>
void imprimirAgen(const ArbolELGEN<T>& A)
// Post: Muestra los nodos de A en la salida estándar
{
   if (!A.vacio())
   {
      cout << "Raiz del arbol: "
           << A.element(A.raiz()) << endl;
      imprimirDescendientes(A.raiz(), A);
   }
   else
      cout << "Arbol vacio\n";
}

template <typename T>
void imprimirDescendientes(typename ArbolELGEN<T>::nodo n, const ArbolELGEN<T>& A)
// Post: Muestra los descendientes de n en la salida estándar.
{
   if (A.Hizqui(n) != ArbolELGEN<T>::NODO_NULO)
   {
      typename ArbolELGEN<T>::nodo hijo = A.Hizqui(n);
      cout << "Hijo izqdo de " << A.element(n) << ": "
           << A.element(hijo) << endl;
      while (hijo != ArbolELGEN<T>::NODO_NULO) {
         imprimirDescendientes(hijo, A);
         if (A.Herdere(hijo) != ArbolELGEN<T>::NODO_NULO)
            cout << "Hermano derecho de " << A.element(hijo) << ": "
                 << A.element(A.Herdere(hijo)) << endl;
         hijo = A.Herdere(hijo);
      }
   }
}

template <typename T>
void imprimirAgen(ostream& os, const ArbolELGEN<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os los nodos de A en preorden,
//       precedidos del elemento especial usado para denotar un nodo nulo.
{
   if (!A.vacio())
   {
      os << fin << endl
         << A.element(A.raiz()) << ' ';
      imprimirDescendientes(os, A.raiz(), A, fin);
      os << endl;
   }
}

template <typename T>
void imprimirDescendientes(ostream& os, typename ArbolELGEN<T>::nodo n, const ArbolELGEN<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os y en preorden
//       los descendientes de n, usando fin como nodo nulo.
{
   typename ArbolELGEN<T>::nodo hijo = A.Hizqui(n);
   while (hijo != ArbolELGEN<T>::NODO_NULO) {
      os << A.element(hijo) << ' ';
      imprimirDescendientes(os, hijo, A, fin);
      hijo = A.Herdere(hijo);
   }
   os << fin << ' ';
}

#endif   // AGEN_E_S_H
