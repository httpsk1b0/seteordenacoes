#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numerosAleatorios.cpp"

int* lerDados(int);
void gerarNumerosAleatorios(int);
void mostrarValores(int*,int);

void bubbleSort(int*, int);
void swap(int *a, int *b);

float tempo(clock_t tempo);

/*
    O algoritmo apresentado no main está ordenando elementos com a quantidade expressa no vetor v(vSize), com valores incrementados em vIncrement.
*/
int main()
{
    int vSize = 1000;
    int vIncrement = 10; 
    int tentativa = 5; 
    clock_t dB[tentativa], dQ[tentativa], dM[tentativa];
    int *v = (int*)malloc(vSize*sizeof(int));
    for(int i=0; i<vSize; i++){
        v[i] = vIncrement*(i+1);
    }
    for(int j=0; j<vSize; j++){
        gerarNumerosAleatorios(v[j]);
        int *x = (int*)malloc(v[j]*sizeof(int));
        for(int i=0; i<tentativa; i++){
            //BubbleSort
            
            x = lerDados(v[j]);
            dB[i] = clock();
            bubbleSort(x, v[j]);
            dB[i] = clock() - dB[i];
    
        }
        clock_t sB=dB[0]/tentativa;
        clock_t sQ=dQ[0]/tentativa;
        clock_t sM=dM[0]/tentativa;
        for (int i = 1; i < tentativa; i++){
            sB += dB[i]/tentativa;
            sQ += dQ[i]/tentativa;
            sM += dM[i]/tentativa;
        }
        FILE *f = fopen("tempoos.txt", "w");
        fprintf(f, "%d\t%f\t%f\t%f\n", v[j], tempo(sB), tempo(sQ), tempo(sM));
        fclose(f);
    }
}

int* lerDados(int t){
    FILE *f = fopen("numerosAleatorios.txt", "r");
    int* res = (int*)malloc(t*sizeof(int));
    int aux = 0;
    while(!feof(f)){
        fscanf(f, "%d", &res[aux++]);
    }
    return res;
}

void gerarNumerosAleatorios(int t){
    int dispersao = 100;
    srand(100);
    int* res = numerosAleatorios(t, dispersao);
    escreverEmArquivo(res, t);
}

void mostrarValores(int *x, int t){
    for (int i = 0; i < t; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }   
}

void bubbleSort(int *x, int n){ 
    if (n < 1)return; 
    for (int i=0; i<n; i++){
        if (x[i] > x[i+1]){
            swap(&x[i], &x[i+1]);  
        }
    }
    bubbleSort(x, n-1); 
}


void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

float tempo(clock_t tempo){
    return ((float) tempo)/CLOCKS_PER_SEC;
}