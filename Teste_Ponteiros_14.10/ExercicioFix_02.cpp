//2) construa um método chamado exercicio2 que receba como parâmetros:
//   - vetorA - com n numeros sorteados
//    - vetorB - com n numeros sorteados
//    - vetorResultado - que vai armazenar todos os números que aparecem nos dois vetores

//    ao final, o vetorResultado deve ter seus dados retornados.

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void inicializarVetor(vector<int> &va, vector<int> &vb, int qtd, int valor) {
    for (int i = 0; i < qtd; i++) {
        va.push_back(valor);
    }

    for (int i = 0; i < qtd; i++) {
        vb.push_back(valor);
    }
}

void popularVetor(vector<int> &va, vector<int> &vb, int qtd, int inicio, int fim) {
    srand(static_cast<unsigned int>(time(NULL)));
    int numero;
    
    for (int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        va.push_back(numero);
    }

    for (int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        vb.push_back(numero);
    }
}

void Resultado(const vector<int> &va, const vector<int> &vb, vector<int> &r) {
    for (size_t i = 0; i < va.size(); i++) {
        if (va[i] == vb[i]) { 
            r.push_back(va[i]); 
        }
    }

    cout << "Vetor Resultado (Numeros iguais na mesma posicao):\n";
    for (size_t i = 0; i < r.size(); i++) {
        cout << r[i] << "\t";
    }
    cout << "\n\n";
}

int main() {
    vector<int> vetora;
    vector<int> vetorb;
    
    popularVetor(vetora, vetorb, 10, 100, 500);
   
    vector<int> resultado;
    
    Resultado(vetora, vetorb, resultado);

    return 1; 
}


