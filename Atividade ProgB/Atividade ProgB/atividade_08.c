/* 8. Gestão de Consumo de Energia
        Contexto: Uma empresa de energia quer identificar residências com alto consumo.
        
        * Struct: Imóvel (Número da Casa, Consumo kWh).
        * Menu:
        1. Cadastrar imóvel.
           2. Calcular a média de consumo geral da rua.
           3. Listar imóveis que consomem acima da média calculada.
           4. Sair.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define RUA 100

typedef struct {
    char codigo[6]; 
    float consumo_kwh;
} Imovel;

int main() {
    Imovel vetorRua[RUA];
    int qtd_Imoveis = 0;
    int opcao;

    do {
        printf("\n====+ Gestao de Consumo de Energia +====\n");
        printf("1 - Cadastrar Imovel\n");
        printf("2 - Calcular Media de Consumo Geral\n");
        printf("3 - Listar Imoveis Acima da Media\n");
        printf("4 - Encerrar\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        printf("=========================================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Imoveis >= RUA) {
                    printf("Sua Rua esta Lotada!!\n");
                    printf("Libere espaco para continuar cadastrando.\n");
                } else {
                    Imovel tempImovel;

                    printf("\n================\n");
                    printf("Cadastro de Imovel\n");
                    printf("================\n");

                    printf("Numero da Casa (max 5 chars): ");
                    scanf("%5s", tempImovel.codigo);

                    printf("Consumo (kWh): ");
                    scanf("%f", &tempImovel.consumo_kwh);

                    strcpy(vetorRua[qtd_Imoveis].codigo, tempImovel.codigo);
                    vetorRua[qtd_Imoveis].consumo_kwh = tempImovel.consumo_kwh;

                    qtd_Imoveis++;

                    printf("Imovel Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                if (qtd_Imoveis < 1) {
                    printf("Voce ainda nao tem imoveis cadastrados.\n");
                } else {
                    float soma = 0;
                    for (int i = 0; i < qtd_Imoveis; i++) {
                        soma += vetorRua[i].consumo_kwh;
                    }

                    float media = soma / qtd_Imoveis;

                    printf("\n--- Media de Consumo Geral ---\n");
                    printf("A media de consumo da rua e: %.2f kWh\n", media);
                }
                break;
            }

            case 3: {
                if (qtd_Imoveis < 1) {
                    printf("Voce ainda nao tem imoveis cadastrados.\n");
                } else {
                    float soma = 0;
                    for (int i = 0; i < qtd_Imoveis; i++) {
                        soma += vetorRua[i].consumo_kwh;
                    }

                    float media = soma / qtd_Imoveis;
                    bool encontrou = false;

                    printf("\n--- Imoveis com Consumo Acima da Media (%.2f kWh) ---\n", media);
                    for (int i = 0; i < qtd_Imoveis; i++) {
                        if (vetorRua[i].consumo_kwh > media) {
                            printf("Numero da Casa: %s | Consumo: %.2f kWh\n",
                                   vetorRua[i].codigo,
                                   vetorRua[i].consumo_kwh);
                            encontrou = true;
                        }
                    }

                    if (!encontrou) {
                        printf("Nenhum imovel cadastrado possui consumo acima da media.\n");
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