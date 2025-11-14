#pragma once
#include "../paleta/paleta.h"

struct Pixel{
    int r, g, b;
};

class Matriz{
    int linhas;
    int colunas;

    //criando uma "matriz" de forma linear
    int *valores;

    public:

    Matriz(int l, int c){
        linhas = l;
        colunas = c;
        int valores[linhas*colunas];
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

};

class Imagem{
    int largura;
    int altura;
    Sequencia<Pixel> pixels;

    public:
    
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

    Pixel& operator= (Pixel pixel)
    {
        pixels.adicionar(pixel);
    }
};