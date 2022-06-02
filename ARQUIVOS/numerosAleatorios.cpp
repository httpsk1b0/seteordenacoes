#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>

using namespace std;

int* numerosAleatorios(int, int);
void mostrarSequencia(int*, int);
void escreverEmArquivo(int* x, int);

int* numerosAleatorios(int N, int d) {
    int* x = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        x[i] = rand() % (d * N) + 1;
    }
    return x;
}

void mostrarSequencia(int* x, int N) {
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
}

void escreverEmArquivo(int* x, int N) {
    ofstream myfile;
    myfile.open("numerosAleatorios.txt");
    for (int i = 0; i < N; i++) {
        myfile << x[i] << "\n";
    }
    myfile.close();
}
