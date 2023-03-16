#include<stdio.h>
#include"matrixLib.h"
int main(){
	int m[100][100], lin, cols, x, cont=0, i, j;
	printf("Entre com a quantidade de linhas e colunas:");
	scanf("%d%d",&lin,&cols);
	geraMatrix(m,lin,cols);
	printMatrix(m,lin,cols);
	printf("Insira um numero:");
	scanf("%d", &x);
	
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
			if(m[i][j] > x){
				cont++;
			}
		}
	}
	printf("Existem %d numeros maiores que %d na matriz.\n\n",cont,x);
	
}

