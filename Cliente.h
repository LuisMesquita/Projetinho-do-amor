#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome[30];
    int idade;
    char email[30];
    char endereco[50];
    char cpf[11];
    char nick[10];
    char senha[8];
    int status;
}Cliente;

typedef struct{
    Cliente cliente;
    int error;
}ClientResponse;

//funçao getIndice varre o repositorio cliente atraves do cpf e retorna o numero da posiçao do vetor em que ele se encontra!!
int getIndice(char cpf[11], Cliente *repositorioCliente){ //Nao esquecer de setar no main o repositório!!!
    char comp[11];
    int indice;
    for(indice=0; indice<1000;){
        comp = repositorioCliente[indice]->cpf;
        if(strcmp(cpf, comp) == 0){
            return indice;
        }
        else{
            indice++;
        }
    }
}

void cadastrarCliente(char nome[30],int idade,char email[30], char endereco[50],char cpf[11],char nick[10], char senha[8], Cliente *repositorioCliente, int *incremento){
    Cliente c;
    strcpy(c.nome, nome);
    c.idade=idade;
    strcpy(c.email, email);
    strcpy(c.endereco, endereco);
    strcpy(c.cpf, cpf);
    strcpy(c.nick, nick);
    strcpy(c.senha, senha);
    c.status = 1;

    repositorioCliente[incremento] = c;
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
	return p.error;
}

int removerCliente(char cpf[11], Cliente *repositorioCliente){
    ClientResponse c;
    c = buscarCliente(cpf, repositorioCliente);
    if(c.error == NULL){
        c.cliente.status = 0;
        return 0;
    }
    else{
        return c.error;
    }
}

//funçao buscar cliente usa o indice do vetor encontrado no getIndice para retornar o cliente naquela posiçao!!
 ClientResponse buscarCliente(char cpf[11], Cliente *repositorioCliente){
    Cliente c;
    ClientResponse response;
    c1.status = 0;
    int indice;
    indice = getIndice(cpf);
    c = repositorioCliente[indice];
    if(c.status == 1){
        response.cliente = c;
        response.error = NULL;
    }
    else{
    	response.error = 1;
	}
	return response;
}
int loginCliente(char cpf[11], char senha[8], Cliente *repositorioCliente){
    int indice;
    indice = getIndice(cpf, repositorioCliente);
    if(strcmp(senha, repositorioCliente[indice]->senha) == 0){
        return 1;
    }
    else{
        return 0;
    }
}
