#ifndef LOJA_H
#define LOJA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Produto.h"
#include "Funcionario.h"
#include "Cliente.h"

void iniciarLoja(Produto* repositorioProduto, int incrementoProduto, Cliente *cliente);

void printarProduto(Produto produto) {
	printf("+-----+--------+--------+-----+\n");
	printf("|Nome: %s \n\n",produto.nome);
	printf("|Descrição: %s \n",produto.descricao);
	printf("|R$%.2f \n",produto.valor);
	printf("|Código: %s \n",produto.codigo);
	printf("|Tamanho: %s \n", produto.tamanho);
	//printf("|Quantidade disponível: %d \n", produto.qtd_Itens);
	printf("+-----+--------+--------+-----+\n\n");
}
void printarCarrinho(Produto listaDeProdutos[], int incrementoProduto) {
	system("cls");
	int i;
	float total = 0;
	for(i = 0; i<incrementoProduto; i++) {
		if (listaDeProdutos[i].status == 1) {
            printarProduto(listaDeProdutos[i]);
            total+= listaDeProdutos[i].valor;
		}
	}

	printf("+-----+--------+--------+-----+\n");
	printf("| Valor Total - R$%.2f \n",total);
	printf("+-----+--------+--------+-----+\n\n");
	system("pause");
}

void printarMenuCarrinho() {
	system("cls");
    printf("SELECIONE UMA OPÇÃO: ");
    printf("\n1 - Comprar todos os items");
    printf("\n2 - Remover Item");
    printf("\n3 - Voltar\n");
}
void printarMenuLojaPrincipal() {
	system("cls");
    printf("SELECIONE UMA OPÇÃO: ");
    printf("\n1 - Listar Produtos");
    printf("\n2 - Ver carrinho");
    printf("\n3 - Logout\n");
}

void printarTodosProdutos(Produto *repositorioProduto, int incrementoProduto) {
	system("cls");
	int i;
	printf("+-----+----- LOLJA -----+-----+\n");
	for(i = 0; i<incrementoProduto; i++) {
        printarProduto(repositorioProduto[i]);
	}
}

void printarTodosProdutosAtivos(Produto *repositorioProduto, int incrementoProduto) {
    system("cls");
	int i;
	printf("+-----+----- LOLJA -----+-----+\n");
	for(i = 0; i<incrementoProduto; i++) {
		if(repositorioProduto[i].status == 1 && repositorioProduto[i].qtd_Itens > 0) {
            printarProduto(repositorioProduto[i]);
		}
	}
}

void removerItemCarrinho(Produto *carrinho, int qntItems, char codigo[20], Produto *repositorioProduto) {
    int i, indice;
    for(i=0; i<qntItems; i++) {
        if(strcmp(carrinho[i].codigo, codigo) == 0) {
            carrinho[i].status = 0;
            ProductResponse produtoResponse = procurarProduto(codigo, repositorioProduto);
            produtoResponse.produto.qtd_Itens ++;
            indice = getIndiceProduto(codigo, repositorioProduto);
            repositorioProduto[indice] = produtoResponse.produto;
            return;
        }
    }
}

void removerItemCarrinhoFull(Produto *carrinho, int qntItems, Produto *repositorioProduto) {
    system("cls");
    printarCarrinho(carrinho, qntItems);
    char codigo[20];
    do {
        printf("Qual dos items do carrinho você quer remover?");
        printf("\nDigite o código dele ou exit para cancelar\n");
        gets(codigo);
        removerItemCarrinho(carrinho, qntItems, codigo, repositorioProduto);
        printf("\nitem removido com sucesso");
        printarCarrinho(carrinho, qntItems);
    } while(strcmpi(codigo, "exit") != 0);
}

void comprarItemsCarrinho(Produto *carrinho, int qntItems, Cliente *cliente) {
    system("cls");
    int op;
    printf("Escolha uma opção\n");
    printf("\n1 - Comprar Tudo");
    printf("\n2 - Voltar\n");
    scanf("%i", &op);
    float total = 0;
    if(op == 1) {
        int i;
        for(i=0; i<qntItems; i++) {
            carrinho[i].status = 0;
            total += carrinho[1].valor;
        }
        //cadastrarTransacao(total, cliente);
        //cadastrarTransacao(total, cliente);
		printf("Obrigado pela compra");
    }
    return;
}

void printarProdutoMenu(){
	printf("Digite o código do produto que deseja colocar no carrinho\n");
	printf("Ou digite 'exit' para sair \n");
}

void iniciarLoja(Produto* repositorioProduto, int incrementoProduto,Cliente *clienteLogado) {
	system("cls");
	Produto carrinho[20];
	char codigo[10], listaOp[10];
	int lojaOp, i, qntCarrinho = 0, carrinhoOp, indice;
	ProductResponse produtoResponse;
	do {
		printarMenuLojaPrincipal();
		scanf("%i",&lojaOp);

		switch(lojaOp){
			case 1: //listar todos os itens da loja
				printarTodosProdutosAtivos(repositorioProduto, incrementoProduto);
				do {
					printarProdutoMenu();
					gets(listaOp);
					produtoResponse = procurarProduto(listaOp, repositorioProduto);

					if (strcmp(listaOp, "exit") != 0) {
						if (produtoResponse.error == 0){
							if(produtoResponse.produto.qtd_Itens > 0){
								carrinho[qntCarrinho] = produtoResponse.produto;
								qntCarrinho++;
								printf("\nProduto adicionado no carrinho com sucesso.\n");
								produtoResponse.produto.qtd_Itens-=1;
								if(produtoResponse.produto.qtd_Itens <= 5){
									printf("Produto acabando, restam %d unidades\n", produtoResponse.produto.qtd_Itens);
								}
								indice = getIndiceProduto(listaOp, repositorioProduto);
								repositorioProduto[indice] = produtoResponse.produto;
							}
							else{
								printf("\nProduto indisponível, selecione outro produto!\n");
							}
						}
						else {
							printf("\nProduto não encontrado, por favor tente novamente\n");
						}

					}
				}while(strcmp(listaOp, "exit") != 0);
				system("pause");
				break;
			case 2:
				printarCarrinho(carrinho, qntCarrinho);
				do{
					printarMenuCarrinho();
					scanf("%i",&carrinhoOp);

					switch(carrinhoOp) {
						case 1:
						    comprarItemsCarrinho(carrinho, qntCarrinho, clienteLogado);
							break;
						case 2:
						    removerItemCarrinhoFull(carrinho, qntCarrinho, repositorioProduto);
							break;
						case 3:
						    printf("Voltar");
							break;
						default:
							break;
					}
				} while(carrinhoOp != 3);
				system("pause");
				break;
			case 3:
				break;
			default:
				break;
		}
	}while(lojaOp != 3);
}

#endif
