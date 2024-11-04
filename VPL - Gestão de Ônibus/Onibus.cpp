#include "Onibus.hpp"
#include <iostream>
#include <string>

Onibus::Onibus(string placa, int capacidade_max)
{
    this->placa = placa;
    this->capacidade_max = capacidade_max;
    this->lot_atual = 0;
}

int Onibus::subir_passageiros(int num_passageiros)
{
    if (num_passageiros < 0)
    {
        return 1;
    }
    if (lot_atual + num_passageiros > capacidade_max)
    {
        return 2;
    }
    lot_atual += num_passageiros;
    return 0;
}

int Onibus::descer_passageiros(int num_passageiros)
{
    if ((num_passageiros < 0) || ((lot_atual - num_passageiros) < 0))
    {
        return 1;
    }
    lot_atual -= num_passageiros;
    return 0;
}

int Onibus::transfere_passageiros(int num_passageiros, Onibus* onibus_seguinte)
{
    if (num_passageiros > lot_atual)
    {
        cout << "ERRO : transferencia cancelada" << endl;
        return 1;
    }
    if ((onibus_seguinte->lot_atual + num_passageiros) > onibus_seguinte->capacidade_max)
    {
        cout << "ERRO : transferencia cancelada" << endl;
        return 1;
    }
    if (placa == onibus_seguinte->placa)
    {
        cout << "ERRO : transferencia cancelada" << endl;
        return 2;
    }
    if ((descer_passageiros(num_passageiros) + onibus_seguinte->subir_passageiros(num_passageiros)) > 0)
    {
        cout << "ERRO : transferencia cancelada" << endl;
        return 3;
    }
    cout << "transferencia de passageiros efetuada" << endl;
    return 0;
}

int Onibus::imprime_estado()
{
    cout << placa << " (" << lot_atual << "/" << capacidade_max << ")" << endl;
    return 0;
}