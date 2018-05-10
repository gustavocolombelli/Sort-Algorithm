#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Bubble 0
#define Merge 1
#define Quick 2
#define Radix 3
#define Shell 4
//Configs
#define QUANTIDADE_ELEMENTOS 150

/*
 Autogres: Gustavo Colombelli Alessio e Bruno Luiz Shuszter
*/


// ----------------------- Algoritimos de Ordenacao ---------------------------------
void bubble(int vetor[]) {
    int k, j, aux;

    for (k = 1; k <= QUANTIDADE_ELEMENTOS; k++) {
        printf("\n------>[%d]<------\n", k);

        for (j = 0; j <= QUANTIDADE_ELEMENTOS - 1; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    printf("\n---------\n");
}





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

typedef struct tempoOrdenacao{
    char inicioOrdenacao[80];
    char fimOrdenacao[80];
}_tempoOrdenacao;

void timeStamp(char * buffer){

  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%I:%M:%S",timeinfo);
}

void relatorioOrdenacao(_tempoOrdenacao algoritimoOrdenacao[]){

    printf("RELATORIO - TEMPO DE ORDENACAOO\n\nQUANTIDADE DE ELEMENTOOS: %d\n\nALGORITIMO\tINICIO        |        FINAL\n", QUANTIDADE_ELEMENTOS);

    printf("\nBubble\t\t%s      |        ", algoritimoOrdenacao[Bubble].inicioOrdenacao);
    printf("%s", algoritimoOrdenacao[Bubble].fimOrdenacao);

    printf("\nMerge\t\t%s      |        ", algoritimoOrdenacao[Merge].inicioOrdenacao);
    printf("%s", algoritimoOrdenacao[Merge].fimOrdenacao);

    printf("\nQuick\t\t%s      |        ", algoritimoOrdenacao[Quick].inicioOrdenacao);
    printf("%s", algoritimoOrdenacao[Quick].fimOrdenacao);

    printf("\nRadix\t\t%s      |        ", algoritimoOrdenacao[Radix].inicioOrdenacao);
    printf("%s", algoritimoOrdenacao[Radix].fimOrdenacao);

    printf("\nShell\t\t%s      |        ", algoritimoOrdenacao[Shell].inicioOrdenacao);
    printf("%s\n\n\n\n\n\n\n\n\n", algoritimoOrdenacao[Shell].fimOrdenacao);

}

int main(){
  int i;
  int vetorPiorCaso[QUANTIDADE_ELEMENTOS];
  _tempoOrdenacao algoritimoOrdenacao[5];
  gerarPiorCaso(vetorPiorCaso);


   //--------Bubble
  timeStamp(algoritimoOrdenacao[Bubble].inicioOrdenacao);
  bubble(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Bubble].fimOrdenacao);


  //--------Merge
  timeStamp(algoritimoOrdenacao[Merge].inicioOrdenacao);

  timeStamp(algoritimoOrdenacao[Merge].fimOrdenacao);


   //--------Quick
  timeStamp(algoritimoOrdenacao[Quick].inicioOrdenacao);

  timeStamp(algoritimoOrdenacao[Quick].fimOrdenacao);


   //--------Radix
  timeStamp(algoritimoOrdenacao[Radix].inicioOrdenacao);

  timeStamp(algoritimoOrdenacao[Radix].fimOrdenacao);


   //--------Shell
  timeStamp(algoritimoOrdenacao[Shell].inicioOrdenacao);

  timeStamp(algoritimoOrdenacao[Shell].fimOrdenacao);

  relatorioOrdenacao(algoritimoOrdenacao);

  return 0;
}
