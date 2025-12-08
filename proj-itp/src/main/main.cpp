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

    cout << "Nome do arquivo com a paleta de cores (Insira 'cores.hex' para utilizar a paleta padrão.): " << '\n';
    cin >> filenamePaleta;

    cout << "Tamanho do mapa: ";
    cin >> tamanho;

    cout << "Nome do arquivo da imagem: ";
    cin >> filenamePPM;

    cout << "Gerando o mapa... " << "\n";
    
    Paleta paleta(filenamePaleta);
    Terreno terreno(tamanho);

    terreno.normalizar();
    terreno.geradorImagem(paleta, filenamePPM);
    cout << "Mapa gerado!" << '\n';
}
