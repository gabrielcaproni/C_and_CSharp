#include<stdio.h>
#include"matrixlib.h"
void matIdentidade(int m[100][100],int ordem){
	int i,j;
	for(i = 0; i < ordem; i++){
		for( j = 0; j < ordem; j++){
			if(i == j){
				m[i][j] = 1;
				}else{
					m[i][j] = 0;
				}				
		}
	}
}

int main(){
	int m[100][100],ordem;
	printf("Entre com a ordem da matriz:");
	scanf("%d",&ordem);
	
	matIdentidade(m,ordem);
	printf("Identidade da matriz de ordem %d: \n", ordem);
	printMatrix(m,ordem,ordem);
	return 0;
}
