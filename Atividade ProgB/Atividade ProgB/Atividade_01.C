/*
    ### 1. Cadastro de Clientes Simplificado
    Contexto: Uma loja precisa registrar seus clientes.
    
    * Struct: Cliente (Código, Idade, Telefone).
    * Menu:
        1. Cadastrar cliente (inserir no vetor).
        2. Listar todos os clientes cadastrados.
        3. Sair.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 100

typedef struct {
    int codigo;
    int idade;
    char telefone[20];
} Cliente;

int main() {
    Cliente vetorClientes[MAX_CLIENTES];
    int opcao, quantidadeClientes = 0;

    do {
        // system("cls"); // Limpa a tela (funciona no Windows)
        printf("Menu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                printf("Cadastro de cliente:\n");
                if (quantidadeClientes == MAX_CLIENTES) {
                    printf("Nao ha espaco na base para mais clientes... \n");
                } else {
                    int codigo, idade;
                    char telefone[20];

                    printf("Informe o codigo do cliente: ");
                    scanf("%d", &codigo);
                    printf("Informe sua idade: ");
                    scanf("%d", &idade);
                    printf("Informe seu telefone: ");
                    scanf("%s", telefone);

                    vetorClientes[quantidadeClientes].codigo = codigo;
                    vetorClientes[quantidadeClientes].idade = idade;
                    strcpy(vetorClientes[quantidadeClientes].telefone, telefone);
                    printf("Cliente cadastrado com sucesso\n");
                    quantidadeClientes++;
                }
                break;
            case 2: 
                printf("Clientes cadastrados:\n");
                if (quantidadeClientes == 0) {
                    printf("Nao ha clientes para exibir\n");
                } else {
                    for (int i = 0; i < quantidadeClientes; i++) {
                        printf("Codigo: %d\n", vetorClientes[i].codigo);
                        printf("Idade: %d\n", vetorClientes[i].idade);
                        printf("Telefone: %s\n", vetorClientes[i].telefone);
                        printf("-----------------------------------\n\n");
                    } 
                }
                break;
            case 3: 
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        // system("pause"); // Pausa para o usuário ler a mensagem
    } while (opcao != 3);
}