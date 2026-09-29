#include <iostream>
#include "metodosEx.h" 

using namespace std;

int main() {
    
    int vetorOrdenado[] = {2, 5, 8, 12, 20};
    int tamanho1 = 5;
    
    int vetorDesordenado[] = {10, 3, 7, 1, 15};
    int tamanho2 = 5;
    
    cout << "\nTestando o primeiro vetor {2, 5, 8, 12, 20}:" << endl;
    if (estaOrdenado(vetorOrdenado, tamanho1)) {
        cout << "Resultado: true" << endl;
    } else {
        cout << "Resultado: false" << endl;
    }
    
    cout << "\nTestando o segundo vetor {10, 3, 7, 1, 15}:" << endl;
    if (estaOrdenado(vetorDesordenado, tamanho2)) {
        cout << "Resultado: true" << endl;
    } else {
        cout << "Resultado: false" << endl;
    }
    
    return 0;
}