#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <string.h>

typedef struct {
	int qtd_Itens;
	int status;
	float valor;
	char descricao[250];
	char tamanho[2];
	char codigo[10];
	char nome[20];
	char categoria[20];
}Produto;

typedef struct{
        Produto produto;
        int error;
}ProductResponse;

int cadastrarProduto(Produto p, int incremento, Produto *repositorioProduto);
int getIndiceProduto(char codigo[10], Produto *repositorioProduto);
int getIndiceCategoria(char categoria[20], Produto *repositorioProduto);
ProductResponse procurarProduto(char codigo[10], Produto *repositorioProduto);
void salvarProduto(Produto *repositorioProduto, int incremento);
void lerProduto(Produto *repositorioProduto, int incremento);

int cadastrarProduto(Produto p, int incremento, Produto *repositorioProduto){
	ProductResponse response;
	response.produto = p;
	response.produto.status = 1;
	repositorioProduto[incremento] = response.produto;
	
	response.error = 1; // Cadastrado com sucesso;
	
	return response.error;
}

int getIndiceProduto(char codigo[10], Produto *repositorioProduto){ // RETORNA O INDICE DO PRODUTO COM O CÓDIGO PESQUISADO.
	int indice;

	char comp[10];
	for(indice = 0; indice < 1000;){
		strcpy(comp, repositorioProduto[indice].codigo);
		if(strcmp(comp, codigo)==0){
			return indice;
		}
		else{
			indice++;
		}
	}
}
int getIndiceCategoria(char categoria[20], Produto *repositorioProduto){ // RETORNA O INDICE DO PRODUTO COM A CATEGORIA PESQUISADA.
	int indice;
	char comp[20];
	for(indice = 0; indice < 1000;){
		strcpy(comp, repositorioProduto[indice].categoria);
		if(strcmp(comp, categoria)==0){
			return indice;
		}
		else{
			indice++;
		}
	}
}
ProductResponse procurarProduto(char codigo[10], Produto *repositorioProduto){ // RETORNA O PRODUTO DO CÓDIGO PESQUISADO.
	Produto p, p1;
	ProductResponse response;
	p1.status = 0;
	int indice;
	indice = getIndiceProduto(codigo, repositorioProduto);
	if(strcmp(codigo, repositorioProduto[indice].codigo) == 0){
		p = repositorioProduto[indice];
		if(p.status == 1){
			response.produto = p;
			response.error = 0;  //   TRATAR AS MENSAGENS DE ERRO NO MAIN. /  PRODUTO ENCONTRADO
		}
		else{
			response.produto = p1;
			response.error = 1; //   TRATAR AS MENSAGENS DE ERRO NO MAIN. /  PRODUTO NÃO ENCONTRADO
		}
	}
	else{
		response.error = 1; // TRATAR AS MENSAGENS DE EROO NO MAIN /  PRODUTO NÃO ENCONTRADO
	}
	return response;
}


void salvarProduto(Produto *repositorioProduto, int incremento){
	FILE *arq;
	arq = fopen("produtos.txt", "wb");
	fwrite(repositorioProduto, sizeof(Produto), incremento, arq);
	fclose(arq);
}

void lerProduto(Produto *repositorioProduto, int incremento){
	FILE *arq;
	arq = fopen("produtos.txt", "rb");
	fread(repositorioProduto, sizeof(Produto), incremento, arq);
	fclose(arq);
}

#endif
