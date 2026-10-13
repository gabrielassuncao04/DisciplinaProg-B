/*2- Construa um programa (com módulo/método) que leia n 
nomes completos de pessoas e os adicione em um vetor 
de n posicoes em que deve ser armazenado o 
nome completo e o sobrenome. Use a seguinte estrutura;*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
} Pessoa;


string extrairSobrenome(string nomeCompleto) {
    size_t ultimaPosicao = nomeCompleto.find_last_of(' ');
    
   
    if (ultimaPosicao == string::npos) {
        return ""; 
    }
    
   
    return nomeCompleto.substr(ultimaPosicao + 1);
}


void lerPessoas(vector<Pessoa> &pessoas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome completo da " << i + 1 << "ª pessoa: ";
        getline(cin, pessoas[i].nomeCompleto);
        
       
        pessoas[i].sobreNome = extrairSobrenome(pessoas[i].nomeCompleto);
    }
}

void exibirPessoas(const vector<Pessoa> &pessoas) {
    cout << "\n=== Pessoas e Sobrenomes Cadastrados ===\n";
    for (size_t i = 0; i < pessoas.size(); i++) {
        cout << "Registro " << i + 1 << ":\n";
        cout << "  - Nome Completo: " << pessoas[i].nomeCompleto << "\n";
        cout << "  - Sobrenome:     " << pessoas[i].sobreNome << "\n";
        cout << "----------------------------------------\n";
    }
}

int main() {
    int n;
    
    cout << "Informe a quantidade de pessoas (n): ";
    cin >> n;
    cin.ignore(); 

    
    vector<Pessoa> pessoas(n);


    lerPessoas(pessoas, n);
    exibirPessoas(pessoas);

    return 0;
}
