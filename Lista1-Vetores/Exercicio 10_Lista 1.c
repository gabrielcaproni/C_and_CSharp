#include<stdio.h>
#include "VetLib.h"
int main(){
	int dado[6]={0} , i , n, face;
	printf("Entre com a quantidade de vezes que o dado foi lancado:");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &face);
		dado[face-1]++;
	}
	
	for(i=0;i<6;i++){
		printf("face %d caiu %d vezes. \n",i+1, dado[i]);
	}
}
