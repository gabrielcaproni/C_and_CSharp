#include<stdio.h>
#include"matrixlib.h"

int main(){
	int m1[100][100],m2[100][100], matsum[100][100],ordem1,ordem2
	;
	
	printf("Insira a ordem da primeira e da segunda matriz:");
	scanf("%d%d", &ordem1, &ordem2);
	
	geraMatrix(m1, ordem1, ordem1);
	printMatrix(m1,ordem1,ordem1);
	printf("\n\n");
	geraMatrix(m2,ordem2,ordem2);
	printMatrix(m2,ordem2,ordem2);
	printf("\n\n");
	
	printf("Somando matrizes...\n\n");
	if(ordem1 != ordem2){
	printf("As matrizes nao sao de mesma ordem; nao e possivel fazer a soma.");
	}else{
		printf("Soma das matrizes.\n\n");
		somaMatrix(m1,m2,matsum,ordem1,ordem2);
		printMatrix(matsum,ordem1,ordem1);
	}
	
}
