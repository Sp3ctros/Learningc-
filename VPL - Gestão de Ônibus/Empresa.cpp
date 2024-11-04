#include "Empresa.hpp"
#include <iostream>
#include <string>

using namespace std;

Empresa::Empresa()
{
    this->num_onibus = 0;
    for (int i = 0; i < 20; i++)
    {
        this->vet_onibus[i] = nullptr;
    }
}

Onibus* Empresa::buscar_onibus(string placa)
{
    for (int i = 0; i < num_onibus; i++)
    {
        if (placa == vet_onibus[i]->placa)
        {
            return vet_onibus[i]; 
        }
    }
    return nullptr;
}

Onibus* Empresa::adicionar_onibus(string placa, int lot_maxima)
{
    if (buscar_onibus(placa) == nullptr)
    {
        vet_onibus[num_onibus] = new Onibus(placa, lot_maxima);
        num_onibus++;
        return vet_onibus[num_onibus-1];
    }
    return nullptr;
}

int Empresa::imprimir_estado()
{
    cout << "Teste!" << endl;
    for (int i = 0; i < num_onibus; i++)
    {
        vet_onibus[i]->imprime_estado();
    }
    return 0;
}
