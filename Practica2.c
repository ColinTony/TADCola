/*
PRACTICA 02
AUTORES: Colin Heredia Luis Antonio 
VERSIÓN: 1.0

DESCRIPCIÓN: Con la implementación del TAD cola en C, (dinámica)
implementamos un programa que realice las 3 sumulaciones de la practica (Supermercado , procesos SO, Banco)

OBSERVACIONES: Utilizamos una Estructura de datos cola de forma dinamica , la cual
nos ayudara para la realizacion de las diferentes simulaciones.

COMPILACIÓN : usamos el comando gcc Practica01.c TADPila.c Evaluador.c -o Practica01.c ó ejecutar el .bat
*/

#include <stdio.h>
// mis librerias .h
#include "Presentacion.h"
#include "TADColaDin.h"
#include "SuperMercado.h"
#include "Dibujar.h"


// Esta funcion solo nos dira si el usuario quiere continuar en el menu o ya no
boolean isContinue()
{
	boolean isContinue = FALSE; // saber si quiere continuar en el menu 
	int opc;
	puts("\n \n \n Teclea la opcion que desees");
	printf("Deseas regresar al menu de simulaciones ? \n 1-.SI \n 2-.NO \n");
	scanf("%i",&opc);
	// si quisi continuar se cambia a verdaero
	if(opc == 1)
		isContinue=TRUE; // si es 1 entonces quiere continuar , si no se mantiene en FASLE

	return isContinue; // regresamos
}

int main()
{
	int opc; 
	// menu para las simulaciones
	boolean continuar = TRUE; // sera verdadero hasta que el usuario ya no quiera

	// variables para la simulacion del superMercado
	superMerc super;
	
	while(continuar)
	{
		// Vemos que simulacion ejecutar
		puts("\n Tecla la simulacion que deseas realizar"); // puts agrega un salto de linea.
		printf("%s\n", " 1-.SUPERMERCADO \n 2-.PROCESOS S.O \n 3-.BANCO");
		scanf("%i",&opc);
		// ejecutamos la opcion seleccionada
		switch(opc)
		{
			case 1:
				// ejetutamos la simulacion del supermercado
				// creamos nuestro superMercado con los datos que quiera el usuario
				abrirSuper(&super);
				// dibujamos el supermercado
				dibujar(&super);
				// empezamos a antender
				empezar(&super);
			break;
			
			case 2:
				// Ejetucamos la simulacion de Procesos S.O
				printf("%s\n", "Procesos S.O");
			break;

			case 3:
				// Ejecutamos banco
				printf("%s\n", "Banco");
			break;
			
			default:
				// no es ninguna opcion
				printf("%s\n", "No has elegido ninguna opcion correcta");
			break;
		}

		continuar = isContinue();
	} // mientras el usiario quiera se regresara al menu
	
	return 0;
}