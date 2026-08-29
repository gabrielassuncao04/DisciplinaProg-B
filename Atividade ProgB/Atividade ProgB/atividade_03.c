/* 3. Diário de Notas Acadêmicas
        Contexto: Um professor precisa calcular médias da turma.
        
        * Struct: Aluno (Matrícula, Nota 1, Nota 2).
        * Menu:
        1. Cadastrar aluno e suas duas notas.
           2. Listar alunos mostrando a matrícula e a média aritmética das duas notas.
           3. Sair.*/

/* 3. Diário de Notas Acadêmicas */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
    float n1;
    float n2;
} Aluno;

int main() {
    Aluno vetorAluno[MAX_ALUNOS];
    int qtd_alunos = 0, opcao;
    
    do {
        printf("\n==========\n");
        printf("===MENU===\n");
        printf("==========\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Alunos\n");
        printf("3 - Sair\n");
        printf("Digite uma opção ==> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (qtd_alunos < MAX_ALUNOS) {
                    int matricula;
                    float n1, n2;

                    printf("\nDigite a matricula do Aluno: ");
                    scanf("%d", &matricula);
                    printf("Digite a Primeira Nota: ");
                    scanf("%f", &n1);
                    printf("Digite a Segunda Nota: ");
                    scanf("%f", &n2);

                    vetorAluno[qtd_alunos].matricula = matricula;
                    vetorAluno[qtd_alunos].n1 = n1;
                    vetorAluno[qtd_alunos].n2 = n2;
                    qtd_alunos++;

                    printf("Aluno Cadastrado com Sucesso!\n");
                } else {
                    printf("Limite de Alunos Cadastrados excedido!\n");
                }
                break;

            case 2: {
                float media;
                if (qtd_alunos > 0) {
                    for (int i = 0; i < qtd_alunos; i++) {
                        printf("\n=============\n");
                        printf("    Aluno %d\n", i + 1);
                        printf("=============\n");
                        printf("Matricula: %d\n", vetorAluno[i].matricula);
                        printf("Nota 01: %.2f\n", vetorAluno[i].n1);
                        printf("Nota 02: %.2f\n", vetorAluno[i].n2);
                        
                        media = (vetorAluno[i].n1 + vetorAluno[i].n2) / 2.0;
                        printf("Media: %.2f\n", media);

                        if (media >= 6) {
                            printf("Situação: Aprovado\n");
                        } else {
                            printf("Situação: Reprovado\n");
                        }
                    }
                } else {
                    printf("Você não tem alunos registrados.\n");
                }
                break;
            }

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida, tente novamente...\n");
                break;
        }
        
    } while (opcao != 3);

    return 0;
}
