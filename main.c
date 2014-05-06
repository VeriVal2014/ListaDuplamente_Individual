#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

int main(){
	int option=0, number=0, endLoop=0, error=0, errorEntrada=0;
	char* teste;
	
	while(endLoop==0){
		fflush(stdin);
		scanf("%d", &option);
		
		switch(option){
			fflush(stdin);
			case 0:
				endLoop++;
				error=end();
				break;
			case 1: 
				errorEntrada=scanf("%d", &number);
				
				if(errorEntrada==1){
					error=insertFront(number); 
				}
				else{
					fprintf(stderr,"Entrada inválida\n");
					return -1;
				}
				break; 
		
			case 2:	
				errorEntrada=scanf("%d", &number);
				if(errorEntrada==1){
					error=insertEnd(number);
				}
				else{
					fprintf(stderr,"Entrada inválida\n");
					return -1;
				}
				break;
		
			case 3: 
				errorEntrada=scanf("%d", &number);
				if(errorEntrada==1){
					error=deleteNum(number);
				}
				else{
					fprintf(stderr,"Entrada inválida\n");
					return -1;
				}
				break;
	
			case 4:	
				error = show(); 
				break;
			
			case 5:
				error = reverseShow(); 
				break;
			default:
				error=1;
				break;
		}
		
		switch(error){
		case -1:
			fprintf(stderr,"Lista Vazia\n");
			break;
		case -2:
			fprintf(stderr,"Sem Memoria\n");
			break;
		case 0: 
			break;
		case 1:
			fprintf(stderr,"Entrada invalida\n");
		default:
			fprintf(stderr,"Erro\n");
			break;
		}				
		
	}

	
	return 0;

}
