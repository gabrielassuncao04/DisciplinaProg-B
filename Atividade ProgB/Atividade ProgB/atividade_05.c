/* 5. Catálogo de Carros Usados (Filtro por Valor)
        Contexto: Uma concessionária quer ajudar clientes a encontrar carros por preço.
        
        * Struct: Carro (Código, Ano, Preço).
        * Menu:
        1. Cadastrar carro.
           2. Buscar por preço: O usuário digita um valor máximo, e o programa mostra todos os carros mais baratos que esse valor.
           3. Sair.*/

           #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GARAGEM 100

typedef struct {
    char codigo[6]; 
    int ano;
    float preco;
} Carro;

int main() {
    Carro vetorGaragem[GARAGEM];
    int qtd_Carros = 0;
    int opcao;

    do {
        printf("\n====+ Concessionaria de Carros +====\n");
        printf("1 - Cadastrar Carro\n");
        printf("2 - Buscar por Preco\n");
        printf("3 - Encerrar\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        printf("====================================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Carros >= GARAGEM) {
                    printf("Sua Garagem esta Lotada!!\n");
                    printf("Libere espaco para continuar cadastrando.\n");
                } else {
                    Carro tempCarros;

                    printf("\n================\n");
                    printf("Cadastro de Carro\n");
                    printf("================\n");

                    printf("Codigo do Carro (max 5 chars): ");
                    scanf("%5s", tempCarros.codigo);

                    printf("Ano do Carro: ");
                    scanf("%d", &tempCarros.ano);

                    printf("Preco do Carro (R$): ");
                    scanf("%f", &tempCarros.preco);

                    strcpy(vetorGaragem[qtd_Carros].codigo, tempCarros.codigo);
                    vetorGaragem[qtd_Carros].ano = tempCarros.ano;
                    vetorGaragem[qtd_Carros].preco = tempCarros.preco;

                    qtd_Carros++;

                    printf("Carro Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                bool encontrou = false;

                if (qtd_Carros < 1) {
                    printf("Voce ainda nao tem carros cadastrados.\n");
                } else {
                    float precoMaximo;

                    printf("\n--- Busca de Carros por Preco ---\n");
                    printf("Digite o valor maximo desejado (R$): ");
                    scanf("%f", &precoMaximo);
                    printf("---------------------------------\n");

                    for (int i = 0; i < qtd_Carros; i++) {
                        if (vetorGaragem[i].preco <= precoMaximo) {
                            printf("Codigo: %s | Ano: %d | Preco: R$ %.2f\n",
                                   vetorGaragem[i].codigo,
                                   vetorGaragem[i].ano,
                                   vetorGaragem[i].preco);
                            encontrou = true;
                        }
                    }

                    if (!encontrou) {
                        printf("Nenhum carro encontrado abaixo de R$ %.2f.\n", precoMaximo);
                    }
                }
                break;
            }

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida, tente novamente...\n");
                break;
        }

    } while (opcao != 3);

    return 0;
}