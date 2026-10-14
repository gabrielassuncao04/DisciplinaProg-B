// 3 - Construa um programa (com módulo/método) 
//que leia n nomes de pessoas, armazena em um vetor de nomes e os exiba na tela. 
//Porém, é necessário ao lado do nome mostrar quantos caractares tem esse nome.

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
} Pessoa;

int main() {
    int n;
    
    cout << "Informe a quantidade de pessoas: ";
    cin >> n;
    cin.ignore(); 


    Pessoa pessoas[100];

    
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome completo da " << i + 1 << "a pessoa: ";
        getline(cin, pessoas[i].nomeCompleto);

        int ultimaPosicaoEspaco = -1;
        for (int j = 0; j < pessoas[i].nomeCompleto.length(); j++) {
            if (pessoas[i].nomeCompleto[j] == ' ') {
                ultimaPosicaoEspaco = j; 
            }
        }

        if (ultimaPosicaoEspaco != -1) {
            pessoas[i].sobreNome = pessoas[i].nomeCompleto.substr(ultimaPosicaoEspaco + 1);
        } else {
            pessoas[i].sobreNome = "(Sem sobrenome)";
        }
    }

    
    cout << "\n=== RESULTADO ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nome Completo: " << pessoas[i].nomeCompleto << "\n";
        cout << "Sobrenome:     " << pessoas[i].sobreNome << "\n";
        cout << "--------------------\n";
    }

    return 0;
}
