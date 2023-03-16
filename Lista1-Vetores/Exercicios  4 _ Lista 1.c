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
	printf("Quantidade de numeros impares: %d\n",qtdimpar(vet,n));
	
}
