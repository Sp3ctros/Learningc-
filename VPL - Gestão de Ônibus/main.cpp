#include <iostream>
#include <string>
#include "Empresa.hpp"

int main()
{
    Empresa empresa;
while (true)
{

    char entrada_buffer;
    string placa_buffer;
    string placa2_buffer;
    int lot_maxima;
    int num_pessoas_buffer;
    Onibus* onibus_buffer;
    Onibus* onibus_buffer2;
    cin >> entrada_buffer;
    switch (entrada_buffer)
    {
    case 'C':
        cin >> placa_buffer >> lot_maxima;
        if ((empresa.adicionar_onibus(placa_buffer, lot_maxima)) != nullptr)
        {
            cout << "novo onibus cadastrado" << endl;
        }
        else
        {
            cout << "ERRO : onibus repetido" << endl;
        }
        break;
    case 'S':
        cin >> placa_buffer >> num_pessoas_buffer;
        onibus_buffer = empresa.buscar_onibus(placa_buffer);
        if (onibus_buffer != nullptr)
        {
            switch (onibus_buffer->subir_passageiros(num_pessoas_buffer))
            {
            case 1:
                cout << "ERRO : numero invalido de passageiros" << endl;
                break;
            case 2:
                cout << "ERRO : onibus lotado" << endl;
                break;
            case 0:
                cout << "passageiros subiram com sucesso" << endl;
                break;
            };
        }
        else
        {
            cout << "ERRO : onibus inexistente" << endl;
        }
        break;
    case 'D':
        cin >> placa_buffer >> num_pessoas_buffer;
        onibus_buffer = empresa.buscar_onibus(placa_buffer);
        if (onibus_buffer != nullptr)
        {
            if (onibus_buffer->descer_passageiros(num_pessoas_buffer) == 0)
            {
                cout << "passageiros desceram com sucesso" << endl;
            }
            else
            {
                cout << "ERRO : faltam passageiros" << endl;
            }
        }
        else
        {
            cout << "ERRO : onibus inexistente" << endl;
        }
        break;
    case 'T':
        cin >> placa_buffer >> placa2_buffer >> num_pessoas_buffer;
        onibus_buffer = empresa.buscar_onibus(placa_buffer);
        onibus_buffer2 = empresa.buscar_onibus(placa2_buffer);
        if ((onibus_buffer == nullptr) || (onibus_buffer2 == nullptr))
        {
            cout << "ERRO : onibus inexistente" << endl;
        }
        else
        {
            onibus_buffer->transfere_passageiros(num_pessoas_buffer, onibus_buffer2);
        }
        break;
    case 'I':
        empresa.imprimir_estado();
        break;
    case 'F':
        return 0;
    default:
        break;
    }
}
}
