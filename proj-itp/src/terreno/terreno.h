#pragma once
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include "../imagem/imagem.h"
#include "../../../doctest.h"

class Terreno {
    Matriz<int> *terreno;
    int medida;
    
    void geradorCantosIniciais()
    {
        //Define os valores aleatórios dos 4 cantos do terreno;
        srand(time(0));
        
        //Intervalo de alturas: [1, 10]
        (*this)(0,0) = rand()%10+1;
        (*this)(0, medida-1) = rand()%10+1;
        (*this)(medida-1, 0) = rand()%10+1;
        (*this)(medida-1, medida-1) = rand()%10+1;
    }

    void DiamondSquare()
    {
        diamondStep();
        squareStep();
    }


    void diamondStep()
    {
        
    }
    
    void squareStep()
    {

    }
    
    public:

    Terreno(int n)
    {
        medida = pow(2, n) + 1;
        //Cria novo terreno quadrado de tamanho 2^n + 1
        terreno = new Matriz<int>(medida,medida);
        
        geradorCantosIniciais();
        DiamondSquare();
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

    int& operator() (int lin, int col)
    {
        //Retorna uma célula específica da matriz terreno(l, c)
        return terreno->obterElemento((lin*medida)+col);
    }

    void printMat()
    {
        for(int i = 0; i < medida; i++)
        {
            for(int j = 0; j < medida; j++)
            {
                std::cout << this->operator()(i,j) << ' ';
            }
            std::cout << '\n';
        }
    }
};                          
