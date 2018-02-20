#ifndef SISTEMA_H
#define SISTEMA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"

typedef struct {
	int incrementoCliente;
	int incrementoFuncionario;
	int incrementoProduto;
}Sistema;

void salvarSistema(Sistema* sistema, int quantidade);
void lerSistema(Sistema* sistema, int quantidade);

void salvarSistema(Sistema* sistema, int quantidade){
	FILE *arq;
	arq = fopen("Sistema.txt", "w");
	fwrite(sistema, sizeof(Sistema), quantidade, arq);
	fclose(arq);
}
void lerSistema(Sistema* sistema, int quantidade){
	FILE *arq;
	if(fopen("Sistema.txt", "r") == NULL){
		sistema->incrementoCliente = 0;
		sistema->incrementoFuncionario = 0;
		sistema->incrementoProduto = 0;
	}
	else{
		arq = fopen("Sistema.txt", "r");
	}
	fread(sistema, sizeof(Sistema), quantidade, arq);
	fclose(arq);
}
	

#endif
