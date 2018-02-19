#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"

typedef struct{
    char nome[30];
    int idade;
    char email[30];
    char endereco[50];
    char cpf[11];
    char senha[10];
    int status;
}Funcionario;

typedef struct{
    Funcionario funcionario;
    int error;
}FuncionarioResponse;

int getIndiceCpf(char cpf[11], Funcionario *repositorioFuncionario);
int cadastrarFuncionario(Funcionario f, int incremento, Funcionario *repositorioFuncionario);
int removerFuncionario(char cpf[11], Funcionario *repositorioFuncionario);
FuncionarioResponse procurarFuncionario(char cpf[11], Funcionario *repositorioFuncionario);
FuncionarioResponse loginFuncionario(char cpf[11], char senha[8], Funcionario *repositorioFuncionario);
int removerProduto(char codigo[10], Produto *repositorioProduto);
int removerItens(char codigo[10], int qtd_Itens, Produto *repositorioProduto);
int adicionarItens(char codigo[10], int qtd_Itens, Produto *repositorioProduto);
void salvarFuncionario(Funcionario *repositorioFuncionario, int incremento);
void lerFuncionario(Funcionario *repositorioFuncionario, int incremento);
int validadarAdmin(char id[5], char senha[5]);
int alterarCadastroProduto(char codigo[10], Produto pa, Produto *repositorioProduto);

int validadarAdmin(char id[5], char senha[5]){
	char senhaComp[10] = "admin";
	char idComp[10] = "admin";

	if(strcmp(id, idComp) == 0 && strcmp(senha, senhaComp) == 0){
		return 1; // Validado;
	}
	else{
		return 0; //N�o validado;
	}
}

int getIndiceCpf(char cpf[11], Funcionario *repositorioFuncionario){
    char cpfComp[11];
    int i;
    for(i = 0; i < 1000;){
        strcpy(cpfComp, repositorioFuncionario[i].cpf);
        if(strcmp(cpf, cpfComp) == 0){
            return i;
        }
        else{
            i++;
        }
    }
}

int cadastrarFuncionario(Funcionario f, int incremento, Funcionario *repositorioFuncionario){
    FuncionarioResponse response;
	response.funcionario = f;
	response.funcionario.status = 1;
    repositorioFuncionario[incremento] = response.funcionario;

    response.error = 1; // Funcionario Cadastrado com sucesso;

    return response.error;
}
int removerFuncionario(char cpf[11], Funcionario *repositorioFuncionario){
    FuncionarioResponse response;
    response = procurarFuncionario(cpf, repositorioFuncionario);
    if(response.error == 0){
        response.funcionario.status = 0;
        return 0;
    }
    else{
        return 1;
    }
}

FuncionarioResponse procurarFuncionario(char cpf[11], Funcionario *repositorioFuncionario){
    Funcionario f;
    FuncionarioResponse response;
    int indice;
    indice = getIndiceCpf(cpf, repositorioFuncionario);
    if(strcmp(cpf, repositorioFuncionario[indice].cpf) == 0 && repositorioFuncionario[indice].status == 1){
    	f = repositorioFuncionario[indice];

    	if(f.status == 1){
       		response.funcionario = f;
       		response.error = 0;
    	}
    	else{
    		response.error = 1; // usuario inativo;
		}
	}
	else{
		response.error = 5; // Funcion�rio n�o encontrado ou inativo.
	}
	return response;
}
FuncionarioResponse loginFuncionario(char cpf[11], char senha[8], Funcionario *repositorioFuncionario){
    FuncionarioResponse response;
    int indice;
    indice = getIndiceCpf(cpf, repositorioFuncionario);
    if(strcmp(senha, repositorioFuncionario[indice].senha == 0)){
        response.error = 1;
        response.funcionario = repositorioFuncionario[indice];
    }
    else{
        response.error = 0;
    }
    return response;
}

int removerProduto(char codigo[10], Produto *repositorioProduto){ // REMOVE O PRODUTO COM C�DIGO INDICADO, ALTERANDO O STATUS DO PRODUTO.
	ProductResponse response;
	response = procurarProduto(codigo, repositorioProduto);
	if (response.error == 0) {
        response.produto.status = 0;
        return 0;
	} else {
        return response.error;
	}
}
int removerItens(char codigo[10], int qtd_Itens, Produto *repositorioProduto){
    ProductResponse response;
	response = procurarProduto(codigo, repositorioProduto);
	if(response.produto.status == 1){
        if(response.produto.qtd_Itens >= qtd_Itens){
            response.produto.qtd_Itens -= qtd_Itens;
            response.error = 0;
        }
        else{
            response.error = 2;
        }
	}
	else{
        response.error = 1;
	}
	return response.error;
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
int alterarCadastroProduto(char codigo[10], Produto pa, Produto *repositorioProduto){
	ProductResponse response;
	response = procurarProduto(codigo[10], repositorioProduto);
	if(response.error == 0){
		if(strcmp(response.produto.codigo, codigo) == 0){
			int indice;
			indice = getIndiceProduto(codigo, repositorioProduto);
			repositorioProduto[indice] = pa;
			response.error = 3; //Produto alterado com sucesso
		}
		else{
			response.error = 4; // Codigo invalido
		}
	}
	return response.error;
}

void salvarFuncionario(Funcionario *repositorioFuncionario, int incremento){
	FILE *arq;
	arq = fopen("funcionarios.txt", "wb");
	fwrite(repositorioFuncionario, sizeof(Funcionario), incremento, arq);
	fclose(arq);
}

void lerFuncionario(Funcionario *repositorioFuncionario, int incremento){
	FILE *arq;
	arq = fopen("funcionarios.txt", "rb");
	fread(repositorioFuncionario, sizeof(Funcionario), incremento, arq);
	fclose(arq);
}

#endif
