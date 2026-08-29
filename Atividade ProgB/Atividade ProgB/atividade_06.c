  /*6. Relatório de Altura e Peso (Maior e Menor)
        Contexto: Uma academia está avaliando o perfil físico dos alunos.
        
        * Struct: Perfil (Código, Peso, Altura).
        * Menu:
        1. Cadastrar aluno.
           2. Exibir o aluno mais alto cadastrado até o momento (busca de maior valor).
           3. Sair.*/

           #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ACADEMIA 100

typedef struct {
    char codigo[6]; 
    float peso;
    float altura;
} Perfil;

int main() {
    Perfil vetorAcademia[ACADEMIA];
    int qtd_Alunos = 0;
    int opcao;

    do {
        printf("\n====+ Sistema de Academia +====\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Exibir o Aluno Mais Alto\n");
        printf("3 - Encerrar\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao);
        printf("=================================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Alunos >= ACADEMIA) {
                    printf("Sua Academia está Lotada!!\n");
                    printf("Libere espaço para continuar cadastrando.\n");
                } else {
                    Perfil tempAlunos;

                    printf("\n================\n");
                    printf("Cadastro de Aluno\n");
                    printf("================\n");

                    printf("Código do Aluno (máx 5 chars): ");
                    scanf("%5s", tempAlunos.codigo);

                    printf("Peso do Aluno (kg): ");
                    scanf("%f", &tempAlunos.peso);

                    printf("Altura do Aluno (m): ");
                    scanf("%f", &tempAlunos.altura);

                    strcpy(vetorAcademia[qtd_Alunos].codigo, tempAlunos.codigo);
                    vetorAcademia[qtd_Alunos].peso = tempAlunos.peso;
                    vetorAcademia[qtd_Alunos].altura = tempAlunos.altura;

                    qtd_Alunos++;

                    printf("Aluno Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                if (qtd_Alunos < 1) {
                    printf("Você ainda não tem alunos cadastrados.\n");
                } else {
                    int indiceMaisAlto = 0;

                    for (int i = 1; i < qtd_Alunos; i++) {
                        if (vetorAcademia[i].altura > vetorAcademia[indiceMaisAlto].altura) {
                            indiceMaisAlto = i;
                        }
                    }

                    printf("\n--- Aluno Mais Alto Cadastrado ---\n");
                    printf("Código: %s | Peso: %.2f kg | Altura: %.2f m\n",
                           vetorAcademia[indiceMaisAlto].codigo,
                           vetorAcademia[indiceMaisAlto].peso,
                           vetorAcademia[indiceMaisAlto].altura);
                }
                break;
            }

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida, tente novamente...\n");
                break;
        }

    } while (opcao != 3);

    return 0;
}