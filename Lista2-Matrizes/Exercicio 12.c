#include <stdlib.h>
#include "matrixlib.h"

void main(){

	float mat1[100][100], mat2[100][100], matr[100][100], cons; 
	int op = 1, ordem;
	
	printf("Insira a ordem das matrizes: ");
	scanf("%d", &ordem);
	geraMatrixFloat(mat1, ordem, ordem);
	_sleep(500);
	geraMatrixFloat(mat2, ordem, ordem);
	
	while(op != 0){
		printf("\n\nEscolha uma opcao a seguir: \n");
		printf("1- Somar Matrizes\n2- Subtrair Matrizes\n3- Adicionar Constante\n4- Mostrar Matrizes\n0- Sair");
		printf("\n\nOpcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				somaMatrixFloat(mat1, mat2, matr, ordem);
				printf("\nMatrizes somadas: \n");
				printMatrixFloat(matr, ordem, ordem);
				break;
			case 2:
				subtraiMatrixFloat(mat1, mat2, matr, ordem);				
				printf("\nSubtraindo a primeira matriz da segunda: \n");
				printMatrixFloat(matr, ordem, ordem);
				break;
			case 3:
				printf("Insira uma constante para adicionar as matrizes: ");
				scanf("%f", &cons);
				for(int i = 0; i < ordem; i++){
					for(int j = 0; j < ordem; j++){
						mat1[i][j] += cons;
						mat2[i][j] += cons;
					}
				}
				break;
			case 4:
				printMatrixFloat(mat1, ordem, ordem);
				printf("\n\n");
				printMatrixFloat(mat2, ordem, ordem);
				break;
			case 0:
				break;
			default:
				printf("Opcao invalida!");
				
		}
	}
}
	
	
	
