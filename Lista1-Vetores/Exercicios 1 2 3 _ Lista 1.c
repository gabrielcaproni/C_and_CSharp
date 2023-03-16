#include<stdio.h>
#include<stdlib.h>
#include "vetlib.h"

int main(){
	int vet[100], n;
	printf("Qtde de elementos do vetor:");
	scanf("%d", &n);
	//geravet(vet,n);
	printf("Entre com os dados para o vetor:");
	leiavetor(vet,n);
	printf("Vetor\n");
	printvet(vet,n);
	printf("Soma do vetor: %d\n",somavet(vet,n));
	printf("Maior elemento: %d\n",maiorvet(vet,n));
	printf("Menor elemento: %d\n",menorvet(vet,n));
	return 0;
}
