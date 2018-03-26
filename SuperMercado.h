/*
	Libreria ? : Super
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declaran las funcinones para el manejo del super mercado.
*/
#define MAX_CAJAS 10

typedef struct caja
{
	int timeAte; 		// tiempo de atencion de la cajera
	boolean isVacia; 	// saber si su cola esta vacia
	cola clientes; 		// cola clientes formados en la cola

}caja;

// Tipo de super mercado el cual tiene las cajas 
typedef struct super
{	
	char nombreSuper[50]; 		// nombre del super mercado maximo 50 Caracteres
	int cajeras; 				// numero de cajeras
	int atendidos;				// saber cuantas clientes ya se atendieron
	int timeClie;			// tiempo de llegada de cada cliente
	caja cajas[MAX_CAJAS]; 		// numero maximo de cajas
	boolean open; 				// bandera para saber si esta abierto

}superMerc;

typedef struct cliente
{
	char cara; 		// el caracter con codigo asicii
	int numClie;	// el numero de cliente

}cliente;

boolean isOpen(superMerc *super); 					// Para seber si esta abierto el super mercado
boolean isCajaEmpty(cola *cola);					// para saber si la caja aun tiene clientes
void abrirSuper(superMerc *super);					// inicializa todo , abre el supermercado 
boolean verificaCajas(superMerc *super); 			// verifica si esta dentro del rango y las inicializa
boolean isMultiplo(int num);						// Verifica si es multiplo de 10
void empezar(superMerc *super);