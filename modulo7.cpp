#include <stdio.h>  //bliblioteca de comunica��o com com o usu�rio 
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o 
#include <string.h>  //bliblioteca responsav�l pelas strings
        //variavel para registro e etc 	
        int registro()
   {
   	    char arquivo  [40]; //inicio cria��o de vari�vel/string
        char cpf      [40];
        char nome     [40];
		char sobrenome[40];
		char cargo    [40];		
		
		printf("Digite o cpf a ser cadastrado:");
		scanf ("%s",cpf);   //caixinha de texto para o usuario poder digitar			
			
	    strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	    
     	FILE *file;    //cria arquivo
     	file = fopen(arquivo, "w"); //cria arquivo o uso do "w" � para criar o arquivo
     	fprintf(file,cpf); //salvo o valor da variavel
     	fclose (file);    //fecha o arquivo
     	
     	file =fopen(arquivo, "a"); // "a" para atualizar o arquivo e n�o criar outro
     	fprintf(file,",");        // "fprinf" � o fprintf � para escrever no arquivo(no caso foi usado para dar espa�amento com a virgulaO 
     	fclose(file);
     	
     	printf("Digite o nome a ser cadastrado: ");
     	scanf("%s",nome);          //abre a caixa para o usuario poder digitar (%s no scan � quando � string)
     	
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
      	printf("Usuario n�o foi encontrado!.\n");
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
	     file = fopen(cpf,"r");  // o "r" � para "consultar"( readind)
	     
	     if (file == NULL)   
	     {
	     printf("N�o foi possivel abrir o arquivo, N�o foi localizado.\n");	
		 }
	     
	    
	     while(fgets(conteudo, 200, file) != NULL)
	     {
	     	printf("Essas s�o informa��es do usu�rio: ");
	     	printf("%s", conteudo);
	     	printf("\n\n");
		 }
		 
		 system("pause");
	 
	    
	    
     	}	
	  	
        int main() 
        {
      	//Variavel das op��es do menu
    	int opcao=0;
     	int loop=1;
	
     	for(loop=1;loop=1;)//looping
		  
        {    //chave/abra�o	
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem para que o acento funcione
        system("cls");
     	printf("### Painel ###\n\n"); //incio do menu/painel
     	printf("Escolha a op��o desejada:\n\n");
     	printf("\t1 - Registro nomes\n\n");
     	printf("\t2 - Apagar Nomes\n\n");	
     	printf("\t3 - Consultar Nomes\n\n");    
		printf("\t4 - Sair do sistema\n\n\n");
     	printf("Op��o:");
	
     	scanf("%d", &opcao);//armazenando a escolha do usuario/abilitar para escrever
	    system("pause");
     	system("cls"); //responsavel por limpar a tela /clear
	
      	switch(opcao)//usando a variavel que tinha criado anteriormente para n�o ter que ficar usando varios "if"
      	{
	 	case 1:
	 	registro();	//chamada de fun��es
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
 	    	
 	    printf("Est� op��o n�o est� disponivel\n");
	    system("pause");
	    break;
	    }

        }//final da chave de looping	
    }
