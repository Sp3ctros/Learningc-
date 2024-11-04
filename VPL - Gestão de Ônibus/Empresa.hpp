#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <string>
#include "Onibus.hpp"

using namespace std;

class Empresa
{
    public:
    Empresa();
    Onibus* adicionar_onibus(string placa, int lot_maxima);
    Onibus* buscar_onibus(string placa);
    int imprimir_estado();
    private:
    int num_onibus;
    Onibus *vet_onibus[20];
};

#endif