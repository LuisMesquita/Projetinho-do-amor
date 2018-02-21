#ifndef SISTEMA_H
#define SISTEMA_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void salvarIncrementoCliente(int* incrementoCliente, int quantidade);
void salvarIncrementoFuncionario(int* incrementoFuncionario, int quantidade);
void salvarIncrementoProduto(int *incrementoProduto, int quantidade);
void lerIncrementoCliente(int *incrementoCliente, int quantidade);
void lerIncrementoProduto(int *incrementoProduto, int quantidade);
void lerIncrementoFuncionario(int *incrementoFuncionario, int quantidade);

void salvarIncrementoCliente(int* incrementoCliente, int quantidade){
	FILE *arq;
	arq = fopen("IncrementoCliente.txt", "wb");
	fwrite(&incrementoCliente, sizeof(int), quantidade, arq);
	fclose(arq);
}
void salvarIncrementoFuncionario(int* incrementoFuncionario, int quantidade){
	FILE *arq;
	arq = fopen("IncrementoFuncionario.txt", "wb");
	fwrite(&incrementoFuncionario, sizeof(int), quantidade, arq);
	fclose(arq);
}
void salvarIncrementoProduto(int *incrementoProduto, int quantidade){
	FILE *arq;
	arq = fopen("IncrementoProduto.txt", "wb");
	fwrite(&incrementoProduto, sizeof(int), quantidade, arq);
	fclose(arq);
}
void lerIncrementoCliente(int *incrementoCliente, int quantidade){
	FILE *arq;
	if(fopen("IncrementoCliente.txt", "rb") == NULL){
		incrementoCliente = 0;
		arq = fopen("IncrementoCliente.txt", "rb");
	}
	else{
		arq = fopen("IncrementoCliente.txt", "rb");
	}
	fread(incrementoCliente, sizeof(int), quantidade, arq);
	fclose(arq);
}
void lerIncrementoFuncionario(int *incrementoFuncionario, int quantidade){
	FILE *arq;
	if(fopen("IncrementoFuncionario.txt", "rb") == NULL){
		incrementoFuncionario = 0;
		arq = fopen("IncrementoFuncionario.txt", "rb");
	}
	else{
		arq = fopen("IncrementoFuncionario.txt", "rb");
	}
	fread(incrementoFuncionario, sizeof(int), quantidade, arq);
	fclose(arq);
}
void lerIncrementoProduto(int *incrementoProduto, int quantidade){
	FILE *arq;
	if(fopen("IncrementoProduto.txt", "rb") == NULL){
		incrementoProduto = 0;
		arq = fopen("IncrementoProduto.txt", "rb");
	}
	else{
		arq = fopen("IncrementoProduto.txt", "rb");
	}
	fread(incrementoProduto, sizeof(int), quantidade, arq);
	fclose(arq);
}
	

#endif
