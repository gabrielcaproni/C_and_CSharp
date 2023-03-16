#include<stdio.h>
#include"matrixLib.h"
int main(){
	int m[100][100], lin, cols, i, j;
	printf("Entre com a quantidade de linhas e colunas:");
	scanf("%d%d",&lin,&cols);
	geraMatrix(m,lin,cols);
	printMatrix(m,lin,cols);
	j = cols-1;
	for(i=0;i<lin;i++){
		printf("%d |\n", m[i][j]);
		j--;
		}
	
}
