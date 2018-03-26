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
	int timeClientes=0;
	super->cajeras = 0; // ponemos las cajeras en 0
	super->open = TRUE; // abrimos la tienda

	// pedimos al usuario que ingrese el nombre del SuperMercado 
	puts("Ingrese el nombre del SuperMercado (sin espacios): ");
	scanf("%s",super->nombreSuper); // gets(super->nombreSuper); No jalo
	strupr(super->nombreSuper); // pasamos todo a Mayusculas
	puts("Ingresa el numero de cajeras que atenderan : ");
	scanf("%d", &cajas);

	if(cajas == 0)
	{
		puts("ERROR : Debe haber alguna cajera atendiendo "); // no tiene cajeras
		exit(0);
	}
	super->cajeras = cajas; // iniciamos el numero de cajas
	
	// verficamos la cajas
	if(!verificaCajas(super))
	{
		// si no cumple
		printf("%s\n", "El numero de cajas no esta dentro del rango");
		exit(0);
	}
	
	puts("Ingrese el tiempo de llegada de los cientes (MS) : ");
	scanf("%i",&timeClientes);
	if(!isMultiplo(timeClientes))
	{
		// si no es multiplo
		puts("ERROR : El numero ingresado no es multiplo de 10");
		exit(0);
	}
	super->timeClie = timeClientes; // asignamos valor de llegada de clientes
	
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
			if(!isMultiplo(tiempoAte)) // verificar que sea multiplo de 10
			{
				// Si no es multiplo no le asignamos el valor
				puts("ERROR: El numero asignado de tiempo noes multiplo de 10");
				isCorrect=FALSE;
				break; // nos salimos sin asignar nada
			}else // si no , asiganarlo
				super->cajas[i].timeAte = tiempoAte;
			
		}
	}
	return isCorrect;
}
/*
	boolean ismultiplo(int num)
	Descripción: complurueba si el numero ingresado es multiplo de 10
	Recibe:  int
	Devuelve: boolean.
*/
boolean isMultiplo(int num)
{
	boolean isMultiplo=FALSE;
	if(num == 0) // si es el numero cero
	{
		isMultiplo=FALSE;
		puts("ERROR : El numero ingresado no puede ser 0 MS ");
		exit(0);
	}
	if(num%10 == 0)
	{
		isMultiplo=TRUE;
	}
	return isMultiplo;
}
/*
	boolean isCajaEmpty(cola *cola)
	Descripción: comprueba si esta vacia la cola de clientes
	Recibe:  cola
	Devuelve: boolean.
*/
boolean isCajaEmpty(cola *cola)
{
	return Empty(cola);
}
/*
	void empezar(superMerc *super)
	Descripción: Inicia para recibir clientes en las colas y empieza atender clientes
	Recibe:  super
	Devuelve: void.
*/
void empezar(superMerc *super)
{
	int i; // contador
   	
   	// inicializamos las cajas
   	for(i = 0; i<super->cajeras; i++)
   	{
   		// inicializamos las colas
   		Initialize(&super->cajas[i].clientes);
   	}
   	// minimo debemos atender a 100 clientes antes de cerrar
	while(super->atendidos <= 100)
	{
		int numeroCaja = rand() % MAX_CAJAS; // numero aletario del 0 al 10
	}
}
