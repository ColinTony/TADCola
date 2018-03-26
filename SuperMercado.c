/*
	Autor: Colin Heredia Luis Antonio
	Versión 1.0
	Descripción: Cabecera de la libreria para crear un supermercado
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para exit
// mis librerias .h
#include "Presentacion.h"
#include "TADColaDin.h"
#include "SuperMercado.h"
#include "Dibujar.h"


/*
	void abrirSuper(superMerc *super); 
	Descripción: Le pedimos al usuario los valores iniciales nombre, tiempos .. etc
	Recibe:  super
	Devuelve: void.
*/
void abrirSuper(superMerc *super)
{	
	int cajas = 0;
	super->cajeras = 0; // ponemos las cajeras en 0
	// pedimos al usuario que ingrese el nombre del SuperMercado 
	puts("Ingrese el nombre del SuperMercado : ");
	scanf("%s",super->nombreSuper); // gets(super->nombreSuper); No jalo
	strupr(super->nombreSuper); // pasamos todo a Mayusculas
	puts("Ingresa el numero de cajeras que atenderan : ");
	scanf("%d", &cajas);
	super->cajeras = cajas; // iniciamos el numero de cajas
	// verficamos la cajas
	if(!verificaCajas(super))
	{
		// si no cumple
		printf("%s\n", "El numero de cajas no esta dentro del rango");
		exit(0);
	}
	
}
/*
	boolean isOpen(superMerc *super); 
	Descripción: Revisa si aun pueden llegar clientes ya que esta abierto
	Recibe:  super
	Devuelve: boolean.
*/
boolean isOpen(superMerc *super)
{

}
/*
	boolean verificaCajas(superMerc *super); 
	Descripción: combrueba que el numero de cajas ingresado este dentro del rango
	Recibe:  superMerc
	Devuelve: boolean.
*/
boolean verificaCajas(superMerc *super)
{
	int tiempoAte=0; // tiempo de atencion ingresado por el usuario
	int i; // contador
	boolean isCorrect = FALSE;

	if(super->cajeras <= 10)
	{
		isCorrect = TRUE;
		
		// las cajas son crrectas las inicializamos
		// recorremos el arreglo de las cajas
		for(i = 0; i<super->cajeras; i++)
		{
			super->cajas[i].isVacia = TRUE; // la cola al iniciarce esta vacia
			printf("\n Ingresa el tiempo de atencion de la caja %i (MS) \n", i+1);
			scanf("%d",&tiempoAte);
			super->cajas[i].timeAte = tiempoAte;
		}
	}
	return isCorrect;
}
//boolean isCajaEmpty(cola *colacola *cola)		// para saber si la caja aun tiene clientes
