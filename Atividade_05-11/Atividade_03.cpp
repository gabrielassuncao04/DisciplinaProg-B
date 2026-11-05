#include <cstring>
#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao;
} Telefone;

// Função split usando vector
vector<string> split(string frase, string delimitador = ";") {
    vector<string> vetor;
    size_t inicio = 0;
    size_t fim = frase.find(delimitador);
    
    while (fim != string::npos) {
        vetor.push_back(frase.substr(inicio, fim - inicio));
        inicio = fim + delimitador.size();
        fim = frase.find(delimitador, inicio);
    }
    vetor.push_back(frase.substr(inicio));

    return vetor;
}

void carregarDoArquivo(vector<Telefone>& telefones, const string& telefone_list) {
    cout << "[Debug] Tentando abrir o arquivo: " << telefone_list << "\n";
    ifstream telephony_sessions(telefone_list); 

    if (!telephony_sessions.is_open()) {
        cout << "[Aviso] Nao foi possivel abrir o arquivo '" << telefone_list << "'. Comecando com a lista vazia.\n";
        return;
    }

    string linha;
    while (getline(telephony_sessions, linha)) {
        if (linha.empty()) continue;

        // USA O PONTO E VÍRGULA COMO DELIMITADOR AQUI:
        vector<string> partes = split(linha, ";"); 

        if (partes.size() >= 2) {
            Telefone t;
            t.numeroCelular = partes[0]; // Vai pegar exatamente o número antes do ';'
            t.dadosSessao = partes[1];   // Vai pegar o restante (o JSON da sessão)
            telefones.push_back(t); 
        }
    }

    telephony_sessions.close();
    cout << "[Sucesso] Dados carregados do arquivo com sucesso!\n\n";
}

void listar(const vector<Telefone>& telefones) {
    cout << "\n===== Numeros de Telefone =====\n";
    if (telefones.empty()) {
        cout << "Nenhum telefone cadastrado/encontrado.\n";
    } else {
        for (size_t i = 0; i < telefones.size(); i++) {
            cout << "- " << telefones[i].numeroCelular << "\n";
        }
    }
    cout << "===============================\n\n";
}

string buscar(const vector<Telefone>& telefones) {
    string celular;

    cout << "Digite o numero do celular que deseja buscar: ";
    cin >> celular;

    for (size_t i = 0; i < telefones.size(); i++) {
        if (telefones[i].numeroCelular == celular) {
            return telefones[i].dadosSessao;
        }
    }
    
    return "Numero nao encontrado!";
}

int main() {
    cout << "=== INICIANDO O PROGRAMA ===\n";

    vector<Telefone> listaSessoes;
    int opcao;

    carregarDoArquivo(listaSessoes, "telephony_sessions.txt");

    cout << "=== ENTRANDO NO MENU ===\n";

    do {
        cout << "MENU\n";
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone e dados de sessao\n";
        cout << "3 - Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                listar(listaSessoes);
                break;
            case 2: {
                string resultado = buscar(listaSessoes);
                cout << "Resultado: " << resultado << "\n\n";
                break;
            }
            case 3:
                cout << "Obrigado por usar o sistema!\n";
                break;
            default:
                cout << "Opcao invalida!\n\n";
                break;
        }
    } while (opcao != 3);

    return 0;
}