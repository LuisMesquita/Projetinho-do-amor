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

void printarProdutos(Produto listaDeProdutos[], int qntItems) {
	int i;
	for(i = 0; i<qntItems; i++) {
		printf("+-----+--------+--------+-----+\n");
		printf("|nome: %s \n\n",listaDeProdutos[i].nome);
		printf("|descrição: %s \n",listaDeProdutos[i].descricao);
		printf("|R$%f \n",listaDeProdutos[i].valor);
		printf("|código: %s \n",listaDeProdutos[i].codigo);
		printf("+-----+--------+--------+-----+\n\n");
	}
}

void printarProdutoMenu(){
	printf("Digite o código do produto que deseja colocar no carrinho ou exit para sair.");
}

void iniciarLoja(Produto* repositorioProduto, int qntItems) {
	printf("Loja geek");
	getchar();
	Produto carrinho[20];
	char codigo[10], carrinhoOp[20];
	int lojaOp, qntCarrinho = 0;
	ProductResponse produtoResponse;
	do {
		printarMenuLojaPrincipal();
		scanf("%i",&lojaOp);
		
		switch(lojaOp){
			case 1: //listar todos os itens da loja
					int i;
					for(i = 0; i<qntItems; i++) {
						printf("+-----+--------+--------+-----+\n");
						printf("|nome: %s \n\n",repositorioProduto[i].nome);
						printf("|descrição: %s \n",repositorioProduto[i].descricao);
						printf("|R$%f \n",repositorioProduto[i].valor);
						printf("|código: %s \n",repositorioProduto[i].codigo);
						printf("+-----+--------+--------+-----+\n\n");
					}
				system("pause");
				do {
					printarProdutoMenu();
					getchar();
					gets(carrinhoOp);
					produtoResponse = procurarProduto(carrinhoOp, repositorioProduto);
					
					if (produtoResponse.error == 0 && strcmp(carrinhoOp, "exit") != 0)){
						carrinho[qntCarrinho] = produtoResponse.produto;
						qntCarrinho++;
						printf("\nProduto adicionar no carrinho com sucesso.");
					} else {
						printf("\nProduto não encontrado, por favor tente novamente.");
					}
					
				}while(strcmp(carrinhoOp, "exit") != 0);
				system("pause");
				break;
			case 2:
				printarProdutos(carrinho, qntCarrinho);
				
				break;
			case 3:
				break;
			default:
				break;
		}
	}while(lojaOp != 3);
}


#endif
