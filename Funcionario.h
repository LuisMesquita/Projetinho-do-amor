#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

typedef struct{
    char nome[30];
    int idade;
    char email[30];
    char endereco[50];
    char cpf[11];
    char nick[10];
    char senha[10];
    int status;
}Funcionario;

typedef struct{
    Funcionario funcionario;
    int error;
}FuncionarioResponse;

int getIndice(char cpf, Funcionario *repositorioFuncionario){
    char cpfComp[11];
    int i;
    for(i = 0; i < 1000;){
        cpfComp = repositorioFuncionario[i]->cpf;
        if(strcmp(cpf, cpfComp) == 0){
            return i;
        }
        else{
            i++;
        }
    }
}

void cadastrarFuncionario(char nome[30], int idade, char email[30], char endereco[50], char cpf[11], char nick[10],char senha[8], int *incremento, Funcionario *repositorioFuncionario){
    Funcionario f;
    strcpy(f.nome, nome);
    f.idade = idade;
    strcpy(f.email, email);
    strcpy(f.endereco, endereco);
    strcpy(f.cpf, cpf);
    strcpy(f.nick, nick);
    strcpy(f.senha, senha);
    f.status = 1;

    repositorioFuncionario[incremento] = f;
}
int removerFuncionario(char cpf[11], Funcionario *repositorioFuncionario){
    FuncionarioResponse f;
    f = procurar(cpf, repositorioFuncionario);
    if(f.error == NULL){
        f.funcionario.status = 0;
        return 0;
    }
    else{
        return 1;
    }
}

FuncionarioResponse procurar(char cpf[11], Funcionario *repositorioFuncionario){
    Funcionario f, f1;
    FuncionarioResponse response;
    f1.status = 0
    int indice;
    indice = getIndice(cpf);
    f = repositorioFuncionario[indice];

    if(f.status == 1){
       response.funcionario = f;
       response.error = NULL;
    }
    else{
    	response.error = 1;
	}

	return response;
}
int loginFuncionario(char cpf[11], char senha[8], Funcionario *repositorioFuncionario){
    int indice;
    indice = getIndice(cpf);
    if(strcmp(senha, repositorioFuncionario[indice]->senha == 0)){
        return 1;
    }
    else{
        return 0;
    }
}
