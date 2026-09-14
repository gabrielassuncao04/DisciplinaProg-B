/*Construa um programa (com módulo/método) que leia n nomes
 completos de pessoas e os exiba na tela;*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void SelecArquivo(string &nomeArquivo, ofstream &procuradorArquivo){
    cout << "Informe o Nome do Arquivo que recebera os nomes (ex: nomes.txt): ";
    cin >> nomeArquivo;
    cin.ignore(); 
    
    procuradorArquivo.open(nomeArquivo);
    if(!procuradorArquivo){
        cout << "Erro ao criar ou abrir o arquivo. Encerrando Programa\n";
        exit(0); 
    }
}

void Escrever(ofstream &procuradorArquivo){
    string nome;
    while (true){
        cout << "Digite um nome completo para guardar no arquivo (ou 'fim' para encerrar): ";
        getline(cin, nome);

        if (nome == "fim" || nome == "FIM" || nome == "Fim"){
            break;
        }
        
        
        procuradorArquivo << nome << endl;
    }
    
    procuradorArquivo.close(); 
    cout << "Arquivo fechado e nomes salvos com sucesso!\n";
}

int main(){
    string nomeArquivo;
    ofstream procuradorArquivo;
    
    cout << "== Gravador de Nomes em Arquivo ==\n";

    SelecArquivo(nomeArquivo, procuradorArquivo);
    Escrever(procuradorArquivo);

    return 0;
}   


