#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Cliente.h"
#include "Funcionario.h"
#include "Produto.h"
#include "Sistema.h"
#include "Loja.h"

#define MAX_LEN 128

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

void logo(){
    char *filename = "teste.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr);

    fclose(fptr);
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
        system ("pause");
}

void esqueciSenha(Cliente *repositorioCliente){
	getchar();
	system("cls");
	char cpf[11];
	char email[30];
	char novaSenha[8];
	char senhaComp[8];
	int retornoSenhaCliente;
	
	printf("Digite seu CPF: ");
	gets(cpf);
	printf("Digite seu e-mail: ");
	gets(email);
	do{
        printf("Digite uma senha com 8 digitos: ");
        gets(novaSenha);
        printf("Confirme a senha: ");
        gets(senhaComp);

        retornoSenhaCliente = strcmp(novaSenha, senhaComp);
        if(retornoSenhaCliente != 0){
            printf("Senhas digitas s�o diferentes! Digite novamente!\n");
        }
    }while(retornoSenhaCliente != 0);
    alterarSenhaCliente(cpf, email, novaSenha, repositorioCliente);
    printf("Senha alterada com sucesso!");
    system("pause");
}
FuncionarioResponse loginFuncionarioMain(Funcionario *repositorioFuncionario){
	getchar();
	int i, a = 0;
	char c;
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
		printf("Digite sua senha: ");
	   	do{
	       c=getch();
	       if(isprint(c)){       //Analisa se o valor da vari�vel c � imprimivel
	       senhaFuncionario[a]=c;  //Se for, armazena o caractere 
	       a++;
	       printf("*");          //imprime o * Anterisco
	       }
	       else if(c==8&&a){     //8 � o caractere BackSpace na tabela ASCII, && a analisa se a � diferente de 0
	       senhaFuncionario[a]='\0';
	       a--;
	       printf("\b \b");       //Apagando o caractere digitado
	       } 
	   	}while(c!=13); 
        printf("\n");
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
    getchar();
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
    printf("\n");
    alterarCadastroProduto(codigo, pa, repositorioProduto);
}

void criarProduto(int incrementoProduto, Produto *repositorioProduto){
	Produto p;
    getchar();
    system("cls");
    printf("Digite o nome do produto: ");
    gets(p.nome);
    printf("Digite o valor do produto: ");
    scanf("%f", &p.valor);
    getchar();
    printf("Digite a descri��o do produto: ");
    gets(p.descricao);
    printf("Digite a categoria do produto: ");
    gets(p.categoria);
    printf("Digite o tamanho do produto: ");
    gets(p.tamanho);
    printf("Digite o codigo do produto: ");
    gets(p.codigo);
    printf("Digite a quantidade que deseja adicionar: ");
    scanf("%i", &p.qtd_Itens);
    printf("\n");
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
    printf("\n3 - Esqueci a senha");
    printf("\n4 - Voltar\n");
}

void printarMenuAdmin() {
    system("cls");
    printf("SELECIONE UMA OP��OO: ");
    printf("\n1 - Adicionar Funcion�rio");
    printf("\n2 - Adicionar Produto");
    printf("\n3 - Remover Produto");
    printf("\n4 - Alterar Produto");
    printf("\n5 - Adicionar Itens");
    printf("\n6 - Logout\n");
}

void PrintarMenuFuncinario(){
	system("cls");
	printf("TELA DE FUNCIONARIO");
	printf("\nSELECIONE UMA OP��O");
	printf("\n1 - Cadastrar produto");
	printf("\n2 - Remover produto");
	printf("\n3 - Alterar produto");
	printf("\n4 - Voltar\n");
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
    gets(funcionario.cpf);

    char senhaFuncionario[20], senhaFuncionarioComp[20];
    int retornoSenhaFuncionario;
    do{
        fflush(stdin);
        printf("Digite uma senha com 8 digitos: ");
        gets(senhaFuncionario);
        fflush(stdin);
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
        system("pause");
    } else {
        printf("Algum erro aconteceu, tente novamente");
    }
}

int main(int argc, char *argv[]) {
	int op;
	Cliente repositorioCliente[1000];
	Funcionario repositorioFuncionario[1000];
	Produto repositorioProduto[1000];
	int incrementoCliente, incrementoFuncionario, incrementoProduto;
	
	lerIncrementoCliente(&incrementoCliente, 1);
	lerIncrementoFuncionario(&incrementoFuncionario, 1);
	lerIncrementoProduto(&incrementoProduto, 1);
	
	lerCliente(repositorioCliente, incrementoCliente);
	lerFuncionario(repositorioFuncionario, incrementoFuncionario);
	lerProduto(repositorioProduto, incrementoProduto);
	
	system("color f1");
	setlocale(LC_ALL, "Portuguese");
	
	logo();
	do{
        Cliente c1;
        char c;
        int a = 0;
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
		int qtd_ItensAdmin;
		FuncionarioResponse funcionarioLogado;
		int opFuncionario;
		int i;
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
                            fflush(stdin);
							printf("Digite seu CPF (somente n�meros): ");
							gets(cpf);
							fflush(stdin);
							printf("Digite sua senha: ");
							
							do{
					           c=getch();
					           if(isprint(c)){       //Analisa se o valor da vari�vel c � imprimivel
					           senha[a]=c;  		 //Se for, armazena o caractere 
					           a++;
					           printf("*");          //imprime o * Anterisco
					           }
					           else if(c==8&&a){     //8 � o caractere BackSpace na tabela ASCII, && a analisa se a � diferente de 0
					           senha[a]='\0';
					           a--;
					           printf("\b \b");       //Apagando o caractere digitado
					           } 
					       }while(c!=13); 

							clienteLogado = loginCliente(cpf, senha, repositorioCliente);
							
							if(clienteLogado.error != 1){
								printf("\nSenha Incorreta, digite novamente!\n");
								countErros++;
								getchar();
							}
						}while(clienteLogado.error != 1 && countErros <= 3);
						system("cls");
						printf("LOLJA\n");
						if (clienteLogado.error == 1) {
							printf("Bem vindo, %s\n" ,clienteLogado.cliente.nome);
							system("pause");
							iniciarLoja(repositorioProduto, incrementoProduto);
						}

                    break;

                    case 2: //Cadastro
                    	criarCliente(incrementoCliente, repositorioCliente);
                    	incrementoCliente++;
                    break;
                    case 3:
                    	esqueciSenha(repositorioCliente);
						break; 
					case 4:
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
				system("pause");
				PrintarMenuFuncinario();
				scanf("%i", &opFuncionario);

                Produto p;
				switch (opFuncionario)
				{
                    case 1:
                        criarProduto(incrementoProduto, repositorioProduto);  //adiciona um produto novo
                        incrementoProduto++;
                        break;

                    case 2:
                       	getchar();
						printf("REMOVER PRODUTO\n");
						printf("Digite o c�digo do produto: ");
						gets(codigoProdutoFuncionario);
						
						indiceRemocaoProdutoFuncionario = getIndiceProduto(codigoProdutoAdmim, repositorioProduto);
						printf("%i %i", indiceRemocaoProdutoFuncionario, codigoProdutoFuncionario);
						
						if(indiceRemocaoProdutoFuncionario > 0){
							getchar();
							printf("Voc� deseja remover o produto: %s?", repositorioProduto[indiceRemocaoProdutoFuncionario].nome);
							printf("\n1 - Remover");
							printf("\n2 - Cancelar\n");
							scanf("%i", opRemoverProdutoFuncionario);
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
				//LOGIN BUGADO AP�S PRIMEIRA TENTATIVA
				getchar();
				system("cls");
				countErros = 0;
				char idAdmin[10], senhaAdmin[10];
				do{
					printf("Digite o id do Administrador: ");
					gets(idAdmin);
					printf("Digite a senha do Administrador: ");
					do{
			           c=getch();
			           if(isprint(c)){       //Analisa se o valor da vari�vel c � imprimivel
			           senhaAdmin[a]=c;  //Se for, armazena o caractere 
			           a++;
			           printf("*");          //imprime o * Anterisco
			           }
			           else if(c==8&&a){     //8 � o caractere BackSpace na tabela ASCII, && a analisa se a � diferente de 0
			           senhaAdmin[a]='\0';
			           a--;
			           printf("\b \b");       //Apagando o caractere digitado
			           } 
			        }while(c!=13); 
                    
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
							    incrementoFuncionario++;
								break;
							case 2: //Adicionar produto
							    criarProduto(incrementoProduto, repositorioProduto);
							    incrementoProduto++;
								break;
							case 3: //Remover produto
								getchar();
								printf("REMOVER PRODUTO\n");
								printf("Digite o c�digo do produto: ");
								gets(codigoProdutoAdmim);
								indiceRemocaoProdutoAdmin = getIndiceProduto(codigoProdutoAdmim, repositorioProduto);
								if(indiceRemocaoProdutoAdmin >= 0){
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
							case 5://Adiconar itens
								getchar();
								system("cls");
								printf("ADICIONAR ITENS\n");
								printf("Digite o c�digo do produto: ");
								gets(codigoProdutoAdmim);
								indiceRemocaoProdutoAdmin = getIndiceProduto(codigoProdutoAdmim, repositorioProduto);
								
								printf("Existem %d itens deste produto na LOLJA!\n", repositorioProduto[indiceRemocaoProdutoAdmin].qtd_Itens);
								printf("Digite a quantidade de itens que ser�o adicionados: ");
								scanf("%i", &qtd_ItensAdmin);
								getchar();
								
								if(indiceRemocaoProdutoAdmin >= 0){
									printf("Voc� deseja adicionar itens ao produto: %s?", repositorioProduto[indiceRemocaoProdutoAdmin].nome);
									printf("\n1 - Adicionar");
									printf("\n2 - Cancelar\n");
									gets(opRemoverProdutoAdmin);
									switch(opRemoverProdutoAdmin){
										//N�O EST� FUNCIONANDO
										case 1:
											adicionarItens(codigoProdutoAdmim, qtd_ItensAdmin, repositorioProduto);
											printf("Itens adicionados com sucesso!");
											printf("O produto %s tem %i itens.", repositorioProduto[indiceRemocaoProdutoAdmin].nome, repositorioProduto[indiceRemocaoProdutoAdmin].qtd_Itens);
										break;
										case 2: break;	
									}
								}
								else{
									printf("Produto inexistente!");
								}
								break;
							case 6:
								break;
							default:
								break;
						}
					}while(opAdmin != 6);
				}
			break;

            default:
                printf("Obrigado pela visita");
                salvarIncrementoCliente(incrementoCliente, 1);
                salvarIncrementoFuncionario(incrementoFuncionario, 1);
                salvarIncrementoProduto(incrementoProduto, 1);
				salvarCliente(repositorioCliente, incrementoCliente);
				salvarFuncionario(repositorioFuncionario, incrementoFuncionario);
				salvarProduto(repositorioProduto, incrementoProduto);
            break;
        }
	}while(op != 4);
}
