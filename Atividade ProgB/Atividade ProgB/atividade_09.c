/* 9. Controle de Pontuação de Jogadores
        Contexto: Um campeonato de eSports precisa monitorar o placar.
        
        * Struct: Jogador (ID do Jogador, Pontos).
        * Menu:
        1. Cadastrar jogador.
           2. Buscar jogador por ID: O usuário digita o ID, o programa varre o vetor e mostra os pontos dele (ou diz que não foi encontrado).
           3. Sair.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CAMPEONATO 100

typedef struct {
    char codigo[6]; 
    int pontos;
} Jogador;

int main() {
    Jogador vetorCampeonato[CAMPEONATO];
    int qtd_Jogadores = 0;
    int opcao;

    do {
        printf("\n====+ Campeonato de eSports +====\n");
        printf("1 - Cadastrar Jogador\n");
        printf("2 - Buscar Jogador por ID\n");
        printf("3 - Encerrar\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        printf("=================================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Jogadores >= CAMPEONATO) {
                    printf("Seu Campeonato esta Lotado!!\n");
                    printf("Libere espaco para continuar cadastrando.\n");
                } else {
                    Jogador tempJogador;

                    printf("\n================\n");
                    printf("Cadastro de Jogador\n");
                    printf("================\n");

                    printf("ID do Jogador (max 5 chars): ");
                    scanf("%5s", tempJogador.codigo);

                    printf("Pontuacao do Jogador: ");
                    scanf("%d", &tempJogador.pontos);

                    strcpy(vetorCampeonato[qtd_Jogadores].codigo, tempJogador.codigo);
                    vetorCampeonato[qtd_Jogadores].pontos = tempJogador.pontos;

                    qtd_Jogadores++;

                    printf("Jogador Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                bool encontrou = false;

                if (qtd_Jogadores < 1) {
                    printf("Voce ainda nao tem jogadores cadastrados.\n");
                } else {
                    char idBusca[6];

                    printf("\n--- Busca de Jogador por ID ---\n");
                    printf("Digite o ID do jogador (max 5 chars): ");
                    scanf("%5s", idBusca);
                    printf("--------------------------------\n");

                    for (int i = 0; i < qtd_Jogadores; i++) {
                        if (strcmp(vetorCampeonato[i].codigo, idBusca) == 0) {
                            printf("Jogador Encontrado!\n");
                            printf("ID: %s | Pontos: %d\n", 
                                   vetorCampeonato[i].codigo, 
                                   vetorCampeonato[i].pontos);
                            encontrou = true;
                            break;
                        }
                    }

                    if (!encontrou) {
                        printf("Jogador com ID '%s' nao foi encontrado.\n", idBusca);
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