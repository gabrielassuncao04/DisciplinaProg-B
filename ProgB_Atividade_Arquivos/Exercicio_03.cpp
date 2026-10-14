/*Construa um programa (com módulo/método) que leia n nomes de pessoas DE UM ARQUIVO DE ORIGEM, armazena em um vetor de nomes e os exiba na tela. Porém, é necessário GRAVAR ESSES 
NOMES JUNTAMENTE COM A QUANTIDADE DE CARACTERES EM UM ARQUIVO DESTINO.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string arqOrigem, arqDestino;
    
    cout << "Informe o nome do arquivo de origem: ";
    cin >> arqOrigem;
    cout << "Informe o nome do arquivo de destino: ";
    cin >> arqDestino;

    ifstream origem(arqOrigem);
    if (!origem) {
        cout << "Erro ao abrir o arquivo de origem!\n";
        return 0;
    }

    ofstream destino(arqDestino);
    if (!destino) {
        cout << "Erro ao criar o arquivo de destino!\n";
        return 0;
    }

    string nomes[100];
    int qtdCaracteres[100];
    int total = 0;

    string linha;
    while (getline(origem, linha) && total < 100) {
        nomes[total] = linha;
        qtdCaracteres[total] = linha.length();
        total++;
    }
    origem.close();

    
    cout << "\n=== Nomes e Quantidade de Caracteres ===\n";
    for (int i = 0; i < total; i++) {
    
        cout << "Nome: " << nomes[i] << " | Caracteres: " << qtdCaracteres[i] << endl;
        
      
        destino << nomes[i] << " - " << qtdCaracteres[i] << " caracteres" << endl;
    }

    destino.close();
    cout << "\nArquivo de destino gerado com sucesso!\n";

    return 0;
}