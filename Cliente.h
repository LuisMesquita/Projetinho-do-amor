#ifndef CLIENTE_H
#define CLIENTE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Produto.h"

typedef struct{
    char nome[30];
    int idade;
    char email[30];
    char endereco[50];
    char cpf[11];
    char senha[8];
    int status;
}Cliente;

typedef struct{
    Cliente cliente;
    int error;
}ClientResponse;

int getIndice(char cpf[11], Cliente *repositorioCliente);
int cadastrarCliente(Cliente c, Cliente* repositorioCliente, int incremento);
ClientResponse procurarCliente(char cpf[11], Cliente *repositorioCliente);
int removerCliente(char cpf[11], Cliente *repositorioCliente);
int alterarCadastroCliente(char cpf[11], char email[30], char senha[8], Cliente ca, Cliente *repositorioCliente);
int alterarSenhaCliente(char cpf[11], char email[30], char novaSenha[8], Cliente *repositorioCliente);
ClientResponse loginCliente(char cpf[11], char senha[8], Cliente *repositorioCliente);
void salvarCliente(Cliente *repositorioCliente, int incremento);
void lerCliente(Cliente *repositorioCliente, int incremento);

//fun�ao getIndice varre o repositorio cliente atraves do cpf e retorna o numero da posi�ao do vetor em que ele se encontra!!
int getIndice(char cpf[11], Cliente *repositorioCliente){ //Nao esquecer de setar no main o reposit�rio!!!
    char comp[11];
    int indice;
    for(indice=0; indice<1000;){
        strcpy(comp, repositorioCliente[indice].cpf);
        if(strcmp(cpf, comp) == 0){
            return indice;
        }
        else{
            indice++;
        }
    }
    return -1;
}

int cadastrarCliente(Cliente c, Cliente* repositorioCliente, int incremento){
    ClientResponse response;
	response.cliente = c;
	response.cliente.status = 1;
    repositorioCliente[incremento] = response.cliente;

    salvarCliente(repositorioCliente, 1);
	response.error = 1; // cadastrado com sucesso.
	return response.error;
}

ClientResponse procurarCliente(char cpf[11], Cliente *repositorioCliente){
    Cliente c;
    ClientResponse response;
    int indice;
    indice = getIndice(cpf, repositorioCliente);
    c = repositorioCliente[indice];
    if(c.status == 1){
        response.cliente = c;
        response.error = 0; // Cliente encontrado
    }
    else{
    	response.error = 1; // Cliente n�o encontrado
	}
	return response;
}
int removerCliente(char cpf[11], Cliente *repositorioCliente){
    ClientResponse c;
    c = procurarCliente(cpf, repositorioCliente);
    if(c.error == 0){
        c.cliente.status = 0;
        return 0;
    }
    else{
        return c.error;
    }
}

int alterarCadastroCliente(char cpf[11], char email[30], char senha[8], Cliente ca, Cliente *repositorioCliente){
	ClientResponse response;
	response = procurarCliente(cpf, repositorioCliente);
	if(response.error == 0){
		if(strcmp(response.cliente.email, email) == 0 && strcmp(response.cliente.senha, senha) == 0){
			int indice;
			indice = getIndice(cpf, repositorioCliente);
			repositorioCliente[indice] = ca;
			response.error = 3; // Cliente alterado com sucesso
		}
		else{
			response.error = 4; // E-mail ou senha inv�lidos, cliente n�o alterado
		}
	}
	return response.error;
}

int alterarSenhaCliente(char cpf[11], char email[30], char novaSenha[8], Cliente *repositorioCliente){
	ClientResponse response;
	response = procurarCliente(cpf, repositorioCliente);
	if(response.cliente.status == 1 && strcmp(response.cliente.email, email) == 0){
		strcpy(response.cliente.senha, novaSenha);
		return 1; //Senha alterada com sucesso.
	}
	else{
		return 0; //Usu�rio inativo.
	}
}

//fun�ao buscar cliente usa o indice do vetor encontrado no getIndice para retornar o cliente naquela posi�ao!!

ClientResponse loginCliente(char cpf[11], char senha[8], Cliente *repositorioCliente){
    ClientResponse response;
    int indice;
    indice = getIndice(cpf, repositorioCliente);
    //printf("\nIndice Login %i", indice);
	if(indice >= 0){
    	if(strcmp(senha, repositorioCliente[indice].senha) == 0 && repositorioCliente[indice].status == 1){
        	response.cliente =  repositorioCliente[indice];
        	response.error = 1;
    	}
    	else{
        	response.error = 0;
    	}
	}
	else{
		response.error = 0;
	}
	return response;
}

void salvarCliente(Cliente *repositorioCliente, int incremento){
	FILE *arq;
	fseek(arq, 0, SEEK_END);
	arq = fopen("clientes.txt", "a+");
	fwrite(repositorioCliente, sizeof(Cliente), incremento, arq);
	fclose(arq);
}

void lerCliente(Cliente *repositorioCliente, int incremento){
	FILE *arq;
	arq = fopen("clientes.txt", "r");
	fread(repositorioCliente, sizeof(Cliente), incremento, arq);
	fclose(arq);
}


#endif
