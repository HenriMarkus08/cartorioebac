#include <stdio.h> //bibliotecas
#include <locale.h>
#include <stdlib.h>
#include <string.h>
int registro(){ //registrar usuário

setlocale(LC_ALL, "Portuguese"); //linguagem

    //variáveis
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf); 

    strcpy(arquivo, cpf); //copiar os valores da string

    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); // cria a pasta e "w" escreve
    fprintf(file,cpf); //salvo a variável e seu valor
    fclose(file); //fechar arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado:\n"); //nome
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:\n"); //sobrenome
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:\n"); //cargo
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

 	system("pause");
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s", cpf);
	 
	FILE *file;
    file = fopen(cpf,"r"); //"r" é remove
    
    if(file == NULL){
    	printf("Não foi possível abrir o arquivo\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("Essas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar(){
	
	setlocale(LC_ALL, "Portuguese");
		
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){
		printf("Usuário não se encontra no sistema\n");
		system("pause");
		
	}
	
}

int main(){ //principal
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;){ //inicio do laço
		
	system("cls"); //limpar tela
	
	setlocale(LC_ALL, "Portuguese"); //linguagem em português
	
	printf("Projeto Cartório da EBAC\n"); 
	printf("Selecione a opção no menu:\n");
	printf("\t1 - Registrar nomes:\n");
	printf("\t2 - Consultar nomes:\n");
	printf("\t3 - Deletar nomes:\n");
	printf("\tOpção: \n");
	
		scanf("%d", &opcao);
	
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
			printf("Essa opção é inválida\n");
			system("pause");
			break;
		}
	}
	return 0;
}

