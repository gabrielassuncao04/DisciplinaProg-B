/*1) construir um metodo que receba um número de cpf sem pontuação e retorna se o cpf é valido,
porém, avaliando somente a quantidade de digitos (11 digitos)*/

#include <iostream>
#include <string>

using namespace std;

void LeitorCPF(string &cpf) {
    cout << "Informe seu CPF: ";
    cin >> cpf;
}

bool Contador(string cpf) {
    int tamanho = 0; 
    
    for (int i = 0; i < cpf.length(); i++) {
        if (cpf[i] != '-' && cpf[i] != '.') {
            tamanho++;
        }
    }
    
    if (tamanho < 11) {
        return false;
    } else {
        return true;
    }
}

int main() {
    string cpf;
    cout << "+++ Verificador de CPF +++\n";

    LeitorCPF(cpf);

    if (Contador(cpf)) {
        cout << "Valor Valido\n";
    } else {
        cout << "Valor invalido\n";
    }

    return 0;
}