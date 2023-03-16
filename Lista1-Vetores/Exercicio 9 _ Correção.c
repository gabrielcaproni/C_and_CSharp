#include<stdio.h>
#include"VetLib.h"
int main(){
	int num, face = 0; 
	printf("Insira a quantidade de vezes que o dado foi lancado:");
	scanf("%d", &num);
	int lanc[num];
	
	geravet(lanc, num, 6);
	printvet(lanc, num);
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < num; j++){
			if(lanc[j] == i){
				face++;
			}
		}
		printf("\n O elemento [%d] aparece %d vezes.\n", i, face);
		face = 0;
	}

}
