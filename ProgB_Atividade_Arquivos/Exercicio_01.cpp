//Construa um programa (com módulo/método) que leia n nomes 
//completos de pessoas DE UM ARQUIVO DE ORIGEM e os exiba na tela;

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void lerMostrarArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo de origem!\n";
        return;
    }
    
    string linha;
    cout << "\n=== Nomes lidos do arquivo ===\n";
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
    
    arquivo.close();
}

int main() {
    string nomeArquivo;
    
    cout << "Informe o nome do arquivo de origem (ex: origem.txt): ";
    cin >> nomeArquivo;
    
    lerMostrarArquivo(nomeArquivo);

    return 0;
}
