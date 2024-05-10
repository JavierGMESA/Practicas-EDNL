#include <iostream>
#include <string>

#include "ArbolesELBIN.h"
#include "ArbolesVBIN.h"
#include "ArbolesVPSBIN.h"
#include "ArbolesVGEN.h"
#include "ArbolesELGEN.h"
#include "ArbolesELBIBUS.h"

#include "abin_E-S.h"
#include "agen_E-S.h"
#include "CuentaNodos.h"
#include "AlturaArbol.h"
#include "ProfundidadArbol.h"
#include "Desequilibrio.h"
#include "Pseudocompleto.h"
#include "ArbolAritmetico.h"
#include "ArbolReflejado.h"
#include "DesequilibrioGen.h"
#include "gradoAgen.h"
#include "ABBequilibrado.h"
#include "ABBConjuntos.h"
#include "PodaAgen.hpp"



void PruebaAEB();
void PruebaAV1B();
void PruebaAV2B();
void PruebaAVG();
void PruebaAELG();
void PruebaAELBB();
void PCuentaNodos();
void PAlturaArbol();
void PProfundidadArbol();
void PDesequilibrio();
void PPseudocompleto();
void PAritmetico();
void PArbolRefle();
void PDesequilibrioGen();
void PGradoAgen();
void PruebaABBequilibrado();
void PABBConjuntos();
void PAgenPodar();

int main()
{
    //PruebaAEB();
    //PruebaAV1B();
    //PruebaAV2B();
    //PruebaAVG();
    //PruebaAELG();
    //PruebaAELBB();
    //PCuentaNodos();
    //PAlturaArbol();
    //PProfundidadArbol();
    //PDesequilibrio();
    //PPseudocompleto();
    //PAritmetico();
    //PArbolRefle();
    //PDesequilibrioGen();
    //PGradoAgen();
    //PruebaABBequilibrado();
    //PABBConjuntos();
    PAgenPodar();

    std::cout << std::endl << "System Pause" << std::endl;
    return 0;
}

void PruebaAEB()
{
    ArbolELBIN<int> arb, arb2;
    ArbolELBIN<int>::nodo n;
    arb.insertarRaiz(2);
    std::cout << arb.element(arb.raiz()) << std::endl;
    n = arb.raiz();
    arb.insertarHizqui(n, -2);
    arb.insertarHdere(n, 1);
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl;
    n = arb.Hizqui(n);
    arb.insertarHizqui(n, -5);
    arb.insertarHdere(n, 16);
    std::cout << arb.element(n) << std::endl;
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl << std::endl;
    arb2 = arb;
    std::cout << arb2.element(arb2.raiz()) << std::endl;
    n = arb2.raiz();
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
    n = arb2.Hizqui(n);
    std::cout << arb2.element(n) << std::endl;
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
}

void PruebaAV1B()
{
    ArbolVBIN<int> arb(50), arb2(30);
    ArbolVBIN<int>::nodo n;
    arb.insertarRaiz(2);
    std::cout << arb.element(arb.Raiz()) << std::endl;
    n = arb.Raiz();
    arb.insertarHizqui(n, -2);
    arb.insertarHdere(n, 1);
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl;
    n = arb.Hizqui(n);
    arb.insertarHizqui(n, -5);
    arb.insertarHdere(n, 16);
    std::cout << arb.element(n) << std::endl;
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl << std::endl;
    arb2 = arb;
    std::cout << arb2.element(arb2.Raiz()) << std::endl;
    n = arb2.Raiz();
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
    n = arb2.Hizqui(n);
    std::cout << arb2.element(n) << std::endl;
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
    arb.eliminarHdere(arb.Raiz());
    n = arb2.Hizqui(arb.Raiz());
    std::cout << arb2.element(n) << std::endl;
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
}

void PruebaAV2B()
{
    ArbolVPSBIN<int> arb(50, 8), arb2(30, 8);
    ArbolVPSBIN<int>::nodo n;
    arb.insertarRaiz(2);
    std::cout << arb.element(arb.Raiz()) << std::endl;
    n = arb.Raiz();
    arb.insertarHizqui(n, -2);
    arb.insertarHdere(n, 1);
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl;
    n = arb.Hizqui(n);
    arb.insertarHizqui(n, -5);
    arb.insertarHdere(n, 16);
    std::cout << arb.element(n) << std::endl;
    std::cout << arb.element(arb.Hizqui(n)) << ' ' << arb.element(arb.Hdere(n)) << std::endl << std::endl;
    arb2 = arb;
    std::cout << arb2.element(arb2.Raiz()) << std::endl;
    n = arb2.Raiz();
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
    n = arb2.Hizqui(n);
    std::cout << arb2.element(n) << std::endl;
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
    arb.eliminarHdere(arb.Raiz());
    n = arb2.Hizqui(arb.Raiz());
    if(arb.Hdere(arb.Raiz()) == ArbolVPSBIN<int>::NODO_NULO)
    {
        std::cout << "NODO NULO" << std::endl;
    }
    std::cout << arb2.element(n) << std::endl;
    std::cout << arb2.element(arb2.Hizqui(n)) << ' ' << arb2.element(arb2.Hdere(n)) << std::endl;
}

void PruebaAVG()
{
    ArbolVGEN<int> arb1(30);
    ArbolVGEN<int> arb2(20);
    ArbolVGEN<int>::nodo n;
    arb1.insertarRaiz(5);
    std::cout << arb1.element(arb1.raiz()) << std::endl;
    n = arb1.raiz();
    arb1.insertarHizqui(n, 4);
    arb1.insertarHizqui(n, 3);
    std::cout << n << std::endl;
    n = arb1.Hizqui(n);
    std::cout << arb1.element(n) << arb1.element(arb1.Herdere(n)) << std::endl;
    arb1.eliminarHerdere(n);
    n = arb1.Hizqui(arb1.raiz());
    std::cout << arb1.element(n) << std::endl;
    //std::cout << arb1.element(n) << std::endl;
}

void PruebaAELG()
{
    ArbolELGEN<int> arb1;
    ArbolELGEN<int> arb2;
    ArbolELGEN<int>::nodo n;
    arb1.insertarRaiz(5);
    std::cout << arb1.element(arb1.raiz()) << std::endl;
    n = arb1.raiz();
    arb1.insertarHizqui(n, 4);
    arb1.insertarHizqui(n, 3);
    n = arb1.Hizqui(n);
    std::cout << arb1.element(n) << arb1.element(arb1.Herdere(n)) << std::endl;
    arb1.eliminarHerdere(n);
    n = arb1.Hizqui(arb1.raiz());
    std::cout << arb1.element(n) << std::endl;
}

void PruebaAELBB()
{
    ArbolELBIBUS<int> arb1;
    ArbolELBIBUS<int> arb2{};
    arb1.insertar(9);
    arb1.insertar(6);
    arb1.insertar(14);
    arb1.insertar(12);
    std::cout << arb1.element() << ' ' << arb1.dere().element() << std::endl;
    std::cout << arb1.dere().izqu().element() << std::endl;
    arb2 = arb1;
    arb1.eliminar(14);
    std::cout << arb1.dere().element() << ' ' << arb2.dere().element() << std::endl;
}

void PCuentaNodos()
{
    ArbolELBIN<int> arb;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    std::cout << "El numero de nodos es: " << CuentaNodos(arb) << std::endl;
}

void PAlturaArbol()
{
    ArbolELBIN<int> arb;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    std::cout << "La altura del arbol es: " << AlturaArbol(arb) << std::endl;
}

void PProfundidadArbol()
{
    ArbolELBIN<int> arb;
    ArbolELBIN<int>::nodo n;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    n = arb.raiz();
    n = arb.Hizqui(n);
    n = arb.Hdere(n);
    std::cout << "La profundidad de n en el arbol es: " << ProfundidadArbol(arb, n) << std::endl;
}

void PDesequilibrio()
{
    ArbolELBIN<int> arb;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    std::cout << "El desequilibrio del arbol es: " << ArbolDesequilibrado(arb) << std::endl;
}

void PPseudocompleto()
{
    ArbolELBIN<int> arb;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    if(ArbolPseudoC(arb))
    {
        std::cout << "El arbol esta pseudocompleto" << std::endl;
    }
    else
    {
        std::cout << "El arbol no esta pseudocompleto" << std::endl;
    }
}

void PAritmetico()
{
    std::string cad = "j";
    ArbolELBIN<std::string> arb;
    ArbolELBIN<std::string>::nodo n;
    rellenarAbin(arb, cad);
    imprimirAbin(arb);
    std::cout << ArbolArit(arb) << std::endl;
}

void PArbolRefle()
{
    ArbolELBIN<int> arb;
    ArbolELBIN<int>::nodo n;
    rellenarAbin(arb, 8);
    imprimirAbin(arb);
    ArbolELBIN<int> arb2 = ArbolRefle(arb);
    imprimirAbin(arb2);
}

void PDesequilibrioGen()
{
    ArbolELGEN<int> arb;
    rellenarAgen(arb, 8);
    imprimirAgen(arb);
    std::cout << DesequilibrioGen(arb) << std::endl;
}

void PGradoAgen()
{
    ArbolELGEN<int> arb;
    rellenarAgen(arb, 8);
    imprimirAgen(arb);
    std::cout << gradoAgen(arb) << std::endl;
}

void PruebaABBequilibrado()
{
    ArbolELBIBUS<int> arb;
    arb.insertar(30);
    arb.insertar(29);
    arb.insertar(28);
    arb.insertar(27);
    arb.insertar(26);
    arb.insertar(25);
    arb.insertar(24);
    arb.insertar(23);
    arb.insertar(22);
    arb.insertar(21);
    std::cout << "Va a equilibrar" << std::endl;
    ABBequilibrado(arb);
    std::cout << arb.element() << ' ' << arb.izqu().element() << ' ' << arb.dere().element() << std::endl;

}

void PABBConjuntos()
{
    Conjunto<int> con1;
    Conjunto<int> con2;
    con1.insertar(1);
    con1.insertar(2);
    con1.insertar(3);
    con1.insertar(4);
    con1.insertar(5);
    con1.insertar(6);
    con1.insertar(7);
    con2.insertar(6);
    con2.insertar(7);
    con2.insertar(8);
    con2.insertar(9);
    con2.insertar(10);
    con2.insertar(11);
    con1.mostrarRaizHijos();
    con2.mostrarRaizHijos();
    Conjunto<int> con3 = con1 / con2;
    Conjunto<int> con4 = con1 - con2;
    Conjunto<int> con5 = con1 + con2;
    con3.mostrarRaizHijos();
    con4.mostrarRaizHijos();
    con5.mostrarRaizHijos();
}

void PAgenPodar()
{
    ArbolELGEN<int> arb;
    rellenarAgen(arb, 8);
    imprimirAgen(arb);
    ArbolELGEN<int>::nodo n = buscarElem(arb.raiz(), 6, arb);
    std::cout << arb.element(n) << std::endl;
    podar(6, arb);
    imprimirAgen(arb);
}