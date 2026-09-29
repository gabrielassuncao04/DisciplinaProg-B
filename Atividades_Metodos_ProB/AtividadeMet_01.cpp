#include <iostream>
#include <cstdlib>
#include <cstring>

#include "metodosEx.h"

using namespace std;

int main (){
    char palavra[100];
    char letra;
    
    solicitar(palavra, letra);
    cout << "A letra aparece " << contador(letra, palavra) << " vez(es)." << endl;
    
    return 0;
}

