#pragma once
#include "../paleta/paleta.h"
#include <fstream>
#include <string>

struct Pixel{
    int r, g, b;
};

class Matriz{
    int linhas; //altura maximo
    int colunas; //largura maxima
    Pixel *valores;

    public:

    Matriz(int l = 1, int c = 1){
        linhas = l;
        colunas = c;
        valores = new Pixel[l*c];
    }

    ~Matriz(){
        delete[] valores;
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

    Pixel& operator[](int index){
        return valores[index];
    }

};

class Imagem{
    int largura = 0;
    int altura = 0;
    int maxCor = 0;
    Matriz *pixels = nullptr;

    public:
    
    Imagem() = default;

    Imagem(int larg, int alt){
        largura = larg;
        altura = alt;
        pixels = new Matriz(larg, alt);
    }

    ~Imagem(){
        delete pixels;
    }
    
    int obterAltura(){
        return altura;
    }

    int obterLargura(){
        return largura;
    }

    Pixel& operator() (int l, int c){
        int indice = (l*altura)+c;
        return (*pixels)[indice];
    }

    void redimensionar(int newWidth, int newHeight){
        delete pixels;
        pixels = new Matriz(newWidth, newHeight);
        largura = newWidth;
        altura = newHeight;
    }

  
    bool lerPPM(std::string nome_arquivo){
        std::ifstream arquivo(nome_arquivo);
        std::string tipoPPM = "";
        int novaLargura, novaAltura;

        arquivo >> tipoPPM >> novaLargura >> novaAltura;

        if(!(arquivo.is_open())){
            std::cerr << "Não é possível abrir o arquivo";
            return false;
        }
        if((novaLargura != largura) || (novaAltura != altura)){
            redimensionar(novaLargura, novaAltura);
        }
    }
};