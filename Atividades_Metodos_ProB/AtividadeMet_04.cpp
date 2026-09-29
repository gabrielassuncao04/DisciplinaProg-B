#include <iostream>
#include <string>
#include "metodosEx.h" 

using namespace std;

int main() {
    string frase;
    
    cout << "--- Exercicio 3: Frase em Maiuscula ---" << endl;
    cout << "Informe uma frase: ";
    getline(cin, frase); 
    
    string fraseMaiuscula = paraMaiuscula(frase);
    
    cout << "Frase original: " << frase << endl;
    cout << "Frase em maiuscula: " << fraseMaiuscula << endl;
    
    return 0;
}