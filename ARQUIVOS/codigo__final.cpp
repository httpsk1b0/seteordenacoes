#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <stdbool.h>

using namespace std;

int* numerosAleatorios(int N, int d) {
    int* x = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        x[i] = rand() % (d * N) + 1;
    }
    return x;
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
    FILE *f = fopen("numerosAleatorios.txt", "r");
    int dispersao = 100;
    srand(100);
    int* res = numerosAleatorios(t, dispersao);
}

void mostrarValores(int *x, int t){
    for (int i = 0; i < t; i++)
    { ofstream myfile;
    int N;
    fopen("tempos.txt","w");
            for (int i = 0; i < N; i++) {
        myfile << x[i] << "\n";
    }
    myfile.close();
        printf("x[%d] = %d\n", i, x[i]);
    }   
}
void SelectionSort(int *x, int n){
    int i, j;    
    for ( i = 0; i < n; i++){
        int menor = i;
        for (j = i + 1; j < n; j++){
            if(x[j] < x[menor]){
                menor = j;
            }
        }
        int temp = x[i];
        x[i] = x[menor];
        x[menor] = temp;
    }
}

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
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

void quicksort(int *x, int ini, int fim){
	int i, j, pivo, aux;
	i = ini;
	j = fim-1;
	pivo = x[(ini + fim) / 2];
	while(i <= j){
		while(x[i] < pivo && i < fim){
			i++;
		}
		while(x[j] > pivo && j > ini){
			j--;
		}
		if(i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i++;
			j--;
		}
	}
	if(j > ini)
		quicksort(x, ini, j+1);
	if(i < fim)
		quicksort(x, i, fim);
}

void merge(int *x, int inf, int sup, int mid, int t){
    int i, j, k, c[t];
    i = inf;
    k = inf;
    j = mid + 1;

    while (i <= mid && j <= sup) {
        if (x[i] < x[j]) {
            c[k] = x[i];
            k++;
            i++;
        }
        else  {
            c[k] = x[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = x[i];
        k++;
        i++;
    }
    while (j <= sup) {
        c[k] = x[j];
        k++;
        j++;
    }
    for (i = inf; i < k; i++)  {
        x[i] = c[i];
    }
}
void mergeSort(int *x, int inf, int sup, int t){
    int meio;
    if (inf < sup){
        meio=(inf+sup)/2;
        mergeSort(x,inf,meio,t);
        mergeSort(x,meio+1,sup,t);
        merge(x, inf, sup, meio, t);
    }
}

float tempo(clock_t tempo){
    return ((float) tempo)/CLOCKS_PER_SEC;
}

void BucketSort(int *x, int n){  
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[x[i]])++;
 
    for (i = 0, j = 0; i < n; i++)  
        for(; count[i] > 0; (count[i])--)
            x[j++] = i;
}

void GnomeSort(int *x, int size){ 
   int i, tmp; 
   for(i=1; i<size; ){
       if(x[i-1] <= x[i])
           ++i;
       else{
           tmp = x[i];
           x[i] = x[i-1];
           x[i-1] = tmp;
           --i;
           if(i == 0)
               i = 1;
       }
   }
}

int ShellSort(int *x, int n){
    int interval, i, j, temp;  
    for ( interval = n/2; interval > 0; interval /= 2)  {  
        for ( i = interval; i < n; i += 1)  {  
          
             temp = x[i];        
            for (j = i; j >= interval && x[j - interval] > temp; j -= interval)  
                x[j] = x[j - interval];  
               
            x[j] = temp;  
        }  
    }  
    return 0;  
}

bool preord(int *x, int n){
  while ( --n >= 1 ) {
    if ( x[n] < x[n-1] ) return false;
  }
  return true;
}
 
void embaralha(int *x, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = x[i];
    r = rand() % n;
    x[i] = x[r];
    x[r] = t;
  }
}
 

void mostrarSequencia(int* x, int N) {
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
}


int main(void){
    int vSize = 1000;
    int vIncrement = 10; 
    int tentativa = 5; 
    FILE *result = fopen("tempos.txt", "a");
    clock_t dB[tentativa], dQ[tentativa], dM[tentativa], dBucket[tentativa], dSele[tentativa], dGnome[tentativa], dShell[tentativa];
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
    
            //QuickSort
            x = lerDados(v[j]);
            dQ[i] = clock();
            quicksort(x, 0, v[j]);
            dQ[i] = clock() - dQ[i];

            //MergeSort
            x = lerDados(v[j]);
            dM[i] = clock();
            mergeSort(x, 0, v[j], v[j]);
            dM[i] = clock() - dM[i];

            //BucketSort
            x = lerDados(v[j]);
            dBucket[i] = clock();
            BucketSort(x, v[j]);
            dBucket[i] = clock() - dBucket[i];

            //SelectionSort
            x = lerDados(v[j]);
            dSele[i] = clock();
            SelectionSort(x, v[j]);
            dSele[i] = clock() - dSele[i];

            //GnomeSort
            x = lerDados(v[j]);
            dGnome[i] = clock();
            GnomeSort(x, v[j]);
            dGnome[i] = clock() - dGnome[i];
            //ShellSort
            x = lerDados(v[j]);
            dShell[i] = clock();
            ShellSort(x, v[j]);
            dShell[i] = clock() - dShell[i];

        }
        clock_t sB=dB[0]/tentativa;
        clock_t sQ=dQ[0]/tentativa;
        clock_t sM=dM[0]/tentativa;
        clock_t sBucket = dBucket[0]/tentativa;
        clock_t sSele = dSele[0]/tentativa;
        clock_t sGnome = dGnome[0]/tentativa;
        clock_t sShell = dShell[0]/tentativa;

        for (int i = 1; i < tentativa; i++){
            sB += dB[i]/tentativa;
            sQ += dQ[i]/tentativa;
            sM += dM[i]/tentativa;
            sBucket += dBucket[i]/tentativa;
            sSele += dSele[i]/tentativa;
            sGnome += dGnome[i]/tentativa;
            sShell += dShell[i]/tentativa;
        }

       result = fopen("tempos.txt", "a");
        fprintf(result, "%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", v[j], tempo(sB),tempo(sQ), tempo(sM),tempo(sBucket), tempo(sSele), tempo(sGnome), tempo(sShell));
        fclose(result);
    }
}
