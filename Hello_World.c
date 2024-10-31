#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h>// bilbioteca de alocação de texto por região
#include <string.h>//biblioteca responsavel por cuidar das strings


int registro(){
	
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("digite o CPF a ser cadastrado :");
	
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w");  // cria o arquivo no banco de dados
	fprintf(file, cpf);	 // salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado :");
	
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consulta(){
	
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem

	char cpf [40];
	char conteudo [200];
	
	
	printf("digite o cpf a ser consultado: ");
	
	scanf("%s", cpf);
	
	FILE *file;
	
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("não foi possivel abrir o arquivo, não localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\n Essas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar(){
	
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem

	char cpf [40];
	
	printf("digite o cpf a ser deletado: ");
	
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("usuario não se encontra no sistema \n");
		system("pause");
	}

}

int main(){
	
	int opcao = 0; // definindo variaveis
	int laco = 1;
	
	for(laco=1; laco==1;)
	{
		
		
		
	
	
	
		setlocale(LC_ALL, "portuguese"); // definindo a linguagem
		
		system("cls");
		
		printf("### Cartório da EBAC ### \n\n"); // inicio do menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - registrar nomes: \n");
		printf("\t2 - consultar nomes: \n");
		printf("\t3 - deletar nome: \n");
		printf("Opção: "); // fim do menu
		
		scanf("%d", & opcao); // armazenando a escolha do usuario
		
		system("cls");
		
		switch(opcao){
			case 1:	
			registro();
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n");
			system("pause");
			break;
		}
		
		
	}	
}

