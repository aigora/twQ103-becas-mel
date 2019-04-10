// Autoras: Laura Úbeda, Marina Rodríguez y Ester Ruiz
// BECAS MEL

#include<stdio.h>

int main(){
	int opcion;
	
	do{
		printf("Bienvenido a BECAS MEL\n");
		printf("Por favor, selecciona que desea hacer\n");
		printf("Pulse 1 si quiere solicitar una beca\nPulse 2 para calcular una beca aproximada\nPulse 3 si desea una atencion mas personalizada\n");
		scanf("%i",&opcion);
		
		switch(opcion){
			case 1: printf("Usted ha seleccionado solicitar una beca");break;
			case 2: printf("Usted ha seleccionado calcular una beca aproximada");break;
			case 3: printf("Adjuntamos nuestros datos de contacto:");break;
		}
		
	}
	
	while(opcion!=1&&opcion!=2&&opcion!=3);
}
