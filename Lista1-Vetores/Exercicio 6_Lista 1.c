#include <stdio.h>
#include<stdlib.h>
#include "VetLib.h"

void main(){
	int num, adv;
	printf("Insira a quantidade de numeros para sorteio: ");
	
	scanf("%d", &num);
	int vet[num];
	geravet(vet, num);
	
	printf("\n\nAgora, advinhe um numero: ");
	scanf("%d", &adv);
	if(advinha(vet, num, adv) == 1){
		printf("O numero %d foi sorteado! Parabens!\n\n", adv);
		printvet(vet, num);
	}else{
		printf("O numero %d nao foi sorteado!\n\n", adv);
		printvet(vet, num);
	}
}
