#include <iostream>
#include <string>
#include "metodosEx.h"

using namespace std;

int main() {
    int dia, mes, ano;
    
   
    cout << "Informe o dia: "; 
    cin >> dia;
    
    cout << "Informe o mes: "; 
    cin >> mes;
    
    cout << "Informe o ano: "; 
    cin >> ano;
    
    validarData(dia, mes, ano);
    
    return 0;
}