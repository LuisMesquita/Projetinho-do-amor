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
    printf("SELECIONE UMA OPÇÃO: ");
    printf("\n1 - Login");
    printf("\n2 - Cadastro");
    printf("\n3 - Voltar\n");
}

int main(int argc, char *argv[]) {
	int op;
	static int incremento = 1;
	setlocale(LC_ALL, "Portuguese");
	Cliente repositorioCliente[1000];
	Produto repositorioProduto[1000];
	Funcionario repositorioFuncionario[1000];
	lerCliente(repositorioCliente, incremento);
	do{
        Cliente c;
		char senhaAdmin[5];
		char idAdmin[5];
		int retornoValidacao;
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
                            char cpf[11], senha[8];
                            system("cls");
							getchar();
							printf("Digite seu CPF (somente números): ");							
							gets(cpf);
							printf("Digite sua senha: ");
							gets(senha);

							retornoCliente = loginCliente(cpf, senha, repositorioCliente);
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
                        printf("cadastro filha d aputa");
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


