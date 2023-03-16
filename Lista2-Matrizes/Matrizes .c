#include<stdio.h>
int main(){
	int mat[100][100],lin,cols,i,j;
	printf("Quantidade de linhas e colunas: ");
	scanf("%d%d",&lin,&cols);
	//lendo dados pra a matriz
	for(i=0;i<lin;i++){
		printf("Linha %d\n",i);
		for(j=0;j<cols;j++){
			printf("Posicao[%d,%d]:",i,j);
			scanf("%d", &mat[i][j]);
		}//fim for j
	}//fim for i
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
		
			printf(" %d |", mat[i][j]);
		}//fim for j
		printf("\n");
	}//fim for i
	return 0;
}
