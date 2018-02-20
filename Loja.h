#ifndef LOJA_H
#define LOJA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Produto.h"

void iniciarLoja(Produto* repositorioProduto, int qntItems);


void printarMenuLojaPrincipal() {
	system("cls");
    printf("SELECIONE UMA OPÇÃOO: ");
    printf("\n1 - Listar Produtos");
    printf("\n2 - Ver carrinho");
    printf("\n3 - Logout\n");
}

void printarTodosProdutos(Produto listaDeProdutos[], int qntItems) {
	system("cls");
	int i;
	for(i = 0; i<qntItems; i++) {
		printarProduto(listaDeProdutos[i]);
	}
}

void printarProduto(Produto produto) {
	printf("+-----+--------+--------+-----+\n");
	printf("|nome: %s \n\n",produto.nome);
	printf("|descrição: %s \n",produto.descricao);
	printf("|R$%f \n",produto.valor);
	printf("|código: %s \n",produto.codigo);
	printf("+-----+--------+--------+-----+\n\n");
}

void printarCarrinho(Produto listaDeProdutos[], int qntItems) {
	system("cls");
	int i;
	float total;
	for(i = 0; i<qntItems; i++) {
		printarProduto(listaDeProdutos[i]);
		total+= listaDeProdutos[i].valor;
	}
	
	printf("+-----+--------+--------+-----+\n");
	printf("| Valor Total - R$%f \n",total);
	printf("+-----+--------+--------+-----+\n\n");
	system("pause");
}

void printarProdutoMenu(){
	printf("Digite o código do produto que deseja colocar no carrinho\n");
	printf("Ou digite 'exit' para sair \n");
}

void iniciarLoja(Produto* repositorioProduto, int qntItems) {
	printf("Loja geek");
	getchar();
	Produto carrinho[20];
	char codigo[10], carrinhoOp[20];
	int lojaOp, i, qntCarrinho = 0;
	ProductResponse produtoResponse;
	do {
		printarMenuLojaPrincipal();
		scanf("%i",&lojaOp);
		
		switch(lojaOp){
			case 1: //listar todos os itens da loja
				printarTodosProdutos(repositorioProduto, qntItems);
				do {
					printarProdutoMenu();
					gets(carrinhoOp);
					produtoResponse = procurarProduto(carrinhoOp, repositorioProduto);
					
					if (strcmp(carrinhoOp, "exit") != 0) {
						if (produtoResponse.error == 0){
							carrinho[qntCarrinho] = produtoResponse.produto;
							qntCarrinho++;
							printf("\nProduto adicionar no carrinho com sucesso.\n");
						} else {
							printf("\nProduto não encontrado, por favor tente novamente\n");
						}
					}
					
				}while(strcmp(carrinhoOp, "exit") != 0);
				system("pause");
				break;
			case 2:
				printarCarrinho(carrinho, qntCarrinho);
				system("pause");
				do {
					
				}while(1<3);
				break;
			case 3:
				break;
			default:
				break;
		}
	}while(lojaOp != 3);
}


#endif
