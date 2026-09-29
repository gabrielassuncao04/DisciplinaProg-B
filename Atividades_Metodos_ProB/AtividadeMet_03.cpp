#include <iostream>
#include <string>
#include "metodosEx.h" 

using namespace std;

int main() {
    string frase;

    cout << "Informe uma frase: ";
    getline(cin, frase); 
    
    int qtdVogais = contarVogais(frase);
    
    cout << "A frase informada tem " << qtdVogais << " vogal(is)." << endl;
    
    return 0;
}