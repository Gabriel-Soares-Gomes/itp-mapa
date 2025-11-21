#pragma once
#include "../paleta/paleta.h"
#include <fstream>
#include <string>
#include <iostream>

struct Pixel{
    int r, g, b;
};


class Matriz{
    int linhas; //altura maximo
    int colunas; //largura maxima

    //criando uma "matriz" de forma linear
    Pixel *valores;

    public:
    //Matriz() = default;

    Matriz(int l = 1, int c = 1)
    {
        linhas = l;
        colunas = c;
        valores = new Pixel[l*c];
    }

    ~Matriz() {
        delete[] valores;
    }

    int obterTamanho(){
        return (linhas*colunas);
    }

    Pixel& obterElemento(int index)
    {
        return valores[index];
    }
    
    /*Pixel& operator[] (int index)
    {
        return valores[index];
    }*/

};

class Imagem{
    int largura = 0;
    int altura = 0;
    int maxCor = 0;
    Matriz *pixels = nullptr;

    public:
    
    Imagem() = default;

    Imagem(int larg, int alt)
    {
        largura = larg;
        altura = alt;
        pixels = new Matriz(larg*alt);
    }

    ~Imagem()
    {
        delete pixels;
    }
    
    int obterAltura()
    {
        return altura;
    }

    int obterLargura()
    {
        return largura;
    }

    Pixel& operator() (int c, int l)
    {
        int indice = (l*largura)+c;
        return pixels->obterElemento(indice);
    }
     
    void redimensionar(int newWidth, int newHeight)
    {
        delete pixels;
        pixels = new Matriz(newWidth, newHeight);
        largura = newWidth;
        altura = newHeight;
    }

    bool lerPPM(std::string arquivo)
    {
        std::ifstream filePPM(arquivo);
        if(!filePPM.is_open()) return false;

        std::string tipoPPM = "";
        int alturaPPM, larguraPPM, intensidadeCorPPM;

        filePPM >> tipoPPM >> larguraPPM >> alturaPPM >> intensidadeCorPPM;

        if(alturaPPM != altura || larguraPPM != largura)
        {
            redimensionar(larguraPPM, alturaPPM);
        }

        //int cont = 0;
        for(int i = 0; i < alturaPPM;i++)
        {
            for(int j = 0; j < larguraPPM; j++)
            {
                int red, green, blue;
                filePPM >> red >> green >> blue;
                
                int indice = (i*larguraPPM) + j;
                this->pixels->obterElemento(indice).r = red;
                this->pixels->obterElemento(indice).g = green;
                this->pixels->obterElemento(indice).b = blue;
            }
        }
        filePPM.close();
        return true;
    }
};