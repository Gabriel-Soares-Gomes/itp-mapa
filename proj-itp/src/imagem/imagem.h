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
    int largura, altura;
    Sequencia<Pixel> pixels;
};