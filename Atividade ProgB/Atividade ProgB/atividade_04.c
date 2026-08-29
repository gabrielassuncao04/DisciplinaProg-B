 /* 4. Gerenciador de Biblioteca
        Contexto: Uma biblioteca comunitária quer catalogar seus livros.
        
        * Struct: Livro (Código, Ano de Publicação, Páginas).
        * Menu:
        1. Cadastrar livro.
           2. Filtrar livros: Exibir apenas os livros publicados após o ano 2020.
           3. Sair.*/

/* 4. Gerenciador de Biblioteca */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIVRARIA 100

typedef struct {
    char codigo[6]; // Space for 5 characters + '\0'
    int ano_publi;
    int n_pg;
} Publicacao;

int main() {
    Publicacao vetorLivraria[LIVRARIA];
    int qtd_Livros = 0; 
    int opcao;

    do {
        printf("\n====+ Sistema de Biblioteca +====\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Listar Livros Publicados após 2020\n");
        printf("3 - Encerrar\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao);
        printf("=================================\n");

        switch (opcao) {
            case 1: { 
                if (qtd_Livros >= LIVRARIA) {
                    printf("Sua Biblioteca está Lotada!!\n");
                    printf("Libere espaço para continuar cadastrando.\n");
                } else {
                    Publicacao tempLivros;

                    printf("\n================\n");
                    printf("Cadastro de Livro\n");
                    printf("================\n");
                    
                    printf("Código do Livro (máx 5 chars): ");
                    scanf("%5s", tempLivros.codigo);
                    
                    printf("Ano de Publicação: ");
                    scanf("%d", &tempLivros.ano_publi);
                    
                    printf("Número de Páginas: ");
                    scanf("%d", &tempLivros.n_pg);

                    strcpy(vetorLivraria[qtd_Livros].codigo, tempLivros.codigo);
                    vetorLivraria[qtd_Livros].ano_publi = tempLivros.ano_publi;
                    vetorLivraria[qtd_Livros].n_pg = tempLivros.n_pg;
                    
                    qtd_Livros++;

                    printf("Livro Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                bool encontrou = false;

                if (qtd_Livros < 1) {
                    printf("Você ainda não tem livros cadastrados.\n");
                } else {
                    printf("\n--- Livros Publicados Após 2020 ---\n");
                    for (int i = 0; i < qtd_Livros; i++) {
                        if (vetorLivraria[i].ano_publi > 2020) {
                            printf("Código: %s | Ano: %d | Páginas: %d\n", 
                                   vetorLivraria[i].codigo, 
                                   vetorLivraria[i].ano_publi, 
                                   vetorLivraria[i].n_pg);
                            encontrou = true;
                        }
                    }

                    if (!encontrou) {
                        printf("Nenhum livro cadastrado com publicação após 2020.\n");
                    }
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