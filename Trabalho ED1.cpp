#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//INICIO DO TRABALHO 

struct lista{
	int ID;
	char nome[25];
	struct lista *prox;
};

typedef struct lista Lista;

Lista *Novo, *fir1, *fir2, *las1, *las2, *aux; 

AdProcesso(){
	
	int choose;

	Novo=(Lista *)malloc(sizeof(Lista));
	printf("Insira o ID: ");
	scanf("%i", &Novo->ID);
	printf("Insira o Nome: ");
	scanf("%s", &Novo->nome);
	printf("Para preferencial digite (1) ou para comum digite(2)?\n");
	scanf("%i", &choose);
	
	if(choose==1)
	{
		if(fir1 == NULL)
		{
			fir1=Novo;
		}else if(fir1 != NULL)
		{
			Novo->prox=fir2;
			las1->prox=Novo;
		}
		las1=Novo;
		las1->prox=fir2;
	}else if(choose == 2)
	{
		if(fir2==NULL)
		{
			fir2=Novo;
		} else if(las2 != NULL)
		{
			las2->prox=Novo;
		}
		
		las2=Novo;
		las2->prox=NULL;
		if(las1 != NULL)
		{
			las1->prox = fir2;
		}
	}
	printf("Concluido.\n");
}

Realizar(){ 

	if(fir1 != NULL)
	{
		aux=fir1;
		if(fir1->prox != fir2)
			fir1=fir1->prox;
		else if(fir1->prox == fir2)
		{
			fir1=NULL;
			las1=NULL;
		}
	}
	
else if(fir1 == NULL && fir2 != NULL)
{
		aux=fir2;
		if(fir2->prox != NULL)
			fir2=fir2->prox;
}
	
	if(las2 == NULL)
	{
		fir2=aux;
		las2=aux;
		las2->prox=NULL;
	}
	else if(las2 != NULL)
	{
		las2->prox=aux;
		las2=aux;
		las2->prox=NULL;
	}

	printf("\nConcluido.\n");
}

EndProcesso(){ 
	if(fir1 == NULL && fir2 == NULL)
	{
		printf("\nLista sem nada!\n\n");
		return (0);
	}
	if(fir1 != NULL)
	{
		aux=fir1;
		if(fir1->prox == fir2)
		{
			fir1 = NULL;
			las1 = NULL;
		}
		else if(fir1->prox != fir2)
		{
			fir1 = aux->prox;
		}
		free(aux);
	}else
	if(fir1 == NULL && fir2 != NULL)
	{
		aux=fir2;
		fir2=aux->prox;
		free(aux);
	}
}

PrintLista(){

	if(fir1 == NULL && fir2 == NULL)
	{
		printf("\nLista sem nada!\n\n");
		return (0);
	}
	else if(fir1!=NULL)
	{
		aux=fir1;
	}
	else if(fir1==NULL && fir2!=NULL)
	{
		aux=fir2;
	}
		
	printf("\nLista:\n");
	while(aux!=NULL)
	{
		printf("%i %s\n", aux->ID, aux->nome);
		aux=aux->prox;
	}
}

main()
{
	setlocale(LC_ALL,"Portuguese");
	
	fir1=NULL;
	fir2=NULL;
	
	las1=NULL;
	las2=NULL;
	
	int opcao;
	
	fir1=NULL;
	las1=NULL;
	
	printf("Por favor adicione um processo...\n");
	AdProcesso();

	Menu:
		printf("\n*************Opções para sua escolha*************\n");
		printf("1- Inserir um novo processo\n");
		printf("2- Rodar processo\n");
		printf("3- Concluir o processo\n");
		printf("4- Mostrar o processo\n");
		printf("5- Sair\n\n");
		printf("Opção: ");
		scanf("%i", &opcao);
		
		switch(opcao){
			case 1:
				
				printf("1- Inserir um novo processo\n");
				AdProcesso();
				
			break;
			
			case 2:
				
				printf("2- Rodar processos\n");
				Realizar();
				
			break;
			
			case 3:
				
				printf("3- Concluir o processo\n");
				EndProcesso();
				
			break;
			
			case 4:
				
				printf("4- Mostrar o processo\n");
				PrintLista();
				
			break;
			
			case 5:
				
				printf("5- Sair\n\n");
				return(0);
				
			break;
		}
	goto Menu;

	return(0);
}
