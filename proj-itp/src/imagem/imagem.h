#pragma once
#include "../paleta/paleta.h"
#include <iostream>

struct Pixel{
    int r, g, b;
};



class Matriz{
    int linhas;
    int colunas;
    Pixel *valores;

    public:

    Matriz(int l = 1, int c = 1){
        linhas = l;
        colunas = c;
        //Tratando uma array como matriz;
        valores = new Pixel[l*c];
    }

    ~Matriz(){
        delete[] valores;
    }


    int obterTamanho(){
        return (linhas*colunas);
    }

};

class Imagem{
    int largura = 1;
    int altura = 1;
    Matriz pixels;

    public:

    Imagem() = default;
    
    Imagem(int alt, int larg)
    {
        largura = larg;
        altura = alt;
    }

    int obterAltura()
    {
        return altura;
    }

    int obterLargura()
    {
        return largura;
    }

    Pixel& operator()(int l, int c){
        int indice = l*altura + c;
        return pixels[indice];
    }
};