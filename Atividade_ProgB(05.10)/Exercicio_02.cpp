/*2) construir um metodo que recebe uma data no formato dd/mm/aaaa e retorna se a data é válida, 
porém, avaliando a quantidade de digitos obrigatórios (10 caracteres)*/

#include<iostream>
#include<string>

void LeitorData (string &data){
    cout << "Digite a Data:"
    cin << data;
}

bool Contador (string data){
    int tamanho = 0;

    for (int i = 0; i < data.legth();i++){
        if(data[i] != '/'){
            tamanho++;
        }
    }

    if (tamanho < 10){
        return false;
    }else{
        return true
    }
}

int main (){
    string data;

    cout << "+++ Validar Data +++"

    LeitorData(data);

    if(contador(&data) = true){
        cout << "Valor Valido";
    }else{
        cout << "Valor Invalido";
    }
return 0;
}

