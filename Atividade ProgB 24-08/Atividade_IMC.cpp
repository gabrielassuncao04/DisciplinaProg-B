/**
    Fazer um programa que armazene N dados de pessoas em um vetor (ou vector), contendo nome, altura (metros) e peso (kg).    
**/
#include <limits>
#include <iostream> //equivalente ao stdio.h do C
#include <string>   //equivalente ao string.h do C
#include <vector>

using namespace std;

#include "meusTipos.h"

int main() {
    IndiceMassaCorporal pessoaTMP;
    vector<IndiceMassaCorporal> atletas;
    int quantidadeAtletas;

    cout << "Quantos atletas quer monitorar o IMC? ";
    cin >> quantidadeAtletas;
    
    // LIMPEZA AQUI: Limpa o '\n' deixado pela leitura da quantidade de atletas
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //rotina de persistencia em RAM
    for (int i = 0; i < quantidadeAtletas; i++ ) {
        cout << "Nome atleta: ";
        getline(cin, pessoaTMP.nome);

        do {
            cout << "Altura (m) : ";
            cin >> pessoaTMP.altura;
            if (pessoaTMP.altura < 0.30 || pessoaTMP.altura > 2.70) {
                cout << "Altura invalida. Redigite.....\n";
            }
        } while (pessoaTMP.altura < 0.30 || pessoaTMP.altura > 2.70);

        cout << "Peso (kg)   :";
        cin >> pessoaTMP.peso;

       pessoaTMP.imc = pessoaTMP.peso / (pessoaTMP.altura * pessoaTMP.altura);

        // LIMPEZA AQUI: Limpa o '\n' deixado pela leitura do peso antes do próximo getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        atletas.push_back( pessoaTMP );
    }
    
    //rotina de calculo do IMC = peso / (altura × altura)
    float imc;
    
    for (int i = 0; i < atletas.size(); i++) {
        cout << "Nome atleta: " << atletas[i].nome << endl;
        cout << "IMC        : " << atletas[i].imc << endl;
        cout << "===================" << endl;
    }

    return 1;
}

