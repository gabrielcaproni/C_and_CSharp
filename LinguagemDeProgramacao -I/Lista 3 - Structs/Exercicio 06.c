#include <stdio.h>
#include <string.h>

typedef struct
{
	char nomePessoa[30];
	char data[20];
	char emprestado;
}tdata;

typedef struct
{
	char titulo[30];
	char console[15];
	int ano;
	int ranking;
	tdata emprestimo;
}tjogo;

int qtd = 0;

//_________________________________________________________

void adicionaJogo(tjogo jogo[]){
	printf("Titulo do jogo: ");
	fflush(stdin);
	gets(jogo[qtd].titulo);
	
	printf("Console: ");
	fflush(stdin);
	gets(jogo[qtd].console);
	
	printf("Ano de lancamento: ");
	fflush(stdin);
	scanf("%d", &jogo[qtd].ano);
	
	printf("Ranking: ");
	fflush(stdin);
	scanf("%d", &jogo[qtd].ranking);
	
	jogo[qtd].emprestimo.emprestado = 'N';
	
	qtd++;
}

//_________________________________________________________

void listaJogos(tjogo jogo[])
{
	
	for(int i = 0; i < qtd; i++)
	{
		printf("*** Jogo %d ***\n", i + 1);
		printf("Titulo: %s\n", jogo[i].titulo);
		printf("Console: %s\n", jogo[i].console);
		printf("Ano de publicacao: %d\n", jogo[i].ano);
		printf("Ranking: %d\n", jogo[i].ranking);
		printf("Emprestado: %c\n", jogo[i].emprestimo.emprestado);
		printf("------------------------\n");
	}
	
}

//_________________________________________________________

void fazEmprestimo(tjogo jogo[], int cod)
{
	printf("Nome da pessoa: ");
	fflush(stdin);
	gets(jogo[cod - 1].emprestimo.nomePessoa);
	
	printf("Data do emprestimo: ");
	fflush(stdin);
	gets(jogo[cod - 1].emprestimo.data);
	
	jogo[cod - 1].emprestimo.emprestado = 'S';	
}

//_________________________________________________________

int filtraTitulo(tjogo jogo[], char titulo[30])
{
	char tituloAuxiliar[30];
	int res = -1;
	
	for(int i = 0; i < qtd; i++){
		strcpy(tituloAuxiliar, jogo[i].titulo);
		strupr(tituloAuxiliar);
		if(strcmp(titulo, tituloAuxiliar) == 0)
		{
			printf("*** Jogo %d ***\n", i + 1);
			printf("Titulo: %s\n", jogo[i].titulo);
			printf("Console: %s\n", jogo[i].console);
			printf("Ano de publicacao: %d\n", jogo[i].ano);
			printf("Ranking: %d\n", jogo[i].ranking);
			printf("Emprestado: %c\n", jogo[i].emprestimo.emprestado);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
	
}

//_________________________________________________________

int filtraConsole(tjogo jogo[], char console[15])
{
	char consAuxiliar[15];
	int res = -1;
	
	for(int i = 0; i < qtd; i++){
		strcpy(consAuxiliar, jogo[i].console);
		strupr(consAuxiliar); 
		if(strcmp(console, consAuxiliar) == 0)
		{
			printf("*** Jogo %d ***\n", i + 1);
			printf("Titulo: %s\n", jogo[i].titulo);
			printf("Console: %s\n", jogo[i].console);
			printf("Ano de publicacao: %d\n", jogo[i].ano);
			printf("Ranking: %.2f\n", jogo[i].ranking);
			printf("Emprestado: %c\n", jogo[i].emprestimo.emprestado);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
	
}

//_________________________________________________________

int listaEmp(tjogo jogo[])
{
	int res = -1;
	
	for(int i = 0; i < qtd; i++){
		if(jogo[i].emprestimo.emprestado == 'S')
		{
			printf("Jogo: %s\n", jogo[i].titulo);
			printf("Emprestado para: %s\n", jogo[i].emprestimo.nomePessoa);
			printf("Data do emprestimo: %s\n", jogo[i].emprestimo.data);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
	
}

//_________________________________________________________

int menu()
{
	int opcao;
	
	printf("*** Biblioteca de Jogos ***\n");
	printf("1 - Cadastrar jogo\n");
	printf("2 - Listar jogos\n");
	printf("3 - Procurar por titulo\n");
	printf("4 - Filtrar por console\n");
	printf("5 - Fazer um emprestimo\n");
	printf("6 - Listar emprestimos\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	printf("\n");
	return opcao;
}

//_________________________________________________________

void main(){
	
	tjogo jogos[100];
	char tituloBusca[30], consoleBusca[15];
	int emp, op, res;
	
	do{
		op = menu();
		
		switch(op){
			case 1:
				adicionaJogo(jogos);
				break;
				
			case 2:
				listaJogos(jogos);
				break;
				
			case 3:
				printf("Insira o titulo do jogo: ");
				fflush(stdin);
				gets(tituloBusca);
				strupr(tituloBusca);
				res = filtraTitulo(jogos, tituloBusca);
				if(res == -1)
				{
					printf("Jogo nao encontrado!");
				}
				break;
				
			case 4:
				printf("Insira o nome do console: ");
				fflush(stdin);
				gets(consoleBusca);
				strupr(consoleBusca);
				res = filtraConsole(jogos, consoleBusca);
				if(res == -1)
				{
					printf("Console nao encontrado!");
				}
				break;
				
			case 5:
				listaJogos(jogos);
				printf("Insira o codigo do jogo: ");
				scanf("%d", &emp);
				fazEmprestimo(jogos, emp);
				break;
				
			case 6:
				res = listaEmp(jogos);
				if(res == -1)
				{
					printf("Nao ha jogos emprestados!");
				}
				break;
				
			case 0:
				printf("Saindo...\n");
				break;
				
			default:
				printf("Opcao invalida!!!\n");
				break;
				
		}
		getch();
		system("cls");
		
	}while(op != 0);
	
}
