#pragma once
#include "../../../doctest.h"
#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

class Terreno{

    Matriz<int> *terreno;
    int dimensao;
    public:

    Terreno(int n){
        dimensao =  pow(2, n) + 1;
        terreno = new Matriz<int>(dimensao, dimensao);
        for(int i = 0; i < (dimensao*dimensao); i++){
            terreno->obterElemento(i) = 0;
        }
        //srand(10);
        matrizInicial();
    }

    ~Terreno() {
        delete terreno;
    }

    int& operator()(int linha, int coluna){
        int indice = ((linha*dimensao) + coluna);
        return terreno->obterElemento(indice);
    }

    void matrizInicial(){
        (*this)(0, 0) = 10; //rand() % 10; perguntar a André por que o *this.
        (*this)(0, dimensao - 1) = 10; //rand() % 10;
        (*this)(dimensao - 1, 0) = 10; //rand() % 10;
        (*this)((dimensao - 1), (dimensao - 1)) = 10; //rand() % 10;
        DiamondSquare();
    }

    void imprimirMatriz(){
        for(int i = 0; i < terreno->obterAltura(); i++){
            for(int j = 0; j < terreno->obterLargura(); j++){
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void DiamondSquare(){
        int passos = (dimensao-1)/2;
        float rugosidade = 0.5;
        int variancia = dimensao/2;
        int deslocamento = (rand() % ((2*variancia) + 1)) - variancia;

        while(passos >= 1){
            Diamond(passos);
            Square(passos);

            passos /= 2;
            rugosidade /= 2;
        }
    }

    void Diamond(int posicao){
    }

    void Square(int posicao){

    }

    int obterLargura(){
        return terreno->obterLargura();
    }

    int obterProfundidade(){
        return terreno->obterAltura();
    }
};