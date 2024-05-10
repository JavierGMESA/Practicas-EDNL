#include <string>
#include <cassert>
#include "ArbolAritmetico.h"
#include "ArbolesELBIN.h"

float ArbolArit(const ArbolELBIN<std::string>& arb)
{
    return ArbolAritR(arb.raiz(), arb);
}

float ArbolAritR(ArbolELBIN<std::string>::nodo n, const ArbolELBIN<std::string>& arb)
{
    bool flotante = true;
    std::string cad = arb.element(n);
    if(std::isdigit(cad[0]))
    {
        return std::stof(cad);
    }
    else
    {
        if(cad[0] == '+')
        {
            return ArbolAritR(arb.Hizqui(n), arb) + ArbolAritR(arb.Hdere(n), arb);
        }
        if(arb.element(n)[0] == '-')
        {
            return ArbolAritR(arb.Hizqui(n), arb) - ArbolAritR(arb.Hdere(n), arb);
        }
        if(arb.element(n)[0] == '*')
        {
            return ArbolAritR(arb.Hizqui(n), arb) * ArbolAritR(arb.Hdere(n), arb);
        }
        if(arb.element(n)[0] == '/')
        {
            assert(ArbolAritR(arb.Hdere(n), arb) != 0);
            return ArbolAritR(arb.Hizqui(n), arb) / ArbolAritR(arb.Hdere(n), arb);
        }
    }
}
