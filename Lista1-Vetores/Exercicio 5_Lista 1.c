#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	char dna[30], comp[30];
	int tamanho, i;
	printf("Entre com a fita do DNA:");
	gets(dna);
	tamanho = strlen(dna);
	for(i=0;i<tamanho;i++){
		switch(dna[i]){
			case 'A': comp[i] = 'T';
			break;
			case 'T': comp[i] = 'A';
			break;
			case 'C': comp[i] = 'G';
			break;
			case 'G': comp[i] = 'C';
			break;
			default: comp[i] = ' ';
		}//fim switch
	}//fim for 
	comp[tamanho]= '\0';
	printf("*** Fita principal ***");
	puts(dna);
	printf("*** Fita complementar ***");
	puts(comp);
	return 0;
}
