#include<stdio.h>
#include"matrixlib.h"

int multiplicaEscalar(int m[][100], int ordem, int mult){
	int i,j;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			m[i][j] = m[i][j] * mult;
		}
	}
}

int main(){
	int m[100][100], ordem, mult;
	printf("Insira a ordem da matriz:");
	scanf("%d",&ordem);
	geraMatrix(m, ordem, ordem);
	
	printf("Insira o multiplicador escalar da matriz:");
	scanf("%d", &mult);
	
	printMatrix(m,ordem,ordem);
	printf("\n");
	multiplicaEscalar(m,ordem,mult);
	printf("Matriz multiplicada: \n");
	printMatrix(m,ordem,ordem);
}



