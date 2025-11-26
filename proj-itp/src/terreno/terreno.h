#pragma once
#include <cstdlib>
#include <cmath>
#include "../imagem/imagem.h"
#include "../../../doctest.h"

class Terreno {
    Matriz<int> *terreno;

    public:

    Terreno(int n)
    {
        int medida = pow(2, n) + 1;
        terreno = new Matriz<int>(medida,medida);
    }

    ~Terreno() 
    {
        delete terreno;
    }

    int obterLargura()
    {
        return terreno->obterLargura();
    }

    int obterProfundidade()
    {
        return terreno->obterAltura();
    }
};