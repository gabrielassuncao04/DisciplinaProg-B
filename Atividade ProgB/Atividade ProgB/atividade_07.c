 /* 7. Conta Bancária Simplificada (Alteração de Dados)
        Contexto: Um banco precisa atualizar saldos.
        
        * Struct: Conta (Número da Conta, Saldo).
        * Menu:
        1. Cadastrar conta (saldo inicial).
           2. Depositar: O usuário escolhe uma posição do vetor (índice) e soma um valor ao saldo existente.
           3. Mostrar todas as contas.
           4. Sair.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BANCO 100

typedef struct {
    char codigo[6]; 
    float saldo;
} Conta;

int main() {
    Conta vetorBanco[BANCO];
    int qtd_Contas = 0;
    int opcao;

    do {
        printf("\n====+ Sistema Bancario +====\n");
        printf("1 - Cadastrar Conta\n");
        printf("2 - Depositar em uma Conta\n");
        printf("3 - Mostrar todas as Contas\n");
        printf("4 - Encerrar\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        printf("============================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Contas >= BANCO) {
                    printf("Seu Banco esta Lotado!!\n");
                    printf("Libere espaco para continuar cadastrando.\n");
                } else {
                    Conta tempContas;

                    printf("\n================\n");
                    printf("Cadastro de Conta\n");
                    printf("================\n");

                    printf("Numero da Conta (max 5 chars): ");
                    scanf("%5s", tempContas.codigo);

                    printf("Saldo Inicial (R$): ");
                    scanf("%f", &tempContas.saldo);

                    strcpy(vetorBanco[qtd_Contas].codigo, tempContas.codigo);
                    vetorBanco[qtd_Contas].saldo = tempContas.saldo;

                    qtd_Contas++;

                    printf("Conta Cadastrada com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                if (qtd_Contas < 1) {
                    printf("Voce ainda nao tem contas cadastradas.\n");
                } else {
                    int indice;
                    float valorDeposito;

                    printf("\n--- Deposito em Conta ---\n");
                    printf("Digite a posicao da conta (0 ate %d): ", qtd_Contas - 1);
                    scanf("%d", &indice);

                    if (indice >= 0 && indice < qtd_Contas) {
                        printf("Digite o valor para deposito (R$): ");
                        scanf("%f", &valorDeposito);

                        if (valorDeposito > 0) {
                            vetorBanco[indice].saldo += valorDeposito;
                            printf("Deposito realizado com sucesso!\n");
                            printf("Novo saldo da conta %s: R$ %.2f\n", 
                                   vetorBanco[indice].codigo, 
                                   vetorBanco[indice].saldo);
                        } else {
                            printf("Valor invalido para deposito.\n");
                        }
                    } else {
                        printf("Posicao invalida! Tente novamente.\n");
                    }
                }
                break;
            }

            case 3: {
                if (qtd_Contas < 1) {
                    printf("Voce ainda nao tem contas cadastradas.\n");
                } else {
                    printf("\n--- Relatorio de Contas Cadastradas ---\n");
                    for (int i = 0; i < qtd_Contas; i++) {
                        printf("Posicao [%d] -> Conta: %s | Saldo: R$ %.2f\n",
                               i,
                               vetorBanco[i].codigo,
                               vetorBanco[i].saldo);
                    }
                }
                break;
            }

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida, tente novamente...\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}