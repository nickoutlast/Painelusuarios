#include <stdio.h>  //bliblioteca de comunicação com com o usuário 
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região 
#include <string.h>  //bliblioteca responsavél pelas strings
        //variavel para registro e etc 	
        int registro()
   {
   	    char arquivo  [40]; //inicio criação de variável/string
        char cpf      [40];
        char nome     [40];
		char sobrenome[40];
		char cargo    [40];		
		
		printf("Digite o cpf a ser cadastrado:");
		scanf ("%s",cpf);   //caixinha de texto para o usuario poder digitar			
			
	    strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	    
     	FILE *file;    //cria arquivo
     	file = fopen(arquivo, "w"); //cria arquivo o uso do "w" é para criar o arquivo
     	fprintf(file,cpf); //salvo o valor da variavel
     	fclose (file);    //fecha o arquivo
     	
     	file =fopen(arquivo, "a"); // "a" para atualizar o arquivo e não criar outro
     	fprintf(file,",");        // "fprinf" é o fprintf é para escrever no arquivo(no caso foi usado para dar espaçamento com a virgulaO 
     	fclose(file);
     	
     	printf("Digite o nome a ser cadastrado: ");
     	scanf("%s",nome);          //abre a caixa para o usuario poder digitar (%s no scan é quando é string)
     	
     	file = fopen(arquivo, "a");
     	fprintf(file,nome);
     	fclose(file);
     	
     	file =fopen(arquivo, "a");
     	fprintf(file,",");
     	fclose(file);
     	
     	printf("Digite o sobrenome a ser cadastrado: ");
     	scanf("%s", sobrenome);
    
    
        file = fopen(arquivo, "a");
        fprintf(file,sobrenome);
        fclose(file);
        
        file =fopen(arquivo, "a");
     	fprintf(file,",");
     	fclose(file);
        
        
        
        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s",cargo);
        
        file =fopen(arquivo, "a");
        fprintf(file,cargo);
        fclose(file);
        
        
        
        
        system("pause");  
 	}
	 
        int apagar()
        
        {
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	if(file == NULL)
	
      {
      	printf("Usuario não foi encontrado!.\n");
      	system("pause");//parar para dar tempo do usuario ler o programa
	  }
	  
	
        }

        int consultar()
        {
         setlocale(LC_ALL, "Portuguese"); 
		 char cpf[40];
		 char conteudo[200];	
		 
		 printf("Digite o cpf a ser registrado: ");
		 scanf("%s",cpf);
		
	     FILE *file;
	     file = fopen(cpf,"r");  // o "r" é para "consultar"( readind)
	     
	     if (file == NULL)   
	     {
	     printf("Não foi possivel abrir o arquivo, Não foi localizado.\n");	
		 }
	     
	    
	     while(fgets(conteudo, 200, file) != NULL)
	     {
	     	printf("Essas são informações do usuário: ");
	     	printf("%s", conteudo);
	     	printf("\n\n");
		 }
		 
		 system("pause");
	 
	    
	    
     	}	
	  	
        int main() 
        {
      	//Variavel das opções do menu
    	int opcao=0;
     	int loop=1;
	
     	for(loop=1;loop=1;)//looping
		  
        {    //chave/abraço	
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem para que o acento funcione
        system("cls");
     	printf("### Painel ###\n\n"); //incio do menu/painel
     	printf("Escolha a opção desejada:\n\n");
     	printf("\t1 - Registro nomes\n\n");
     	printf("\t2 - Apagar Nomes\n\n");	
     	printf("\t3 - Consultar Nomes\n\n");    
		printf("\t4 - Sair do sistema\n\n\n");
     	printf("Opção:");
	
     	scanf("%d", &opcao);//armazenando a escolha do usuario/abilitar para escrever
	    system("pause");
     	system("cls"); //responsavel por limpar a tela /clear
	
      	switch(opcao)//usando a variavel que tinha criado anteriormente para não ter que ficar usando varios "if"
      	{
	 	case 1:
	 	registro();	//chamada de funções
		break;
		 
	 	case 2:
	 	apagar();
 	    break;
 	    
 	    case 3:
 	    consultar();
 	    break;
 	    
 	    case 4:
 	    printf("Obrigado por utilizar o sistema!\n");	
 	    return 0;
 	    break;
 	    default:
 	    	
 	    printf("Está opção não está disponivel\n");
	    system("pause");
	    break;
	    }

        }//final da chave de looping	
    }
