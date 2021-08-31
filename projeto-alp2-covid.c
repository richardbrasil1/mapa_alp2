 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main();

char nome[200];
char cpf[15];
char s;
char sexo[11];
int idade;

struct elemento{
  char pergunta[150];
  int pontos;  
};
struct elemento per_res[]={
  
  {.pergunta = "Question�rio:",.pontos = 0},
  {.pergunta = "O paciente tem febre?",.pontos = 5},
  {.pergunta = "O paciente tem dor de cabe�a?",.pontos = 1},
  {.pergunta = "O paciente tem secre��o nasal ou espirros?",.pontos = 1},
  {.pergunta = "O paciente tem dor/irrita��o na garganta?",.pontos = 1},
  {.pergunta = "O paciente tem tosse seca?",.pontos = 3},
  {.pergunta = "O paciente tem dificuldade respirat�ria?",.pontos = 10},
  {.pergunta = "O paciente tem dores no corpo?",.pontos = 1},
  {.pergunta = "O paciente tem diarr�ia?",.pontos = 1},
  {.pergunta = "O paciente esteve em contato, nos �ltimos 14 dias, com um caso diagnosticado com COVID-19?",.pontos = 10},
  {.pergunta = "O paciente esteve em locais com grande aglomera��o?",.pontos = 3}
  
};


void questionario(){
  
  int i = 0;
  char resp;
  int soma = 0;
  
  FILE *arq;
  
  arq = fopen("cadastro.txt","a");
  system("cls");
  
  if(arq == NULL){
    printf("Falha ao abrir o arquivo!\n");
  }
  
  system("cls");  
  
  printf("------------------------------ATEN��O------------------------------\n");
  printf("Responda todas as perguntas do question�rio com S(sim) ou N(n�o).\n\n");
  
  for(i=0; i <11 ;i++){
    printf("%s \n",per_res[i].pergunta);
    scanf("%c",&resp);
    fflush(stdin);
    fprintf(arq,"%s  � %c � \n",per_res[i].pergunta,resp);
    if(resp == 's' || resp == 'S'){
      soma = soma + per_res[i].pontos;
    }
  }
  
  system("cls");
  
  printf("\t\tPontua��o do paciente: %i\n\n",soma);
  fprintf(arq,"\n\nPontua��o do paciente: %i\n\n",soma);
  
  if(soma >= 0 && soma < 10){
    printf("O Paciente deve ser encaminhado para a ala de risco BAIXO");
    fprintf(arq,"\n\nPaciente encaminhado para ala de risco BAIXO\n\n");
  }
  if(soma >= 10 && soma < 20){
    printf("O Paciente deve ser encaminhado para a ala de risco M�DIO");
    fprintf(arq,"\n\nPaciente encaminhado para ala de risco M�DIO\n\n");
  }
  if(soma >= 20){
    printf("O Paciente deve ser encaminhado para a ala de risco ALTO");
    fprintf(arq,"\n\nPaciente encaminhado para ala de risco ALTO\n\n");
  }
  
  soma = 0;
  
  fprintf(arq,"***************\n\n");
  fclose(arq);
  
  printf("\nPressione ENTER para voltar ao menu");
  getchar();
  main();
  
}

void cadastroPaciente(){
  FILE *arq;
  
  arq = fopen("cadastro.txt","a");
  system("cls");
  
  if(arq == NULL){
    printf("Falha ao abrir o arquivo!\n");
  }
  
  printf("Digite o seu nome completo:\n");
  gets(nome);
  fflush(stdin);
  printf("Digite o sue CPF:\n");
  scanf("%s",&cpf);
  fflush(stdin);
  printf("Informe o seu sexo (M/F):\n");
  scanf("%s",&sexo);
  fflush(stdin);
  printf("Informe a sua idade:\n");
  scanf("%i",&idade);
  
  fprintf(arq,"Nome: %s \n",nome);
  fprintf(arq,"CPF: %s \n",cpf);
  fprintf(arq,"Sexo: %s \n",sexo);
  fprintf(arq,"Idade: %i anos \n\n\n",idade);
  fclose(arq);
  
  printf("Dados Salvos com Sucesso!\n");
  system("pause");
  questionario();
}


int main() {
  setlocale(LC_ALL, "");
  
  int m = 0;
  
  system("cls");
  printf("\t------------MENU-----------\n");
  printf("\t\tSeja bem-vindo\n");
  printf("\n\tEscolha uma das op��es:\n");
  printf("\n\t 1 -> Cadastrar paciente;\n");
  printf("\t 0 -> Sair;\n");
  scanf("%i", &m);
  fflush(stdin);
  
  switch(m){
    case 1:
      cadastroPaciente();
      break;
    case 0:
      printf("\nPrograma finalizado.");
      break;
    default:
    
      break;  
  }
  return 0;
}
