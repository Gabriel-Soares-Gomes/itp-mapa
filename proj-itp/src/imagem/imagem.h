#pragma once
#include "../paleta/paleta.h"

struct Pixel{
    int r, g, b;
};

class Matriz{
    int largura, altura; //capacidade
    int linhas, colunas; //tamanho

    public:

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