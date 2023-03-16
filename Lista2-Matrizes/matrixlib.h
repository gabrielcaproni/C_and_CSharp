#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printMatrix(int m[][100],int lin,int cols){
	int i,j;
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++)
		   printf("%2d ",m[i][j]);
		printf("\n");   
	}// fim for i
}// fim funcao

//--------------------

void geraMatrix(int m[][100],int lin, int cols){
	int i,j;
	srand(time(NULL));
	for(i=0;i<lin;i++)
	  for(j=0;j<cols;j++)
	     m[i][j]=rand()%50;
}

//--------------------


void geraMatrixFloat(float m[][100], int lin, int cols){
	srand(time(NULL));
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < cols; j++){
			m[i][j] = rand()%51;
		}
	}
}

//--------------------

void printMatrixFloat(float m[][100], int lin, int cols){
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < cols; j++){
			printf("%.2f |", m[i][j]);
		}
		printf("\n");
	}
}

//--------------------


void leiaMatrix(int m[][100],int lin, int cols){
	int i,j;
	for(i=0;i<lin;i++)
	  for(j=0;j<cols;j++)
	     scanf("%d",&m[i][j]);
}
//-------------------
void carregaMatrix(int m[][100],int lin, int cols){
	FILE *arq;
	int i,j;
	arq= fopen("numeros.txt","r");
	if(arq==NULL)
	   printf("Arquivo nao encontrado\n");
	for(i=0;i<lin;i++){
	   for(j=0;j<cols;j++){
              fscanf(arq,"%d",&m[i][j]); 
		}// fim for j
	}// fim for i     
}
//--------------------
int menorMatrix(int m[][100], int lin, int cols){
	int i,j, menor = m[0][0];
	for(i=0;i<lin;i++)// linhas
		for(j=0;j<cols;j++) // colunas
			if(m[i][j]<menor)
				menor = m[i][j];
	
	return menor;
}
//--------------------
 
 int somaMatrix(int m1[][100], int m2[][100], int res[][100],int ord1, int ord2){
	int i,j;
	for( i = 0; i < ord1; i++){
		for( j = 0; j < ord1; j++){
			res[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return 0;
}

//--------------------

void somaMatrixFloat(float m1[][100], float m2[][100], float res[][100],int ord){
	for(int i = 0; i < ord; i++){
		for(int j = 0; j < ord; j++){
			res[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

//--------------------

void subtraiMatrixFloat(float m1[][100], float m2[][100], float res[][100],int ord){
	for(int i = 0; i < ord; i++){
		for(int j = 0; j < ord; j++){
			res[i][j] = m1[i][j] - m2[i][j];
		}
	}
}
