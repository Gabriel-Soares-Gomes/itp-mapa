#pragma once
#include "../paleta/paleta.h"

struct Pixel{
    int r, g, b;
};

class Imagem{
    int largura, altura;
    Sequencia<Pixel> pixels;
};