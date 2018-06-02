#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define Bubble 0
#define Merge 1
#define Quick 2
#define Radix 3
#define Shell 4
#define Heap 5
//Configs
#define QUANTIDADE_ELEMENTOS 100000

/*
 Trabalho de Estrutura de Dados II
 Autores: Gustavo Colombelli Alessio e Bruno Luiz Schuster
*/


// ----------------------- Algoritimos de Ordenacao ---------------------------------
void bubble(int vetor[]) {
    int k, j, aux;

    for (k = 1; k <= QUANTIDADE_ELEMENTOS; k++) {
        //printf("\n------>[%d]<------\n", k);

        for (j = 0; j <= QUANTIDADE_ELEMENTOS; j++) {
            //printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    //printf("\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");
}

void merge(int vetor[]){
    int comeco = 0, meio = (QUANTIDADE_ELEMENTOS/2)+1, fim = QUANTIDADE_ELEMENTOS+1, aux = 0;
    int vetAux[QUANTIDADE_ELEMENTOS];

    while(comeco <= meio && meio <= fim){
        //printf("\n------>[%d]<------\n", aux);
        if(vetor[comeco] < vetor[meio]){
            //printf("%d, ", vetor[comeco]);
            vetAux[aux] = vetor[comeco];
            comeco++;
        } else {
            //printf("%d, ", vetor[meio]);
            vetAux[aux] = vetor[meio];
            meio++;
        }
        aux++;
    }

    //printf("\n------>[%d]<------\n", aux);
    while(comeco <= meio){
        //printf("%d, ", vetor[comeco]);
        vetAux[aux] = vetor[comeco];
        aux++;
        comeco++;
    }

    //printf("\n------>[%d]<------\n", aux);
    while(meio <= fim){
        //printf("%d, ", vetor[meio]);
        vetAux[aux] = vetor[meio];
        aux++;
        meio++;
    }

    for (aux = 0; aux < fim; aux++){
        vetor[aux] = vetAux[aux];
    }
    //printf("\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");
}

void quick(int vetor[], int comeco, int fim)
{
	int i, j, pivo, aux;
	i = comeco;
	j = fim-1;
	pivo = vetor[(comeco + fim) / 2];
	while(i <= j)
	{
	    //printf("\n------>[%d]<------\n", pivo);
		while(vetor[i] < pivo && i < fim)
		{
		    //printf("%d, ", i);
			i++;
		}
		while(vetor[j] > pivo && j > comeco)
		{
		    //printf("%d, ", j);
			j--;
		}
		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > comeco)
		quick(vetor, comeco, j+1);
	if(i < fim)
		quick(vetor, i, fim);

    //printf("\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");
}

void radix(int vetor[]) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(QUANTIDADE_ELEMENTOS, sizeof(int));

    for (i = 0; i < QUANTIDADE_ELEMENTOS; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < QUANTIDADE_ELEMENTOS; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = QUANTIDADE_ELEMENTOS - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < QUANTIDADE_ELEMENTOS; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

void shell(int vetor[]){
    int i , j , aux;
    int gap = 1;

    while(gap < QUANTIDADE_ELEMENTOS) {
        gap = 3*gap+1;
    }

    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < QUANTIDADE_ELEMENTOS; i++) {
            aux = vetor[i];
            j = i;
            while (j >= gap && aux < vetor[j - gap]) {
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor [j] = aux;
        }
    }
}

void heap(int vetor[]){
   int i = QUANTIDADE_ELEMENTOS / 2, pai, filho, aux, n = QUANTIDADE_ELEMENTOS;

   while(1) {
      if (i > 0) {
          i--;
          aux = vetor[i];
      } else {
          n--;
          if (n == 0) return;
          aux = vetor[n];
          vetor[n] = vetor[0];
      }

      pai = i;
      filho = i * 2 + 1;

      while (filho < n) {
          if ((filho + 1 < n)  &&  (vetor[filho + 1] > vetor[filho]))
              filho++;
          if (vetor[filho] > aux) {
             vetor[pai] = vetor[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }

      vetor[pai] = aux;
   }
}




void gerarPiorCaso(int *vetor){
    int i;
    //printf("Gerando vetor...\n");
    int quantidade_elementos = QUANTIDADE_ELEMENTOS;

    for (i = 0; i < QUANTIDADE_ELEMENTOS; i++) {
        vetor[i] = quantidade_elementos--;
    }
    //printf("Vetor gerado com sucesso!\n\n");
}

// -------------- Funções responsaveis para geração de relatório --------------------

typedef struct infoAlgoritimo{
    char nomeAlgoritimo [25];
    char inicioOrdenacao[80];
    char fimOrdenacao[80];
}_infoAlgoritimo;


void timeStamp(char * buffer){
    double clk = clock();
    char ms[20];

    clk = clk/CLOCKS_PER_SEC;

    snprintf(ms, 20, "%.3f", clk);

    strcpy(buffer, ms);
}

void relatorioOrdenacao(_infoAlgoritimo algoritimoOrdenacao[], int tamVetor){
    int i;


    printf("RELATORIO - TEMPO DE ORDENACAO\n\nQUANTIDADE DE ELEMENTOS: %d\n\nALGORITMO\tINICIO      |  FINAL\n", QUANTIDADE_ELEMENTOS);

    for(i=0;i<6;i++){
        printf("\n%s\t\t%s\t|  %s",algoritimoOrdenacao[i].nomeAlgoritimo,
                                                algoritimoOrdenacao[i].inicioOrdenacao,
                                                algoritimoOrdenacao[i].fimOrdenacao);
    }
 printf("\n\n\n");
}

int main(){

  int vetorPiorCaso[QUANTIDADE_ELEMENTOS];
  _infoAlgoritimo algoritimoOrdenacao[6];
  gerarPiorCaso(vetorPiorCaso);

   //--------Bubble
  strcpy(algoritimoOrdenacao[Bubble].nomeAlgoritimo,"Bubble");
  timeStamp(algoritimoOrdenacao[Bubble].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  bubble(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Bubble].fimOrdenacao);

  //--------Merge
  strcpy(algoritimoOrdenacao[Merge].nomeAlgoritimo,"Merge");
  timeStamp(algoritimoOrdenacao[Merge].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  merge(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Merge].fimOrdenacao);

   //--------Quick
  strcpy(algoritimoOrdenacao[Quick].nomeAlgoritimo,"Quick");
  timeStamp(algoritimoOrdenacao[Quick].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  quick(vetorPiorCaso, 0, QUANTIDADE_ELEMENTOS);
  timeStamp(algoritimoOrdenacao[Quick].fimOrdenacao);

   //--------Radix
  strcpy(algoritimoOrdenacao[Radix].nomeAlgoritimo,"Radix");
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

  //--------Heap
  strcpy(algoritimoOrdenacao[Heap].nomeAlgoritimo,"*Heap");
  timeStamp(algoritimoOrdenacao[Heap].inicioOrdenacao);
  gerarPiorCaso(vetorPiorCaso);
  heap(vetorPiorCaso);
  timeStamp(algoritimoOrdenacao[Heap].fimOrdenacao);

  relatorioOrdenacao(algoritimoOrdenacao, (sizeof(algoritimoOrdenacao)/sizeof(algoritimoOrdenacao[0])));

  //system("\n\nPAUSE");
  return 0;
}
