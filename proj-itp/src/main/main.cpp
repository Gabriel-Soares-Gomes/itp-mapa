#define DOCTEST_CONFIG_IMPLEMENT
#include "../../../doctest.h"
#include "../terreno/terreno.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string filenamePaleta, filenamePPM;
    int tamanho;
    
    cout << "! ----- GERADOR DE MAPA  ----- !" << '\n';

    cout << "Nome do arquivo com a paleta de cores: ";
    cin >> filenamePaleta; // /files/cores.hex

    cout << "Tamanho do mapa: ";
    cin >> tamanho;

    cout << "Nome do arquivo PPM a ser salvo: ";
    cin >> filenamePPM;
    cout << "Gerando o mapa... " << "\n";
    
    Paleta paleta(filenamePaleta);
    Terreno terreno(tamanho);
    
    //terreno.imprimirMatriz();
    terreno.normalizar();
    terreno.geradorImagem(paleta, filenamePPM);
    cout << "Mapa gerado!" << '\n';
}
