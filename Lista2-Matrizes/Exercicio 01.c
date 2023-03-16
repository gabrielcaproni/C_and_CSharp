#include<stdio.h>
#include"matrixlib.h"

int main(){
	int m[100][100], n, lin, cols, i, j, cont=0;
	printf("Entre com  a quantidade de linhas e colunas:");
	scanf("%d%d",&lin, &cols);
	geraMatrix(m,lin,cols);
	printMatrix(m,lin,cols);
	
	printf("Insira um numero:");
	scanf("%d",&n);
	
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
			if(m[i][j] > n){
				cont++;
			}
		}
	}
	printf("Existem %d numeros maiores que %d na matriz.\n\n",cont,n);
}
