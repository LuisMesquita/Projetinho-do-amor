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
    printf("\n2 - Logout\n");
}

void printarProduto(Produto listaDeProdutos[], int qntItems) {
	for(i = 0; i<qntItems; i++) {
		printf("+-----+--------+--------+-----+\n");
		printf("|nome: %s \n\n",listaDeProdutos[i].nome);
		printf("|descrição: %s \n",listaDeProdutos[i].descricao);
		printf("|R$%f \n",listaDeProdutos[i].valor);
		printf("|código: %s \n",listaDeProdutos[i].codigo);
		printf("+-----+--------+--------+-----+\n\n");
	}
}

void iniciarLoja(Produto* repositorioProduto, int qntItems) {
	printf("Loja geek");
	getchar();
	int lojaOp, i;
	do {
		printarMenuLojaPrincipal();
		scanf("%i",&lojaOp);
		
		switch(lojaOp){
			case 1: //listar todos os itens da loja
				printarProduto(repositorioProduto, qntItems);
				
				printf("Digite o codigo do produto que você quer comprar\n");
				system("pause");
				break;
			case 2:
				break;
		}
	}while(lojaOp != 2);
}


#endif
