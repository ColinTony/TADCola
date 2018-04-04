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

	if(banco->numeroCajas > MAX_CAJAS || banco->numeroCajas <= 0) // si es mayor a 10
	{
		// si es mayor a 10
		 puts("ERROR: NO PODEMOS EMPEZAR CON ESAS CAJAS");
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
	int turnosPrefe;
	int turnosClie;
	unsigned int tiempo = 0; // tiempo
	unsigned int clie = 0; // clientes llegados

	elemento element;	// elemento para ingresar en la cola

	// tiempos de llegada del cliente del banco y los tiempos de atencion
	mcd =  	 MCD(banco->cajas[0].tiempoAte,banco->timeClie); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada cliente
	auxMcd = MCD(banco->cajas[0].tiempoAte,banco->timeUsuario); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada usuario
	auxMcd = MCD(banco->cajas[0].tiempoAte,banco->timePrefe); // primero con el tiempo de atencion del arreglo en pos 0 y tiempo de llegada clie Pref.
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
		banco->cajas[i].tiempoAte /= mcd; 
	// ahora todos son multiplos	
	banco->timeClie /= mcd;
	banco->timeUsuario /= mcd;
	banco->timePrefe /= mcd;

	/*
	MoverCursor(50,50);
	printf("MCD final %d ", mcd);
	for(i=0; i<banco->numeroCajas; i++)
		printf("Tiempo caja : %d" , banco->cajas[i].tiempoAte);
	*/
	while(TRUE) // bucle infinito
	{
		// esperamos los milisegundos
		EsperarMiliSeg(mcd); // Tiempo base
		tiempo++;

		if(tiempo%banco->timePrefe == 0) // se forma un nuevo cliente preferente a la fila
		{
			clie++; // sumamos un cleinte que llego
			element.n = clie;
			Queue(&banco->colaPrefe,element); // encolamos elemento
			aux = Size(&banco->colaPrefe);
			MoverCursor(17,aux+12);
			printf("P->%d",clie);
		}

		if(tiempo%banco->timeUsuario == 0) // se forma un nuevo usuario a la fila
		{
			clie++; // sumamos un cleinte que llego
			element.n = clie;
			Queue(&banco->colaUsuario,element); // encolamos elemento
			aux = Size(&banco->colaUsuario);
			MoverCursor(17*2,aux+12);
			printf("U->%d",clie);
		}

		if(tiempo%banco->timeClie == 0) // se forma un nuevo cliente a la fila
		{
			clie++; // sumamos un cleinte que llego
			element.n = clie;
			Queue(&banco->colaClie,element); // encolamos elemento
			aux = Size(&banco->colaClie);
			MoverCursor(17*3,aux+12);
			printf("C->%d",clie);
		}
		

	}
}
