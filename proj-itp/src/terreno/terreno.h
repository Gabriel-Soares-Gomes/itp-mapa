#pragma once
#include "../../../doctest.h"
#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

class Terreno{

    Matriz<int> *terreno;

    public:

    Terreno(int n){
        int dimensao =  pow(2, n) + 1;
        terreno = new Matriz<int>(dimensao, dimensao);
    }

    ~Terreno() {
        delete terreno;
    }

    int& operator()(int l, int c){
        int indice = (l*(*terreno).colunas) + c;
    }

    void matrizInicial(){
        srand(time(0));
        

    }

    int obterLargura(){
        return terreno->obterLargura();
    }

    int obterProfundidade(){
        return terreno->obterAltura();
    }
};