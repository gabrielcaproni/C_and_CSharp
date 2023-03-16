#include<stdio.h>
#include"VetLib.h"
int main(){
	int n;
	float multiplicacao = 0 ;
	printf("Entre com a quantidade de elementos a serem multiplicados:");
	scanf("%d", &n);
	int vet1[n], vet2[n], vetres[n];
	geravet(vet1, n);
	geravet(vet2, n);
	
}
