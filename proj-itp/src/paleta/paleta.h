#include "sequencia.h"

class Cor{
    int r, g, b;
};

class Paleta{
    Sequencia<Cor> cores;
    int tamanho;


    public:

    Paleta(){
        tamanho = 0;
    };


    int obterTamanho(void){
        return tamanho;
    }


};