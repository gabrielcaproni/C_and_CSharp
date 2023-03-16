#include<stdio.h>
#include"matrixLib.h"

int main(){
	int m1[4][100], m2[3][100], i, j;
	leiaMatrix(m1, 4, 3);
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; i++){
			m2[j][i] = m1[i][j];
		}
	}
	printMatrix(m1,4,3);
	printf("\n");
	printMatrix(m2, 3, 4);
}
