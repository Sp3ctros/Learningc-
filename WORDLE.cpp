#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>

using namespace std;

class Palavra{
    public:
    Palavra();
    string letras;
    int char_em_string(char a, string b);
    bool comparar_palavras(string a);
    private:
    string letras_erradas;
};

Palavra::Palavra(){
    letras = "";
    letras_erradas = "";
}

int Palavra::char_em_string(char a, string b)
{
    for (size_t i = 0; i < b.length(); i++)
    {
        if (a == b[i])
        return 1;
    }
    return 0;
}

bool Palavra::comparar_palavras(string a){
    if (a == letras)
    {
        cout << letras << " (" << letras_erradas << ')' << endl;
        cout << "GANHOU!" << endl;
        return 1;
    }
    else
    {
        for (size_t i = 0; i < a.length();i++)
        {
            if (letras[i] == a[i])
            {
                cout << letras[i];
            }
            else
            {
                if (char_em_string(a[i], letras))
                {
                    char minusculo = tolower(a[i]);
                    cout << minusculo;
                }
                else
                {
                    if (char_em_string(a[i], letras_erradas) == 0)
                    {
                        letras_erradas += a[i];
                    }
                    cout << '*';
                }
            }
        }
        cout << " (" << letras_erradas << ')' << endl;
    }
    return 0;
}



int main() {
    ifstream entrada("palavras.txt", fstream::in);
    int num_palavras;
    int chave;
    Palavra palavra;
    Palavra palavra_escolhida;
    entrada >> num_palavras;
    Palavra *lista_de_palavras = new Palavra[num_palavras];
    for (int i = 0; i < num_palavras; i++)
    {
        entrada >> lista_de_palavras[i].letras;
    }
    cin >> chave;
    palavra_escolhida.letras = lista_de_palavras[chave-1].letras;
    for (int i = 0; i < 5; i++)
    {
        cin >> palavra.letras;
        if (palavra_escolhida.comparar_palavras(palavra.letras))
        {
            return 1;
        }
    }
    cout << "PERDEU! " << palavra_escolhida.letras << endl;
    return 0;
}
