/*2. Controle de Estoque de Mercado
Contexto: Um minimercado quer controlar a quantidade de produtos.
        
        * Struct: Produto (Código, Quantidade, Preço).
        * Menu:
        1. Cadastrar produto.
           2. Exibir o valor total investido no estoque (soma de Quantidade * Preço de todos os itens).
           3. Sair.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESTOQUE_TOTAL 100

typedef struct {
    int codigo;
    int qtd_itens;
    float valor;     
}Produtos;

int main (){
    Produtos vetorProdutos[ESTOQUE_TOTAL];
    int opcao, pr_cadastrados = 0;
    float acumulativo = 0;

    do
    {
        printf("====================\n");
        printf("      #MENU#\n");
        printf("====================\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Valor Total do Estoque\n");
        printf("3. Sair\n");
        printf("Escolha um Opção => ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        if (pr_cadastrados < ESTOQUE_TOTAL){
            int codigo, qtd_itens;
            float valor;

            printf("Digite o Codigo do Produto: \n");
            scanf("%d", &codigo);
            printf("Digite o Quantidade em Estoque do Produto: \n");
            scanf("%d", &qtd_itens);
            printf("Digite o Valor Unitario do Produto: \n");
            scanf("%f", &valor);

           acumulativo += valor*qtd_itens;

           vetorProdutos[pr_cadastrados].codigo = codigo;
           vetorProdutos[pr_cadastrados].qtd_itens = qtd_itens;
           vetorProdutos[pr_cadastrados].valor = valor;
           pr_cadastrados++;

           printf("Produto Armazenado com Sucesso");
        }else{
            printf("Seu Estoque está Lotado, Libere espaço para continuar armazenando\n");
        }
            break;
        
        case 2: 
        if(pr_cadastrados > 0){
            printf ("=================\n");
            printf("  ESTOQUE ATUAL\n");
            printf("==================\n");
        for (int i = 0; i < pr_cadastrados; i++){
            printf("Produto %d\n", i+1);
            printf("Codigo: %d\n", vetorProdutos[i].codigo);
            printf("Quantidade: %d\n", vetorProdutos[i].qtd_itens);
            printf("Valor Un: %f\n", vetorProdutos[i].valor);
        }
        printf("=======================");
        printf("VALOR TOTAL EM ESTOQUE: ");
        printf("R$ %.2f\n",acumulativo);
        }else{
            printf("Estoque Vazio, Adicione novos itens\n");
        }
            break;
        case 3:
        printf("Encerrando Programa!!!!");
            break;
        
            default:
            printf("Valor Invalido, Tente Novamente");      
        } 
    } while (opcao != 3);
}
