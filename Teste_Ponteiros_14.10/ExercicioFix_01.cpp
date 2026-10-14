//1) Construa um método chamado exercicio1 que receba um parametro:
// vetorA - com n numeros sorteados
// vetorB - com n numero sorteados
// Exiba os numeros que aparecem nos dois vetores 

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void inicializarVetor(vector<int> &v, int qtd, int valor) {
    for (int i = 0; i < qtd; i++) {
        v.push_back(valor);
    }
}

void exibirVetor(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << "\n\n";
}

void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    srand(static_cast<unsigned int>(time(NULL)));
    int numero;
    for (int i = 0; i < qtd; i++) {
        
        numero = (rand() % (fim - inicio + 1)) + inicio;
        v.push_back(numero);
    }
}

void NumerosIguais(const vector<int> &v, vector<int> &igual) {
    
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[i] == v[j]) {
                
                igual.push_back(v[i]);
            }
        }
    }

    cout << "Numeros repetidos encontrados:\n";
    for (int i = 0; i < igual.size(); i++) {
        cout << igual[i] << "\t";
    }
    cout << "\n\n";
}

int main() {
    vector<int> vetor;
    
    popularVetor(vetor, 10, 100, 500);
    cout << "Exibindo vetor.... \n";
    exibirVetor(vetor);

    vector<int> iguais;
    NumerosIguais(vetor, iguais);

    return 0; 
}


