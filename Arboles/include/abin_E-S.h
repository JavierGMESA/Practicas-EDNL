#ifndef ABIN_E_S_H
#define ABIN_E_S_H

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include "ArbolesELBIN.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void rellenarAbin(ArbolELBIN<T>& A, const T& fin)
// Pre: A está vacío.
// Post: Rellena el árbol A con la estructura y elements
//       leídos en preorden de la entrada estándar, usando
//       fin como element especial para introducir nodos nulos.
{
   T e;

   assert(A.vacio());
   cout << "Raiz (Fin = " << fin << "): "; cin >> e;
   if (e != fin) {
      A.insertarRaiz(e);
      rellenarDescendientes(A.raiz(), A, fin);
   }
}

template <typename T>
void rellenarDescendientes(typename ArbolELBIN<T>::nodo n, ArbolELBIN<T>& A, const T& fin)
// Pre: n es un nodo hoja de A.
// Post: Lee de la entrada estándar y en preorden los descendientes de n,
//       usando fin para introducir nodos nulos.
{
   T ehi, ehd;

   assert(A.Hizqui(n) == ArbolELBIN<T>::NODO_NULO &&
          A.Hdere(n) == ArbolELBIN<T>::NODO_NULO);
   cout << "Hijo izqdo. de " << A.element(n) <<
                " (Fin = " << fin << "): ";
   cin >> ehi;
   if (ehi != fin) {
      A.insertarHizqui(n, ehi);
      rellenarDescendientes(A.Hizqui(n), A, fin);
   }
   cout << "Hijo drcho. de " << A.element(n) <<
                " (Fin = " << fin << "): ";
   cin >> ehd;
   if (ehd != fin) {
      A.insertarHdere(n, ehd);
      rellenarDescendientes(A.Hdere(n), A, fin);
   }
}

template <typename T>
void rellenarAbin(istream& is, ArbolELBIN<T>& A)
// Pre: A está vacío.
// Post: Extrae los nodos de A del flujo de entrada is,
//       que contendrá el element especial que denota
//       un nodo nulo seguido de los elements en preorden,
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
void rellenarDescendientes(istream& is, typename ArbolELBIN<T>::nodo n, ArbolELBIN<T>& A, const T& fin)
// Pre: n es un nodo hoja de A.
// Post: Lee del flujo de entrada is y en preorden los descendientes de n,
//       usando fin para los nodos nulos.
{
   T ehi, ehd;

   assert(A.Hizqui(n) == ArbolELBIN<T>::NODO_NULO &&
          A.Hdere(n) == ArbolELBIN<T>::NODO_NULO);
   if (is >> ehi && ehi != fin) {
      A.insertarHizqui(n, ehi);
      rellenarDescendientes(is, A.Hizqui(n), A, fin);
   }
   if (is >> ehd && ehd != fin) {
      A.insertarHdere(n, ehd);
      rellenarDescendientes(is, A.Hdere(n), A, fin);
   }
}

template <typename T>
void imprimirAbin (const ArbolELBIN<T>& A)
// Post: Muestra los nodos de A en la salida estándar.
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
void imprimirDescendientes (typename ArbolELBIN<T>::nodo n, const ArbolELBIN<T>& A)
// Post: Muestra los descendientes de n en la salida estándar.
{
   if (A.Hizqui(n) != ArbolELBIN<T>::NODO_NULO)
   {
      cout << "Hijo izqdo de " << A.element(n) << ": "
                << A.element(A.Hizqui(n)) << endl;
      imprimirDescendientes(A.Hizqui(n), A);
   }
   if (A.Hdere(n) != ArbolELBIN<T>::NODO_NULO)
   {
      cout << "Hijo derecho de " << A.element(n) << ": "
                << A.element(A.Hdere(n)) << endl;
      imprimirDescendientes(A.Hdere(n), A);
   }
}

template <typename T>
void imprimirAbin (ostream& os, const ArbolELBIN<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os los nodos de A en preorden,
//       precedidos del element especial usado para denotar un nodo nulo.
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
void imprimirDescendientes (ostream& os, typename ArbolELBIN<T>::nodo n, const ArbolELBIN<T>& A, const T& fin)
// Post: Inserta en el flujo de salida os y en preorden
//       los descendientes de n, usando fin como nodo nulo.
{
   if (A.Hizqui(n) != ArbolELBIN<T>::NODO_NULO)
   {
      os << A.element(A.Hizqui(n)) << ' ';
      imprimirDescendientes(os, A.Hizqui(n), A, fin);
   }
   else
      os << fin << ' ';
   if (A.Hdere(n) != ArbolELBIN<T>::NODO_NULO)
   {
      os << A.element(A.Hdere(n)) << ' ';
      imprimirDescendientes(os, A.Hdere(n), A, fin);
   }
   else
      os << fin << ' ';
}

#endif   // ABIN_E_S_H
