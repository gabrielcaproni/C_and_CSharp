#include<stdio.h>
#include"matrixLib.h"

int main(){
	int m[100][100],lin, cols, i, j, n, cont=0;
	printf("Entre com a quantidade de linhas e colunas:");
	scanf("%d%d",&lin,&cols);
	geraMatrix(m,lin,cols);
	printMatrix(m,lin,cols);
	printf("Entre com o numero para busca:");
	scanf("%d",&n);
	for(i = 0; i < lin; i++){
		for(j = 0; j < cols; j++){
			if(m[i][j]==n){
				cont++;
			}
		
		}
	}
	printf("O numero %d aparece %d vez(es) na matriz.\n\n",n,cont);

}
