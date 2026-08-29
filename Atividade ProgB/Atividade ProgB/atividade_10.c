/*10. Sistema de RH (Filtro Condicional Duplo)
        Contexto: O departamento de recursos humanos quer analisar a folha de pagamento.
        
        * Struct: Funcionario (Código, Idade, Salário).
        * Menu:
        1. Cadastrar funcionário.
           2. Contar e exibir quantos funcionários têm mais de 40 anos e ganham mais de R$ 5.000,00.
           3. Sair.*/

           #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPRESA 100

typedef struct {
    char codigo[6]; 
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario vetorEmpresa[EMPRESA];
    int qtd_Funcionarios = 0;
    int opcao;

    do {
        printf("\n====+ Sistema de RH +====\n");
        printf("1 - Cadastrar Funcionario\n");
        printf("2 - Contar Funcionarios (> 40 anos e > R$ 5000,00)\n");
        printf("3 - Encerrar\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        printf("=========================\n");

        switch (opcao) {
            case 1: {
                if (qtd_Funcionarios >= EMPRESA) {
                    printf("Sua Empresa esta Lotada!!\n");
                    printf("Libere espaco para continuar cadastrando.\n");
                } else {
                    Funcionario tempFuncionario;

                    printf("\n=====================\n");
                    printf("Cadastro de Funcionario\n");
                    printf("=====================\n");

                    printf("Codigo do Funcionario (max 5 chars): ");
                    scanf("%5s", tempFuncionario.codigo);

                    printf("Idade: ");
                    scanf("%d", &tempFuncionario.idade);

                    printf("Salario (R$): ");
                    scanf("%f", &tempFuncionario.salario);

                    strcpy(vetorEmpresa[qtd_Funcionarios].codigo, tempFuncionario.codigo);
                    vetorEmpresa[qtd_Funcionarios].idade = tempFuncionario.idade;
                    vetorEmpresa[qtd_Funcionarios].salario = tempFuncionario.salario;

                    qtd_Funcionarios++;

                    printf("Funcionario Cadastrado com Sucesso!!!\n");
                }
                break;
            }

            case 2: {
                bool encontrou = false;
                int contador = 0;

                if (qtd_Funcionarios < 1) {
                    printf("Voce ainda nao tem funcionarios cadastrados.\n");
                } else {
                    printf("\n--- Funcionarios com mais de 40 anos e Salario > R$ 5.000,00 ---\n");
                    
                    for (int i = 0; i < qtd_Funcionarios; i++) {
                        if (vetorEmpresa[i].idade > 40 && vetorEmpresa[i].salario > 5000.00) {
                            printf("Codigo: %s | Idade: %d anos | Salario: R$ %.2f\n",
                                   vetorEmpresa[i].codigo,
                                   vetorEmpresa[i].idade,
                                   vetorEmpresa[i].salario);
                            encontrou = true;
                            contador++;
                        }
                    }

                    if (!encontrou) {
                        printf("Nenhum funcionario atende aos criterios (> 40 anos e salario > R$ 5.000,00).\n");
                    } else {
                        printf("-------------------------------------------------------------\n");
                        printf("Total de funcionarios que atendem ao filtro: %d\n", contador);
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