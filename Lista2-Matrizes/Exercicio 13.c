#include <stdlib.h>
#include "matrixlib.h"

void main(){
	
	int m1[2][100], m2[3][100], mult[100][100];
	
	printf("Insira os valores da primeira matriz: \n");
	leiaMatrix(m1, 2, 3);
	printMatrix(m1, 2, 3);
	printf("\n");
	
	printf("Insira os valores da segunda matriz: \n");
	leiaMatrix(m2, 3, 2);
	printMatrix(m2, 3, 2);
	printf("\n");
	
	printf("\nMatriz multiplicada: \n");

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			for(int aux = 0; aux < 3; aux++){
				mult[i][j] += m1[i][aux] * m2[aux][j];
			}
		}
	}
	
	printMatrix(mult, 2, 2);

}
