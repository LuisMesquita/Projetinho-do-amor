						int countErros = 0;
					/*	getchar();
						char cpf[11];
						char senha[8];
						int retornoCliente;
						int countErros = 0;
						do{
							printf("Digite seu CPF (somente n�meros): ");
							gets(cpf);
							printf("Digite sua senha: ");
							gets(senha);					
							retornoCliente = loginCliente(cpf, senha, &repositorioCliente);
							
							if(retornoCliente != 1){
								printf("CPF ou senha incorretos, digite novamente!");
								printf("Digite seu CPF (somente n�meros): ");
								gets(cpf);
								printf("Digite sua senha: ");
								gets(senha);					
								retornoCliente = loginCliente(cpf, senha, &repositorioCliente);
							}
						}while(retornoCliente != 1);
						system("cls");
						printf("LOGADO COM SUCESSO!");
					}
					else if(opCliente == 2){
						Cliente c;
						getchar();
						printf("Digite seu nome: ");
						gets(c.nome);
						printf("Digite sua idade: ");
						scanf("%i", &c.idade);
						printf("Digite seu email: ");
						gets(c.email);
						printf("Digite seu CPF (somente n�meros): ");
						gets(c.cpf);
						printf("Digite seu endere�o: ");
						gets(c.endereco);
						
						char senha[8], senhaComp[8];
						int retorno;
						do{
							system("cls");
							printf("Digite sua senha: ");
							gets(senha);
							printf("Confirme sua senha: ");
							gets(senhaComp);
							retorno = strcmp(senha, senhaComp);
							
							if(retorno != 0){
								system("cls");
								printf("Voc� digitou senhas diferentes, digite novamente!\n");
								printf("Digite sua senha: ");
								gets(senha);
								printf("Confirme sua senha: ");
								gets(senhaComp);
								retorno = strcmp(senha, senhaComp);
							}
						}while(retorno != 0);
						strcpy(c.senha, senha);
						
						int retornoCadastroCliente;
						int incremento = 0;
						retornoCadastroCliente = cadastrarCliente(c, &repositorioCliente, incremento);
						
						if(retornoCadastroCliente == 1){
							incremento++;
						}*/
