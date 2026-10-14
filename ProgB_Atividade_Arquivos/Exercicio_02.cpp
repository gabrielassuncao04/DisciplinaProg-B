/*Construa um programa (com módulo/método) que leia n nomes completos de pessoas DE UM ARQUIVO DE ORIGEM e os adicione em um vetor de n posicoes em que deve ser armazenado o nome completo e o sobrenome. Use a seguinte estrutura;

typedef struct { string nomeCompleto; string sobreNome; } Pessoa;

Dica: será preciso fazer uma função que extraia o sobrenome de um nome completo.

AO FINAL, ESSES DADOS (nomeCompleto e sobreNome) devem ser salvos em um arquivo de destino, da seguinte forma, por exemplo:

Alexandre de Oliveira Zamberlan; Zamberlan Carlos Alberto Parreira; Parreira Luisa Figueiredo; Figueiredo*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
} Pessoa;

string extrairSobrenome(string nomeCompleto) {
    int ultimaPosicaoEspaco = -1;
    for (int i = 0; i < nomeCompleto.length(); i++) {
        if (nomeCompleto[i] == ' ') {
            ultimaPosicaoEspaco = i;
        }
    }
    
    if (ultimaPosicaoEspaco != -1) {
        return nomeCompleto.substr(ultimaPosicaoEspaco + 1);
    }
    return "";
}

int main() {
    string arqOrigem, arqDestino;
    int n;
    
    cout << "Informe o nome do arquivo de origem: ";
    cin >> arqOrigem;
    cout << "Informe a quantidade de nomes a ler (n): ";
    cin >> n;
    cout << "Informe o nome do arquivo de destino: ";
    cin >> arqDestino;

    ifstream origem(arqOrigem);
    if (!origem) {
        cout << "Erro ao abrir o arquivo de origem!\n";
        return 0;
    }

    Pessoa pessoas[100];
    int lidos = 0;

    for (int i = 0; i < n && getline(origem, pessoas[i].nomeCompleto); i++) {
        pessoas[i].sobreNome = extrairSobrenome(pessoas[i].nomeCompleto);
        lidos++;
    }
    origem.close();

    
    ofstream destino(arqDestino);
    if (!destino) {
        cout << "Erro ao criar o arquivo de destino!\n";
        return 0;
    }

    for (int i = 0; i < lidos; i++) {
        destino << pessoas[i].nomeCompleto << "; " << pessoas[i].sobreNome << endl;
    }
    destino.close();

    cout << "\nDados processados e salvos com sucesso no arquivo de destino!\n";

    return 0;
}