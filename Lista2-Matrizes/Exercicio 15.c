#include <stdlib.h>
#include "matrixlib.h"

void main(){

	int mat[100][100], redes, x1, x2, y1, y2, cont = 0;
	
	
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			mat[i][j] = 0;
		}
	}
	
	printf("Insira a quantidade de redes que foram lancadas: ");
	scanf("%d", &redes);
	
	while(redes != 0){
		printf("Insira a coordenada X inicial e final da rede: ");
		scanf("%d%d", &x1, &x2);
		printf("Insira a coordenada Y inicial e final da rede: ");
		scanf("%d%d", &y1, &y2);
		
		for(int i = x1; i <= x2; i++){
			for(int j = y1; j <= y2; j++){
				mat[i][j] = 1;
			}
		}
		
		redes = redes - 1;
	}
	
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(mat[i][j] == 1){
				cont++;
			}
		}
	}
	
	printf("A area total aproveitada eh: %d", cont);
}

