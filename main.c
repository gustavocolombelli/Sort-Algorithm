#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Bubble 0
#define Merge 1
#define Quick 2
#define Radix 3
#define Shell 4
//Configs
#define QUANTIDADE_ELEMENTOS 250

/*
 Trabalho de Estrutura de Dados II
 Autores: Gustavo Colombelli Alessio e Bruno Luiz Schuster

*/


// ----------------------- Algoritimos de Ordenacao ---------------------------------
void bubble(int vetor[]) {
    int k, j, aux;

    for (k = 1; k <= QUANTIDADE_ELEMENTOS; k++) {
        printf("\n------>[%d]<------\n", k);

        for (j = 0; j <= QUANTIDADE_ELEMENTOS; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    printf("\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");
}

void merge(int vetor[]){}
void quick(int vetor[]){}
void radix(int vetor[]){}
void shell(int vetor[]){}




void gerarPiorCaso(int *vetor){
    int i;
    printf("Gerando vetor...\n");
    int quantidade_elementos = QUANTIDADE_ELEMENTOS;

    for (i = 0; i < QUANTIDADE_ELEMENTOS; i++) {
        vetor[i] = quantidade_elementos--;
    }
    printf("Vetor gerado com sucesso!\n\n");
}

// -------------- Funções responsaveis para geração de relatório --------------------

typedef struct infoAlgoritimo{
    char nomeAlgoritimo [25];
    char inicioOrdenacao[80];
    char fimOrdenacao[80];
}_infoAlgoritimo;

void timeStamp(char * buffer){

  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%I:%M:%S",timeinfo);
}

void relatorioOrdenacao(_infoAlgoritimo algoritimoOrdenacao[], int tamVetor){
    int i;


    printf("RELATORIO - TEMPO DE ORDENACAOO\n\nQUANTIDADE DE ELEMENTOOS: %d\n\nALGORITIMO\tINICIO    |  FINAL\n", QUANTIDADE_ELEMENTOS);

    for(i=0;i<5;i++){
        printf("\n%s\t\t%s  |  %s",algoritimoOrdenacao[i].nomeAlgoritimo,
                                                algoritimoOrdenacao[i].inicioOrdenacao,
                                                algoritimoOrdenacao[i].fimOrdenacao);
    }
 printf("\n\n\n");
}

int main(){
  int i;
  int vetorPiorCaso[QUANTIDADE_ELEMENTOS];
  _infoAlgoritimo algoritimoOrdenacao[5];
  gerarPiorCaso(vetorPiorCaso);

   //--------Bubble
  strcpy(algoritimoOrdenacao[Bubble].nomeAlgoritimo,"Bubble");
  timeStamp(algoritimoOrdenacao[Bubble].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  bubble(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Bubble].fimOrdenacao);

  //--------Merge
  strcpy(algoritimoOrdenacao[Merge].nomeAlgoritimo,"*Merge");
  timeStamp(algoritimoOrdenacao[Merge].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  merge(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Merge].fimOrdenacao);

   //--------Quick
  strcpy(algoritimoOrdenacao[Quick].nomeAlgoritimo,"*Quick");
  timeStamp(algoritimoOrdenacao[Quick].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  quick(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Quick].fimOrdenacao);

   //--------Radix
  strcpy(algoritimoOrdenacao[Radix].nomeAlgoritimo,"*Radix");
  timeStamp(algoritimoOrdenacao[Radix].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  radix(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Radix].fimOrdenacao);

   //--------Shell
  strcpy(algoritimoOrdenacao[Shell].nomeAlgoritimo,"*Shell");
  timeStamp(algoritimoOrdenacao[Shell].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  shell(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Shell].fimOrdenacao);

  relatorioOrdenacao(algoritimoOrdenacao, (sizeof(algoritimoOrdenacao)/sizeof(algoritimoOrdenacao[0])));

  system("\n\nPAUSE");
  return 0;
}
