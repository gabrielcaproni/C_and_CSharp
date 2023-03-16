#include<stdio.h>
#include"matrixLib.h"
int main(){
	
	int mat[100][100], ordem, res;
	int i,j;
	printf("Ordem da matriz:");
	scanf("%d", &ordem);
	geraMatrix(mat,ordem,ordem);
	printf("*** Matriz ***\n");
	printMatrix(mat,ordem,ordem);
	printf("Diagonal Principal\n");
	for(i = 0; i < ordem; i++){
		printf("%d|",mat[i][i]);
	}//fim for
	return 0;
}
