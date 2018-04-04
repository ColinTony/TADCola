/*
	Libreria ? : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declara las funciones de Banco.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// mis .h
#include "Presentacion.h"
#include "TADColaDin.h"	
#include "Banco.h"
#include "SuperMercado.h" // para usar el isMultiplo(int num);
#include "Dibujar.h"
/*
	void abrirBanco(banco *banco)
	Descripción: Realiza Dibuja las cajeras que pidio el usuario y el nombre del super mercado
	Recibe:  super
	Devuelve: void.
*/
void abrirBanco(banco *banco)
{
	int i;
	banco->cliente=0; 
	// inicializar mis variables del banco y dibujar
	Initialize(&banco->colaClie); 			// cola clientes
	Initialize(&banco->colaUsuario);		// cola usuario
	Initialize(&banco->colaPrefe);			// cola Preferente
	
	// inicializamos su dispobiblididad
	for(i=0; i<banco->numeroCajas; i++)
		banco->cajas[i].isDisponible = FALSE;	// disponibilidad
	
	// pedimos los datos de las cajas
	pedirTiempos(banco);
	// iniciar a simulacion
	initBanco(banco);

}
/*
	void pedirTiempos(banco *banco)
	Descripción: pedir los tiempos de atencion de las cajas
	Recibe:  baco para pedir los tiempos de cada cajas
	Devuelve: void.
*/
void pedirTiempos(banco *banco)
{
	int i;
	int tiempoAte; // auxiliar para guardar el tiempo de atencion
	puts("Ingrese el nombre del banco");
	fflush(stdin); // Borrar el buffer
	gets(banco->nombreBanco); // pedimos el nombre del banco
	strupr(banco->nombreBanco); // pasamos todo a Mayusculas
	puts("Ingrese el numero de cajeros que se atenderan");
	scanf("%d",&banco->numeroCajas); // pedimos el numero de cajas

	if(banco->numeroCajas > MAX_CAJAS) // si es mayor a 10
	{
		// si es mayor a 10
		 puts("ERROR , NO TENEMOS TANTAS CAJAS");
		 exit(1);
	}
	// recorremos las cajas
	for(i = 0; i<banco->numeroCajas; i++)
	{
		printf("Ingresa el tiempo de atencion de la cajera %i (MS): ", i+1);
		scanf("%d",&tiempoAte);
		
		if(!isMultiplo(tiempoAte)) // si no es multiplo matamos el proceso
		{
			puts("ERROR: EL TIEMPO INGRESADO NO ES MULTIPLO DE 10");
			exit(0);
		}

		// si es multiplo entonces guardamos el tiempo
		banco->cajas[i].tiempoAte = tiempoAte;
	}

	// Tiempos de llegada de los clientes
	puts("Teclea el tiempo de llegada de los clientes del banco (MS) : ");
	scanf("%d",&banco->timeClie); // tiempo de llegada de clientes
	puts("Teclea el tiempo de llegada de los usuarios del banco (MS) : ");
	scanf("%d",&banco->timeUsuario); // tiempo de usuarios
	puts("Ingresa el tiempo de llegada de los clientes preferentes (MS) : ");
	scanf("%d",&banco->timePrefe); // tiempo de clientes preferentes
	// si alguno no es multiplo se muere el programa
	if(!isMultiplo(banco->timeClie) || !isMultiplo(banco->timeUsuario) || !isMultiplo(banco->timePrefe))
	{
		puts("ERROR: ALGUNO DE LOS TIEMPOS INGRESADOS NO ES MULTIPLO DE 10");
		exit(0);
	}
	dibujarBanco(banco);

}

/*
	void initBanco(banco *banco)
	Descripción: iniciamos la simulacion
	Recibe:  banco , para obtener los datos previamente ingresados
	Devuelve: void.
*/
void initBanco(banco *banco)
{
	int i,j; 	 // contadores
	int aux;	 // auxiliar 
	int mcd; 	 // minimo comun divisor
	int auxMcd;  // auxiliaar del MCD
	int aux2Mcd; // auxiliar mcd
	unsigned int tiempo = 0; // tiempo
	unsigned int clie = 0; // clientes llegados

	elemento cliente;	// elemento para ingresar en la cola

	// tiempos de llegada del cliente del banco y los tiempos de atencion
	mcd = MCD(banco->cajas[0].tiempoAte,banco->timeClie); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada cliente
	auxMcd = MCD(banco->cajas[0].tiempoAte,banco->timeUsuario); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada usuario
	auxMcd = MCD(banco->cajas[0].tiempoAte,banco->timeUsuario); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada clie Pref.
	// sacamos el mcd entre todos los tiempos de antencion
	for(i=1; i<banco->numeroCajas; i++)
	{
		mcd = MCD(mcd,banco->cajas[i].tiempoAte);
		auxMcd = MCD(auxMcd,banco->cajas[i].tiempoAte);
		aux2Mcd = MCD(aux2Mcd,banco->cajas[i].tiempoAte);
	}

	// sacamos el mcd entre los auxiliares mcd y el mcd
	mcd = MCD(mcd,auxMcd);
	mcd = MCD(mcd,aux2Mcd);

	// dividimos el mcd entre los tiempos de atencion de las cajas
	for(i = 0; i<banco->numeroCajas; i++)
		banco->cajas[i].tiempoAte /= mcd; // Ahora los tiempos de atencion ya son multiplos del tiempo de espera

	while(TRUE) // bucle infinito
	{
		// esperamos los milisegundos
		EsperarMiliSeg(mcd); // Tiempo base
		tiempo++;
		if(tiempo%banco->timePrefe == 0) // se forma un nuevo cliente preferente a la fila
		{
			clie++;
			element.n = cliente;
			Queue(&banco->colaPrefe,element); // encolamos elemento
			MoverCursor(40,SizeCola(&filas[0])+5);
			printf("%d",cliente);
		}
	}
}
