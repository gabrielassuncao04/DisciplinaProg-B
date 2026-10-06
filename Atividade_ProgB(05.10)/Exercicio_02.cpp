/*2) construir um metodo que recebe uma data no formato dd/mm/aaaa e retorna se a data é válida, 
porém, avaliando a quantidade de digitos obrigatórios (10 caracteres)
OPS: Retirei as barras então 8*/

#include <iostream>
#include <string>

using namespace std;

void LeitorData(string &data) {
    cout << "Digite a Data: ";
    cin >> data;
}

bool Contador(string data) {
    int tamanho = 0;

    
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != '/') {
            tamanho++;
        }
    }

    
    if (tamanho < 8) {
        return false;
    } else {
        return true;
    }
}

int main() {
    string data;

    cout << "+++ Validar Data +++\n";

    LeitorData(data);

    if (Contador(data) == true) {
        cout << "Valor Valido\n";
    } else {
        cout << "Valor Invalido\n";
    }

    return 0;
}
