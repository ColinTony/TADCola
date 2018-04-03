/*
	Libreria ? : Super
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se definen las funciones y estructuras para el super merccado
*/
#define MAX_CAJAS 10

typedef struct caja
{
	int timeAte; 		// tiempo de atencion de la cajera
	boolean isDispo;	// saber si no esta atendiendo a nadie
	cola clientes; 		// cola clientes formados en la cola

}caja;

// Tipo de super mercado el cual tiene las cajas 
typedef struct super
{	
	char nombreSuper[50]; 		// nombre del super mercado maximo 50 Caracteres
	int cajeras; 				// numero de cajeras
	int atendidos;				// saber cuantas clientes ya se atendieron
	int timeClie;				// tiempo de llegada de cada cliente
	caja cajas[MAX_CAJAS]; 		// numero maximo de cajas
}superMerc;


void abrirSuper(superMerc *super);					// inicializa todo , abre el supermercado 
boolean verificaCajas(superMerc *super); 			// verifica si esta dentro del rango y las inicializa
boolean isMultiplo(int num);						// Verifica si es multiplo de 10
void empezar(superMerc *super);						// empieza a recibir clientes
int MCD(int num1 , int num2);						// algoritmo para maximo comun divisor
int MCDEuclides(int menor , int mayor); 			// Algoritmo de euclides 