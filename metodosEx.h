#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void solicitar(char palavra[], char &letra) {
    cout << "Informe uma Palavra: ";
    cin >> palavra;
    cout << "Informe a Letra: ";
    cin >> letra;
}

int contador(char letra, char palavra[]) {
    int cont = 0;
    for(int i = 0; i < strlen(palavra); i++) {
        if(palavra[i] == letra) {
            cont++; 
        }
    }
    
    return cont; 
}


void validarData(int dia, int mes, int ano) {

    
    bool valida = true;
    
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) {
        valida = false;
    } else {
        int diasNoMes = 31;
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diasNoMes = 30;
        } else if (mes == 2) {
            bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
            diasNoMes = bissexto ? 29 : 28;
        }
        
        if (dia > diasNoMes) {
            valida = false;
        }
    }
    
    if (valida) {
        cout << "DATA VÁLIDA" << endl;
    } else {
        cout << "DATA INVÁLIDA" << endl;
    }
}


int contarVogais(string frase) {
    int qtd = 0;
    for (size_t i = 0; i < frase.length(); i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            qtd++;
        }
    }
    return qtd;
}

-
string paraMaiuscula(string frase) {
    for (size_t i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool estaOrdenado(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false; 
        }
    }
    return true; 
}

string primeiroNome(string nomeCompleto) {
    string primeiro = "";
    for (size_t i = 0; i < nomeCompleto.length(); i++) {
        if (nomeCompleto[i] == ' ') {
            break; // Para no primeiro espaço
        }
        primeiro += nomeCompleto[i];
    }
    return primeiro;
}