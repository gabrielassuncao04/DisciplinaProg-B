#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int main() {
    int opcao;
    int vetor[TAMANHO];
    int qtd_elementos = 0;
    srand(time(NULL));

    do {
        system("cls");
        printf("MENU PRINCIPAL\n");
        printf("1 - Popular vetor com numeros aleatorios\n");
        printf("2 - Listar vetor populado\n");
        printf("3 - Ordenar vetor\n");
        printf("4 - Calcular média aritmética\n");
        printf("5 - Calcular mediana\n");
        printf("6 - Exibir Maior e Menor valor do vetor\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Populando o vetor com numeros aleatorios\n");
                for (int i = 0; i < TAMANHO; i++) {
                    vetor[i] = rand() % 100;
                }
                qtd_elementos = TAMANHO;
                break;

            case 2:
                printf("Listando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0) {
                    for (int i = 0; i < TAMANHO; i++) {
                        printf("%d\t", vetor[i]);
                    }
                    printf("\n");
                } else {
                    printf("Vetor vazio. Nada a exibir\n");
                }
                break;

            case 3:
                printf("Ordenando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0) {
                    int temp, trocou;
                    for (int i = 0; i < TAMANHO - 1; i++) {
                        trocou = 0;
                        for (int j = 0; j < TAMANHO - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                                trocou = 1;
                            }
                        }
                        if (trocou == 0) {
                            break;
                        }
                    }
                    printf("Vetor ordenado com sucesso!\n");
                } else {
                    printf("Vetor vazio. Nada a ordenar\n");
                }
                break;

            case 4:
                if (qtd_elementos > 0) {
                    printf("Calcular Media\n");
                    int soma = 0;
                    for (int i = 0; i < TAMANHO; i++) {
                        soma += vetor[i];
                    }
                    printf("A Media deste vetor e %.1f\n", (float)soma / TAMANHO);
                } else {
                    printf("Vetor Vazio, Nada a exibir\n");
                }
                break;

            case 5:
                if (qtd_elementos > 0) {
                    // Verificação de segurança completa para ordenação
                    int ordenado = 1;
                    for (int i = 0; i < TAMANHO - 1; i++) {
                        if (vetor[i] > vetor[i + 1]) {
                            ordenado = 0;
                            break;
                        }
                    }

                    if (ordenado) {
                        printf("Calculando Mediana\n");
                        float mediana = (float)(vetor[4] + vetor[5]) / 2;
                        printf("O valor equivalente a mediana deste vetor e %.1f\n", mediana);
                    } else {
                        printf("Vetor desordenado! Por favor, ordene o vetor primeiro (Opcao 3).\n");
                    }
                } else {
                    printf("Vetor Vazio, Nada a exibir\n");
                }
                break;

            case 6:
                if (qtd_elementos > 0) {
                    // Verificação de segurança completa para ordenação
                    int ordenado = 1;
                    for (int i = 0; i < TAMANHO - 1; i++) {
                        if (vetor[i] > vetor[i + 1]) {
                            ordenado = 0;
                            break;
                        }
                    }

                    if (ordenado) {
                        printf("Encontrar maior e menor numero do vetor\n");
                        printf("O menor valor do vetor e %d\n", vetor[0]);
                        printf("O maior valor do vetor e %d\n", vetor[9]);
                    } else {
                        printf("Vetor desordenado! Por favor, ordene o vetor primeiro (Opcao 3).\n");
                    }
                } else {
                    printf("Vetor Vazio, Nada a exibir\n");
                }
                break;

            case 7:
                printf("Sistema encerrado\n");
                break;

            default:
                printf("Opcao invalida. Redigite\n");
                break;
        }
        system("pause");
    } while (opcao != 7);

    return 0;
}