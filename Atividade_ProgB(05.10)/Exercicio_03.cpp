/*3) construir um método que recebe um nome completo e retorna o email desse nome, obedecendo a seguinte regra:
primeiroNome.ultimoNome@ufn.edu.br.*/

#include <iostream>
#include <string>

using namespace std;

void LeitorNome(string &nome, string &sobrenome) {
    cout << "Digite seu nome: ";
    cin >> nome;

    cout << "Digite seu sobrenome: ";
    cin >> sobrenome;
}

string FormarEmail(string nome, string sobrenome) {
    return nome + "." + sobrenome + "@ufn.edu.br";
}

int main() {
    string nome, sobrenome;

    LeitorNome(nome, sobrenome);
    cout << "Seu e-mail: " << FormarEmail(nome, sobrenome) << "\n";

    return 0;
}
