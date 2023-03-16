#include<stdio.h>
#include<string.h>
#include "VetLib.h"
int main(){
	char carac[100];
	int tamanho, i;
	printf(" Insira a string: ");
	gets(carac);
	tamanho = strlen(carac);
	printf(" String inserida, ao contrario: ");
	for(i=0;i<tamanho;i++){
		
		printf("%c", carac[tamanho-1-i]);
	}
	return 0;
}


