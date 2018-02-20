#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"
#include "LojaGeek.h"
#include "Sistema.h"

FuncionarioResponse loginFuncionarioMain(Funcionario *repositorioFuncionario){
	getchar();
	int contErros = 0;
	system("cls");
	printf("LOGIN");
	char cpfFuncionario [11];
	char senhaFuncionario[8];
	FuncionarioResponse retornoFuncionario;
	retornoFuncionario.error= 0;
	do{
		//getchar();
		printf("\nDigite seu CPF (somente n�meros): ");
		gets(cpfFuncionario);
		fflush(stdin);
		printf("Digite sua senha: ");
		gets(senhaFuncionario);
		fflush(stdin);
		retornoFuncionario = loginFuncionario(cpfFuncionario, senhaFuncionario, repositorioFuncionario);
		if(retornoFuncionario.error == 0){
			printf("CPF ou senha incorretos, digite novamente!");
		}
		contErros++;
	}while(retornoFuncionario.error != 1 && contErros <=3 );
	return retornoFuncionario;
}

void alterarProduto(char codigo[10], Produto *repositorioProduto){
    Produto pa;
    getchar();
    system("cls");
    printf("Digite o c�digo do produto a ser alterado: ");
    gets(codigo);

    printf("Digite o nome do produto: ");
    gets(pa.nome);
    printf("Digite o valor do produto: ");
    scanf("%f", &pa.valor);
    printf("Digite a descri��o do produto: ");
    gets(pa.descricao);
    printf("Digite a categoria do produto: ");
    gets(pa.categoria);
    printf("Digite o tamanho do produto: ");
    gets(pa.tamanho);
    printf("Digite o codigo do produto: ");
    gets(pa.codigo);
    printf("Digite a quantidade que deseja adicionar: ");
    scanf("%i", &pa.qtd_Itens);
    alterarCadastroProduto(codigo, pa, repositorioProduto);
}

void criarProduto(int incrementoProduto, Produto *repositorioProduto){
	Produto p;
    getchar();
    system("cls");
    printf("Digite o nome do produto");
    gets(p.nome);
    printf("Digite o valor do produto");
    scanf("%f", &p.valor);
    printf("Digite a descri��o do produto");
    gets(p.descricao);
    printf("Digite a categoria do produto");
    gets(p.categoria);
    printf("Digite o tamanho do produto");
    gets(p.tamanho);
    printf("Digite o codigo do produto");
    gets(p.codigo);
    printf("Digite a quantidade que deseja adicionar");
    scanf("%i", &p.qtd_Itens);
    cadastrarProduto(p, incrementoProduto, repositorioProduto);
}

void printarMenuPrincipal(){
    system("cls");
	printf("BEM-VINDO A LOLJA!");
	printf("\nSELECIONE UMA OP��O: ");
	printf("\n1 - Cliente");
	printf("\n2 - Funcion�rio");
	printf("\n3 - Administrador");
	printf("\n4 - Sair do sistema\n");
}

void printarMenuCliente() {
    system("cls");
    printf("SELECIONE UMA OP��OO: ");
    printf("\n1 - Login");
    printf("\n2 - Cadastro");
    printf("\n3 - Voltar\n");
}

void printarMenuAdmin() {
    system("cls");
    printf("SELECIONE UMA OP��OO: ");
    printf("\n1 - Adicionar Funcion�rio");
    printf("\n2 - Adicionar Produto");
    printf("\n3 - Remover Produto");
    printf("\n4 - Alterar Produto");
    printf("\n5 - Logout\n");
}

void PrintarMenuFuncinario(){
	system("csl");
	printf("TELA DE FUNCIONARIO");
	printf("\nSELECIONE UMA OP��O");
	printf("\n1 - Cadastrar produto");
	printf("\n2 - Remover produto");
	printf("\n3 - Alterar produto");
	printf("\n4 - Voltar");
}

void criarCliente(int incrementoCliente, Cliente *repositorioCliente) {
    Cliente c;
    getchar();
    system("cls");
    printf("Digite seu nome: ");
    gets(c.nome);
    printf("Digite sua idade: ");
    scanf("%i", &c.idade);
    getchar();
    printf("Digite seu e-mail: ");
    gets(c.email);
    printf("Digite seu CPF (somente n�meros): ");
    gets(c.cpf);
    printf("Digite seu endere�o: ");
    gets(c.endereco);

    char senhaCliente[20], senhaClienteComp[20];
    int retornoSenhaCliente;
    do{
        printf("Digite uma senha com 8 digitos: ");
        gets(senhaCliente);
        printf("Confirme a senha: ");
        gets(senhaClienteComp);

        retornoSenhaCliente = strcmp(senhaCliente, senhaClienteComp);
        if(retornoSenhaCliente != 0){
            printf("Senhas digitas s�o diferentes! Digite novamente!\n");
        }
    }while(retornoSenhaCliente != 0);
    strcpy(c.senha, senhaCliente);
    int retornoCadastroCliente = cadastrarCliente(c, repositorioCliente, incrementoCliente);

    if(retornoCadastroCliente == 1){
        incrementoCliente++;
        system("cls");
        printf("Cadastrado com sucesso!\n");
        //printf("%i", incremento);
        system("pause");
    }
}

void criarFuncionario(int incrementoFuncionario, Funcionario *repositorioFuncionario) {
    system("cls");
    Funcionario funcionario;
    funcionario.status = 1;
    getchar();
    printf("Qual o nome do funcion�rio?\n");
    gets(funcionario.nome);
    printf("Qual o email?\n");
    gets(funcionario.email);
    printf("Qual o endere�o?\n");
    gets(funcionario.endereco);
    printf("Qual o cpf?\n");
    scanf("%i", &funcionario.cpf);

    char senhaFuncionario[20], senhaFuncionarioComp[20];
    int retornoSenhaFuncionario;
    do{
        getchar();
        printf("Digite uma senha com 8 digitos: ");
        gets(senhaFuncionario);
        printf("Confirme a senha: ");
        gets(senhaFuncionarioComp);

        retornoSenhaFuncionario = strcmp(senhaFuncionario, senhaFuncionarioComp);
        if(retornoSenhaFuncionario != 0){
            printf("Senhas digitas s�o diferentes! Digite novamente!\n");
        }
    }while(retornoSenhaFuncionario != 0);
    strcpy(funcionario.senha, senhaFuncionario);

    if(cadastrarFuncionario(funcionario, incrementoFuncionario, repositorioFuncionario) == 1) {
        printf("Funcion�rio cadastrado com sucesso");
    } else {
        printf("Algum erro aconteceu, tente novamente");
    }
}

int main(int argc, char *argv[]) {
	int op;
	Sistema sistema;
	lerSistema(&sistema, 1);
	int incrementoCliente, incrementoFuncionario, incrementoProduto;
	incrementoCliente = sistema.incrementoCliente;
	incrementoFuncionario = sistema.incrementoFuncionario;
	incrementoProduto = sistema.incrementoProduto;
	
	Cliente repositorioCliente[1000];
	Funcionario repositorioFuncionario[1000];
	Produto repositorioProduto[1000];
	setlocale(LC_ALL, "Portuguese");
	do{
        Cliente c;
		char senhaAdmin[5];
		char idAdmin[5];
		char senhaCliente[8];
		char senhaClienteComp[8];
		char cpf[11];
		char senha[8];
		char codigoProdutoAdmim[10];
		char codigoProdutoFuncionario[10];
		int retornoSenhaCliente;
		int retornoCadastroCliente;
		int retornoValidacao;
		int countErros;
		int indiceRemocaoProdutoAdmin;
		int opRemoverProdutoAdmin;
		int indiceRemocaoProdutoFuncionario;
		int opRemoverProdutoFuncionario;
		FuncionarioResponse funcionarioLogado;
		int opFuncionario;
		//int incremento = 1;
        printarMenuPrincipal();
        scanf("%i", &op);

        switch(op){
           case 1://Cliente
				printarMenuCliente();
				int opCliente;
				scanf("%i", &opCliente);
                ClientResponse clienteLogado;
				switch(opCliente) {
                    case 1: //Login
                        countErros = 0;
                        getchar();
						do{
                            system("cls");
							printf("Digite seu CPF (somente n�meros): ");
							gets(cpf);
							printf("Digite sua senha: ");
							gets(senha);

							clienteLogado = loginCliente(cpf, senha, repositorioCliente);
							//printf("%i", retornoCliente);
							if(clienteLogado.error != 1){
								printf("\nSenha Incorreta, digite novamente!\n");
								countErros++;
								getchar();
							}
						}while(clienteLogado.error != 1 && countErros <= 3);
						system("cls");
						if (clienteLogado.error == 1) {
							printf("Bem vindo %s\n" ,clienteLogado.cliente.nome);
							system("pause");
						}

                    break;

                    case 2: //Cadastro
                    	criarCliente(incrementoCliente, repositorioCliente);
                    break;
					case 3:
					break; //Voltar
                    default:
                    break;
				}

            break;

            case 2://Funcion�rio

                
                funcionarioLogado = loginFuncionarioMain(repositorioFuncionario);
                
                if(funcionarioLogado.error == 0){
                	printf("Funcion�rio n�o encontrado");
                	break;
				}
				
				system("cls");
				printf("Bem vindo %s\n", funcionarioLogado.funcionario.nome);
				PrintarMenuFuncinario();
				scanf("%i", &opFuncionario);

                Produto p;
				switch (opFuncionario)
				{
                    case 1:
                        criarProduto(incrementoProduto, repositorioProduto);  //adiciona um produto novo
                        break;

                    case 2:
                       	getchar();
						printf("REMOVER PRODUTO\n");
						printf("Digite o c�digo do produto: ");
						gets(codigoProdutoFuncionario);
						indiceRemocaoProdutoFuncionario = getIndiceProduto(codigoProdutoAdmim, repositorioProduto);
						if(indiceRemocaoProdutoFuncionario > 0){
							printf("Voc� deseja remover o produto: %s?", repositorioProduto[indiceRemocaoProdutoFuncionario].nome);
							printf("\n1 - Remover");
							printf("\n2 - Cancelar");
							switch(opRemoverProdutoFuncionario){
								case 1:
									removerProduto(codigoProdutoFuncionario, repositorioProduto);
									printf("Produto Removido com sucesso!");
								break;
								case 2: break;	
							}
						}
						else{
							printf("Produto inexistente!");
						}
                    break;

                    case 3:
                        break;
                    break;

                    case 4:
                        break;
                    break;

				}
				break;

			case 3://Administrador
				getchar();
				system("cls");
				countErros = 0;
				char idAdmin[10], senhaAdmin[10];
				do{
					printf("Digite o id do Administrador: ");
					gets(idAdmin);
					printf("Digite a senha do Administrador: ");
					gets(senhaAdmin);
					retornoValidacao = validadarAdmin(idAdmin, senhaAdmin);

					if(retornoValidacao != 1){
						printf("ID ou senha inv�lidos, tente novamente \n");
						printf("Tentativas: %i", countErros);
					}
					countErros++;
				}while(retornoValidacao != 1 && countErros <=3);
				system("cls");

				if(retornoValidacao == 1) { // se logado
					int opAdmin;
					do {
						printarMenuAdmin();
						scanf("%i", &opAdmin);
						switch(opAdmin) {
							case 1://Adicionar Funcion�rio
							    criarFuncionario(incrementoFuncionario, repositorioFuncionario);
								break;
							case 2: //Adicionar produto
							    criarProduto(incrementoProduto, repositorioProduto);
								break;
							case 3: //Remover produto
								getchar();
								printf("REMOVER PRODUTO\n");
								printf("Digite o c�digo do produto: ");
								gets(codigoProdutoAdmim);
								indiceRemocaoProdutoAdmin = getIndiceProduto(codigoProdutoAdmim, repositorioProduto);
								if(indiceRemocaoProdutoAdmin > 0){
									printf("Voc� deseja remover o produto: %s?", repositorioProduto[indiceRemocaoProdutoAdmin].nome);
									printf("\n1 - Remover");
									printf("\n2 - Cancelar");
									switch(opRemoverProdutoAdmin){
										case 1:
											removerProduto(codigoProdutoAdmim, repositorioProduto);
											printf("Produto Removido com sucesso!");
										break;
										case 2: break;	
									}
								}
								else{
									printf("Produto inexistente!");
								}
								
								break;
							case 4: //Alterar produto
								alterarProduto(codigoProdutoAdmim, repositorioProduto);
							case 5:
								break;
							default:
								break;
						}
					}while(opAdmin != 5);
				}
			break;

            default:
                printf("Obrigado pela visita");
                salvarSistema(&sistema, 1);
				salvarCliente(repositorioCliente, incrementoCliente);
				salvarFuncionario(repositorioFuncionario, incrementoFuncionario);
				salvarProduto(repositorioProduto, incrementoProduto);
            break;
        }
	}while(op != 4);
}
