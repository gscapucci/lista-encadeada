#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct turma{
	char* nome;
	float nota;
	struct turma* prox;
} Turma;

/*--------------protitipo-das-funções-------------------*/
Turma* inicializar(void);
Turma* adicionar_inicio(Turma* t, char* a, float b);
Turma* adicionar_fim(Turma* t, char* a, float b);
int remover(Turma* t, char* a);
int obter_tamanho(Turma* t);
int imprimir(Turma* t);
void libera(Turma* t);
int menu();
/*------------------------------------------------------*/

int main(void){
	int erro,opcao;
	float nota;
	char* nome2;
	unsigned int tam=100;
	Turma* t;
	Turma* t2;
	size_t len;


	t=inicializar();
	do{
	system("cls");
	menu();
	printf("opcao:");
	scanf("%d",&opcao);
		if(opcao==1)
		{
			nome2 = malloc(tam * sizeof(char));
			printf("Digite o nome de um aluno:");
			fflush(stdin);
			fgets(nome2, tam, stdin);
			printf("Digite a nota do aluno:");
			scanf("%f",&nota);
			len = strlen(nome2);
			if(nome2[len - 1] == '\n')
				nome2[--len] = 0;
			t=adicionar_inicio(t,nome2,nota);
			printf("Nota e nome adicionados com secesso!\n");
			system("pause");
		}
		if(opcao==2)
		{
			nome2 = malloc(tam * sizeof(char));
			printf("Digite o nome de um aluno:");
			fflush(stdin);
			fgets(nome2, tam, stdin);
			printf("Digite a nota do aluno:");
			scanf("%f",&nota);
			len = strlen(nome2);
			if(nome2[len - 1] == '\n')
				nome2[--len] = 0;
			if(t==NULL)
			t=adicionar_inicio(t,nome2,nota);
			else
			t2=adicionar_fim(t,nome2,nota);
			printf("\nNome e nota foram adicionados com secesso!\n");
			system("pause");
		}
		if(opcao==3)
		{
			printf("Digite o nome do auluno que sera removido:");
			fflush(stdin);
			fgets(nome2, tam, stdin);
			len = strlen(nome2);
			if(nome2[len - 1] == '\n')
				nome2[--len] = 0;
			erro=remover(t,nome2);
			if(erro==0)
				printf("\nAluno removido com sucesso!\n");
			else
				printf("ERRO\n");
			system("pause");
		}
		if(opcao==4)
		{
			erro=imprimir(t);
			if(erro==1)
				printf("lista vazia\n");
			if(erro==2)
				printf("lista impressa com secesso!\n");
			system("pause");
		}
		if(opcao==5)
		{
			libera(t);
			system("pause");
		}
		if(opcao==6)
		{
			erro=obter_tamanho(t);
			if(erro==1)
				printf("Lista vazia!");
			system("pause");
		}
		if(opcao==7)
		{
			system("cls");
			printf("Saindo...\n");
		}
}while(opcao!=7);
}

Turma* inicializar(void){
	return NULL;
}
Turma* adicionar_inicio(Turma* t, char* a, float b){
	Turma* novo_no = (Turma*)malloc(sizeof(Turma));
	novo_no->nome = a;
	novo_no->nota = b;
	novo_no->prox = t;
	return novo_no;
}
Turma* adicionar_fim(Turma* t, char* a, float b){
	Turma* p=t;
	Turma* novo_no = (Turma*)malloc(sizeof(Turma));
	novo_no->nome = a;
	novo_no->nota = b;
	novo_no->prox = NULL;
	while(p->prox!=NULL)
	{
		p=p->prox;
	}
	p->prox=novo_no;
	return novo_no;
}
int imprimir(Turma* t){
	if(t==NULL)
	{
		return 1;
	}
	else
	{
		printf("%s - %3.2f\n", t->nome, t->nota);
		imprimir(t->prox);
	}
	return 0;
}
void libera(Turma* t){
  Turma* p=t;
	int a=0;
	if(t==NULL)
	{
		printf("Lista vazia!\n");
	}
  while (p!=NULL) {
    t=p->prox;
    free(p);
    p=t;
		a++;
  }
	if(a!=0)
	{
		printf("A lista foi apagada!\n");
	}
}
int remover(Turma* t, char* a){
	Turma* p=t;
	Turma* p2=t;


	while(strcmp (a, p->nome) != 0)
	{
		p2=p;
		p=p->prox;
	}
		p2->prox=p->prox;
		free(p);
		return 0;
}
int obter_tamanho(Turma* t){
	int a=1;
	if(t==NULL)
	{
		return 1;
	}
	if(t->prox==NULL)
		a=1;
	while(t->prox!=NULL)
	{
		t=t->prox;
		a++;
	}
	printf("\nA lista tem %d posicoes\n",a);
	return 0;
}
int menu(){
	printf("selecione a opcao desejada:\n\n");
	printf("1-Adicionar no inicio\n");
	printf("2-Adicionar fim\n");
	printf("3-Remover\n");
	printf("4-Listar\n");
	printf("5-Apagar lista\n");
	printf("6-Obter tamanho\n");
	printf("7-Sair\n\n");
}
