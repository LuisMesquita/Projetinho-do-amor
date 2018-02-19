#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"

typedef struct{
	Produto repositorioProduto[1000];
	Cliente repositorioCliente[1000];
	Funcionario repositorioFuncionario[1000];
	int incrementoCliente;
	int incrementoFuncionario;
	int incrementoProduto;
}Sistema;

/*void salvarSistema(){
	

#endif
