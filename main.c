#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"

void printarMenuPrincipal(){
    system("cls");
	printf("BEM-VINDO A LOLJA!");
	printf("\nSELECIONE UMA OPÇÃO: ");
	printf("\n1 - Cliente");
	printf("\n2 - Funcionário");
	printf("\n3 - Administrador");
	printf("\n4 - Sair do sistema\n");
}

void printarMenuCliente() {
    system("cls");
    printf("SELECIONE UMA OPÇÃOO: ");
    printf("\n1 - Login");
    printf("\n2 - Cadastro");
    printf("\n3 - Voltar\n");
}

int main(int argc, char *argv[]) {
	int op;
	int incremento = 1;
	setlocale(LC_ALL, "Portuguese");
	Cliente repositorioCliente[1000];
	Produto repositorioProduto[1000];
	Funcionario repositorioFuncionario[1000];
	lerCliente(repositorioCliente, incremento);
	
	do{
        Cliente c;
		char senhaAdmin[5];
		char idAdmin[5];
		char senhaCliente[8];
		char senhaClienteComp[8];
		char cpf[11];
		char senha[8];
		int retornoSenhaCliente;
		int retornoCadastroCliente;
		int retornoValidacao;
		//int incremento = 1;
        printarMenuPrincipal();
        scanf("%i", &op);

        switch(op){
           case 1:
				printarMenuCliente();
				int opCliente;
				scanf("%i", &opCliente);
                int retornoCliente, countErros;
				switch(opCliente) {
                    case 1: //Login
                        countErros = 0;
						do{
                            system("cls");
							getchar();
							printf("Digite seu CPF (somente números): ");
							gets(cpf);
							printf("Digite sua senha: ");
							gets(senha);

							retornoCliente = loginCliente(cpf, senha, repositorioCliente);
							//printf("%i", retornoCliente);
							if(retornoCliente != 1){
								printf("\nSenha Incorreta, digite novamente!\n");
								countErros++;
								getchar();
							}
						}while(retornoCliente != 1 && countErros <= 3);
						system("cls");
						if (retornoCliente == 1) {
							printf("LOGADO COM SUCESSO!");
							system("pause");
						}
						
                    break;

                    case 2: //Cadastro
                    	getchar();
                    	system("cls");
                        printf("Digite seu nome: ");
                        gets(c.nome);
                        printf("Digite sua idade: ");
                        scanf("%i", &c.idade);
                        getchar();
                        printf("Digite seu e-mail: ");
                        gets(c.email);
                        printf("Digite seu CPF (somente números): ");
                        gets(c.cpf);
                        printf("Digite seu endereço: ");
                        gets(c.endereco);
                        do{
                        	printf("Digite uma senha com 8 digitos: ");
                        	gets(senhaCliente);
                        	printf("Confirme a senha: ");
                        	gets(senhaClienteComp);
                        	
                        	retornoSenhaCliente = strcmp(senhaCliente, senhaClienteComp);
                        	if(retornoSenhaCliente != 0){
                        		printf("Senhas digitas são diferentes! Digite novamente!\n");
							}
						}while(retornoSenhaCliente != 0);
						strcpy(c.senha, senhaCliente);
						retornoCadastroCliente = cadastrarCliente(c, repositorioCliente, incremento);
						
						if(retornoCadastroCliente == 1){
							incremento++;
							system("cls");
							printf("Cadastrado com sucesso!\n");
							//printf("%s", repositorioCliente[1].cpf);
							system("pause");
						}
						
                    break;

                    default:
                    break;
				}

            break;

            case 2:
                getchar();
				system("cls");
				printf("LOGIN");
				int retornoFuncionario;
				char cpfFuncionario [11];
				char senhaFuncionario[8];
				do{
					getchar();
					printf("\nDigite seu CPF (somente números): ");
					gets(cpfFuncionario);
					printf("Digite sua senha: ");
					gets(senhaFuncionario);
					retornoFuncionario = loginFuncionario(cpfFuncionario, senhaFuncionario, repositorioFuncionario);
					if(retornoFuncionario != 1){
						printf("CPF ou senha incorretos, digite novamente!");
					}
				}while(retornoFuncionario != 1);
				system("cls");
				printf("LOGADO COM SUCESSO!");
				break;

			case 3:
				getchar();
				system("cls");
				do{
					printf("Digite o id do Administrador: ");
					gets(idAdmin);
					printf("Digite a senha do Administrador: ");
					gets(senhaAdmin);
					retornoValidacao = validadarAdmin(idAdmin, senhaAdmin);

					if(retornoValidacao != 1){
						printf("ID ou senha inválidos, digite novamente: ");
						printf("\nDigite o ID do Administrador: ");
						gets(idAdmin);
						printf("Digite a senha do Administrador: ");
						gets(senhaAdmin);
						retornoValidacao = validadarAdmin(idAdmin, senhaAdmin);
					}
				}while(retornoValidacao != 1);
				system("cls");
				printf("LOGADO COM SUCESSO");
			break;

            default:
                printf("Obrigado pela visita");
            break;
        }
	}while(op != 4);
}
