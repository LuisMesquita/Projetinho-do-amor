
#include <stdio.h>
#include <string.h>

typedef struct{
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

void cadastrarProduto(char codigo[10], char nome[20], float valor,int qtd_Itens, char tamanho[2], char descricao[250],int *incremento, Produto *repositorioProduto){
	Produto p;
	strcpy(p.codigo, codigo);
	strcpy(p.nome, nome);
	p.valor = valor;
	p.qtd_Itens = qtd_Itens;
	p.status = 1;
	strcpy(p.tamanho, tamanho);
    strcpy(p.descricao, descricao);

	repositorioProduto[incremento] = p;
}

int getIndiceProduto(char codigo[10], Produto *repositorioProduto){ // RETORNA O INDICE DO PRODUTO COM O CÓDIGO PESQUISADO.
	int indice;

	char comp[10];
	for(indice = 0; indice < 1000;){
		strcpy(comp, repositorioProduto[indice]->codigo);
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
		strcpy(comp, repositorioProduto[indice]->categoria);
		if(strcmp(comp, categoria)==0){
			return indice;
		}
		else{
			indice++;
		}
	}
}
ProductResponse procurarProduto(char codigo, Produto *repositorioProduto){ // RETORNA O PRODUTO DO CÓDIGO PESQUISADO.
	Produto p, p1;
	ProductResponse response;
	p1.status = 0;
	int indice;
	indice = getIndiceProduto(codigo, repositorioProduto);
	p = repositorioProduto[indice];
	if(p.status == 1){
		response.produto = p;
		response.error = NULL;  //   TRATAR AS MENSAGENS DE ERRO NO MAIN.
	}
	else{
		response.produto = p1;
		response.error = 1; //   TRATAR AS MENSAGENS DE ERRO NO MAIN.
	}

	return response;
}
int removerProduto(char codigo[10], Produto *repositorioProduto){ // REMOVE O PRODUTO COM CÓDIGO INDICADO, ALTERANDO O STATUS DO PRODUTO.
	ProductResponse p;
	p = procurarProduto(codigo, repositorioProduto);
	if (p.error == NULL) {
        p.produto.status = 0;
        return 0;
	} else {
        return p.error;
	}
}
int removerItens(char codigo[10], int qtd_Itens, Produto *repositorioProduto){
    ProductResponse p;
	p = procurarProduto(codigo, repositorioProduto);
	if(p.produto.status == 1){
        if(p.produto.qtd_Itens >= qtd_Itens){
            p.produto.qtd_Itens -= qtd_Itens;
            p.error = 0;
        }
        else{
            p.error = 2;
        }
	}
	else{
        p.error = 1;
	}
	return p.error;
}
int adicionarItens(char codigo[10], int qtd_Itens, Produto *repositorioProduto){
    ProductResponse p;
	p = procurarProduto(codigo, repositorioProduto);
	if(p.produto.status == 1){
        p.produto.qtd_Itens += qtd_Itens;
        p.error = 0;
	}
	else{
        p.error = 1;
	}
	return p.error;
}
