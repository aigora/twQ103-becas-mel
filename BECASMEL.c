// Autoras: Laura Úbeda, Marina Rodríguez y Ester Ruiz
// BECAS MEL

#include<stdio.h>
#include<string.h>
#include<math.h>

//usuario y contraseña para acceder a la administración
#define USUARIO "admin"
#define CONTRASENA "56234"


// declaración estructuras
typedef struct
{
	char nombre[30];
	char apellidos[50];
	int dni;
	char letradni[1];
	int edad;
	int miembros;
	double renta;
	double distancia;
	double notamedia;
	}
	datossolicitar;
	
struct umbral
{
	int numero;
	double intervalo1;
	double intervalo2;
	double intervalo3;
};

//prototipo funciones
float bachilleratoUmbral1(float distancia, float notamedia);
float bachilleratoUmbral2(float distancia, float notamedia);
float bachilleratoUmbral3(float notamedia);
float uniUmbral1(float distancia, float notamedia);
float uniUmbral2(float distancia, float notamedia);
float uniUmbral3(float notamedia);


int main(){
	
	// variables
	int opcion, estudio;
	datossolicitar bachillerato;
	datossolicitar universidad;
	FILE * fsolicitudes;

	int numero, i, umbral;
	float beca;
	float distancia, notamedia;
	
	char usuario[50], contrasena[50];
	int comparacionUsuario, comparacionContrasena;
	
	
	do{
		printf("Bienvenido a BECAS MEL\n");
		printf("Por favor, selecciona que desea hacer\n");
		printf("Pulse 1 si quiere solicitar una beca\nPulse 2 para calcular una beca aproximada\nPulse 3 si desea una atencion mas personalizada\nPulse 4 si pertenece a la administracion\nPulse 5 para salir del programa\n");
		scanf("%i",&opcion);
		system("cls"); 
		
		switch(opcion){
			
			case 1: printf("Usted ha seleccionado solicitar una beca\n");
			
			// comprobación apertura del fichero correcta
			fsolicitudes = fopen("solicitudes.txt", "a");		
			if (fsolicitudes == NULL){
				printf("Error en apertura\n");
				return -1;
				}
				
			do{
				printf("Por favor, seleccione en que tipo de beca estaria interesado\n");
				printf(" Pulse 1 si esta cursando bachillerato\n Pulse 2 si se trata de estudios universitarios\n");
				scanf("%i", &estudio);
				system("cls");
				
				if (estudio == 1){
					printf("Usted ha seleccionado Bachillerato\n");
					fflush(stdin);
					printf("\nNombre: ");
					gets(bachillerato.nombre);
					printf("Apellidos: ");
					gets(bachillerato.apellidos);
					printf("DNI: ");
					scanf("%d", &bachillerato.dni);
					gets(bachillerato.letradni);
					printf("Edad: ");
					scanf("%d", &bachillerato.edad);
					printf("Numero de miembros en la unidad familiar: ");
					scanf("%d",&bachillerato.miembros);
					printf("Renta familiar: ");
					scanf("%d", &bachillerato.renta);
					printf("Distancia vivienda-centro escolar (km): ");
					scanf("%d", &bachillerato.distancia);
					printf("Nota media curso anterior: ");
					scanf("%d", &bachillerato.notamedia);
					printf("Su beca ha sido solicitada correctamente, recibira una respuesta en los proximos dias. Gracias.\n");
					
					fwrite(&bachillerato, sizeof(datossolicitar), 1, fsolicitudes);
				}
			
				else if (estudio == 2){
					printf("Usted ha seleccionado estudios universitarios\n");
					fflush(stdin);
					printf("\nNombre: ");
					gets(universidad.nombre);
					printf("Apellidos: ");
					gets(universidad.apellidos);
					printf("DNI: ");
					scanf("%d", &universidad.dni);
					gets(universidad.letradni);
					printf("Edad: ");
					scanf("%d", &universidad.edad);
					printf("Numero de miembros en la unidad familiar: ");
					scanf("%d",&universidad.miembros);
					printf("Renta familiar: ");
					scanf("%d", &universidad.renta);
					printf("Distancia vivienda-centro escolar (km): ");
					scanf("%d", &universidad.distancia);
					printf("Nota media curso anterior: ");
					scanf("%d", &universidad.notamedia);
					printf("Su beca ha sido solicitada correctamente, recibira una respuesta en los proximos dias. Gracias.\n");
							
					fwrite(&universidad, sizeof(datossolicitar), 1, fsolicitudes);
					}
								
				else{
					printf("ERROR\n");
				}
			}
		
		while (estudio!=1&&estudio!=2);
		
			break;
			
			case 2: printf("Usted ha seleccionado calcular una beca aproximada\n");
			
				//definición vector estructura
			struct umbral intervalos[3]={ {1, 3771.00, 13236.00, 14122.00},
								{2, 7278.00, 22594.00, 24089.00},
								{3, 10606.00, 30668.00, 32667.00}	};
							
				do{
				printf("Por favor, seleccione en que tipo de beca estaria interesado\n");
				printf(" Pulse 1 si esta cursando bachillerato\n Pulse 2 si se trata de estudios universitarios\n");
				scanf("%i", &estudio);
				system("cls");
				
				if (estudio == 1){
					printf("Usted ha seleccionado Bachillerato\n");
					printf("Introduce el numero de miembros en tu unidad familiar (si son mas de 3 pulsa 3):\n");
					scanf("%d", &numero);
					
					do{
					printf("Por favor, introduce el umbral al que perteneces segun tu renta anual, basandote en los siguientes intervalos:\n");
					
					for(i=0;i<3;i++){
						if(numero==intervalos[i].numero) {
							printf("Umbral 1: %.2lf - %.2lf\n", intervalos[i].intervalo1, intervalos[i].intervalo2);
							printf("Umbral 2: %.2lf - %.2lf\n", intervalos[i].intervalo2, intervalos[i].intervalo3);
							printf("Umbral 3: desde %.2lf\n", intervalos[i].intervalo3);
							}
						}
					scanf("%d", &umbral);
					
					switch(umbral){
						case 1:
							printf("Distancia vivienda-centro escolar(km):\n");
							scanf("%f", &distancia);
							printf("Nota media:\n");
							scanf("%f", &notamedia);	
							
							//invocamos a la función
							beca = bachilleratoUmbral1(distancia, notamedia);
						
							printf("Tu beca tendra un valor aproximado de %.2f euros.\n", beca);
						break;
						
						case 2:
							printf("Distancia vivienda-centro escolar(km):\n");
							scanf("%f", &distancia);
							printf("Nota media:\n");
							scanf("%f", &notamedia);	
							
							beca = bachilleratoUmbral2(distancia, notamedia);
						
							printf("Tu beca tendra un valor aproximado de %.2f euros.\n", beca);
							
							break;
						case 3:
						printf("Distancia vivienda-centro escolar(km):\n");
						scanf("%f", &distancia);
						printf("Nota media:\n");
						scanf("%f", &notamedia);	
						
						beca = bachilleratoUmbral3(notamedia);
					
						printf("Tu beca tendra un valor aproximado de %.2f euros.\n", beca);	
							
							break;
						default:
							
						printf("ERROR\n");
					}
					
					}
					while(umbral!=1&&umbral!=2&&umbral!=3);
				}
			
				else if (estudio == 2){
					printf("Usted ha seleccionado estudios universitarios\n");
					printf("Introduce el numero de miembros en tu unidad familiar (si son mas de 3 pulsa 3):\n");
					scanf("%d", &numero);
					
					do{
					printf("Por favor, introduce el umbral al que perteneces segun tu renta anual, basandote en los siguientes intervalos:\n");
					
					for(i=0;i<3;i++)
					{
						if(numero==intervalos[i].numero) {
							printf("Umbral 1: %.2lf - %.2lf\n", intervalos[i].intervalo1, intervalos[i].intervalo2);
							printf("Umbral 2: %.2lf - %.2lf\n", intervalos[i].intervalo2, intervalos[i].intervalo3);
							printf("Umbral 3: desde %.2lf\n", intervalos[i].intervalo3);
							}
						}
						
					scanf("%d", &umbral);
					
					switch(umbral){
						case 1:
						printf("Distancia vivienda-centro escolar(km):\n");
						scanf("%f", &distancia);
						printf("Nota media:\n");
						scanf("%f", &notamedia);	
						
						beca = uniUmbral1(distancia, notamedia);
					
						printf("Tu beca tendra un valor aproximado de %.2f euros mas el valor de tu matricula.\n", beca);
						break;
						
						case 2:
						printf("Distancia vivienda-centro escolar(km):\n");
						scanf("%f", &distancia);
						printf("Nota media:\n");
						scanf("%f", &notamedia);	
						
						beca = uniUmbral2(distancia, notamedia);
					
						printf("Tu beca tendra un valor aproximado de %.2f euros mas el valor de tu matricula.\n", beca);
							
							break;
						case 3:
						printf("Distancia vivienda-centro escolar(km):\n");
						scanf("%f", &distancia);
						printf("Nota media:\n");
						scanf("%f", &notamedia);	
						
						beca = uniUmbral3(notamedia);
					
						printf("Tu beca tendra un valor aproximado de %.2f euros mas el valor de tu matricula.\n", beca);	
							
							break;
						default:
							
						printf("ERROR\n");
					}
					
					}
					while(umbral!=1&&umbral!=2&&umbral!=3);
				}
				
				else{
					printf("ERROR\n");
				}
			}
		
			while (estudio!=1&&estudio!=2);
		
				break;
			
			case 3: printf("Adjuntamos nuestros datos de contacto:\n");
				printf(" E-mail: becasmel@gmail.com\n Telefono: 916292046 / 672964205\n Localizacion: C/ Ronda de Valencia, 3 28012, Madrid\n");
			break;
			
			case 4: do{
				
				printf("Introduzca su usuario\n");
				scanf("%s", &usuario);
				printf("Introduzca su contrasena\n");
				scanf("%s", &contrasena);
				system("cls");
				
				//comprobación inicio de sesión correcto
				comparacionUsuario = strcmp(USUARIO,usuario);
				comparacionContrasena = strcmp(CONTRASENA, contrasena);
				
				if(comparacionContrasena != 0 || comparacionUsuario != 0){
					printf("Usuario o contrasena incorrecta, vuelve a intentarlo\n");
					}
			} while(comparacionContrasena != 0 || comparacionUsuario != 0);
			
			//comprobación apertura del fichero
			fsolicitudes = fopen("solicitudes.txt", "r");
			if(fsolicitudes == NULL){
				printf("Error abriendo fichero\n");
				return -1;
			}
			
			printf("BECAS SOLICITADAS:\n");
				
			//solicitudes bach	
			while(fread(&bachillerato, sizeof(datossolicitar), 1, fsolicitudes) == 1)
			{
				printf("\nNombre: %s\n", bachillerato.nombre);
				printf("Apellidos: %s\n", bachillerato.apellidos);
				printf("DNI: %d", bachillerato.dni);
				printf("%s\n", bachillerato.letradni);
				printf("Edad: %d\n", bachillerato.edad);
				printf("Numero de miembros en la unidad familiar: %d\n", bachillerato.miembros);
				printf("Renta familiar: %d\n", bachillerato.renta);
				printf("Distancia vivienda-centro escolar: %d km\n", bachillerato.distancia);
				printf("Nota media curso anterior: %d\n\n", bachillerato.notamedia);	
			}
			
			//solicitudes universidad	
			while(fread(&universidad, sizeof(datossolicitar), 1, fsolicitudes) == 1)
			{
				printf("\nNombre: %s\n", universidad.nombre);
				printf("Apellidos: %s\n", universidad.apellidos);
				printf("DNI: %d", universidad.dni);
				printf("%s\n", universidad.letradni);
				printf("Edad: %d\n", universidad.edad);
				printf("Numero de miembros en la unidad familiar: %d\n", universidad.miembros);
				printf("Renta familiar: %d\n", universidad.renta);
				printf("Distancia vivienda-centro escolar: %d km\n", universidad.distancia);
				printf("Nota media curso anterior: %d\n\n", universidad.notamedia);	
			}
			
			fclose(fsolicitudes);
		
			break;
			
			case 5:
				printf("\nQue tenga un buen dia :)\n");
				return;
				break;
			
			
			default:
				printf("ERROR\n");
		}		
	}
	
	while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4);
}


//implementación de las funciones
float bachilleratoUmbral1(float distancia, float notamedia) {
	float resultado;
	float dis = 0;
	float nota = 0;
	
	if (distancia>100){
		dis = 1500;
	}
	
	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = 1800+dis+nota;
	return resultado;
}

float bachilleratoUmbral2(float distancia, float notamedia){
	float resultado;
	float dis = 0;
	float nota = 0;
	
	if (distancia>100){
		dis = 1500;
	}
	
	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = 200+dis+nota;	
	return resultado;
}

float bachilleratoUmbral3(float notamedia){
	float resultado;
	float nota = 0;

	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = 200+nota;	
	return resultado;
}

float uniUmbral1(float distancia, float notamedia){
	float resultado;
	float dis = 0;
	float nota = 0;
	
	if (distancia>100){
		dis = 1500;
	}
	
	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = 1800+dis+nota;
	return resultado;
}

float uniUmbral2(float distancia, float notamedia){
	float resultado;
	float dis = 0;
	float nota = 0;
	
	if (distancia>100){
		dis = 1500;
	}
	
	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = dis+nota;
	return resultado;
}

float uniUmbral3(float notamedia){
	float resultado;
	float nota = 0;
	
	if(notamedia>=8){
		nota = notamedia*6;
	}
	
	resultado = nota;
	return resultado;
}
