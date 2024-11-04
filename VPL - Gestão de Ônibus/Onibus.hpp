#ifndef ONIBUS_HPP
#define ONIBUS_HPP
#include <string>
#include <iostream>

using namespace std;

class Onibus
{
    public:
    Onibus(string placa, int capacidade_max);
    int subir_passageiros(int num_passageiros);
    int descer_passageiros(int num_passageiros);
    int transfere_passageiros(int num_passageiros, Onibus* onibus_seguinte);
    int imprime_estado();
    string placa;
    private:
    int capacidade_max;
    int lot_atual;
};
#endif
