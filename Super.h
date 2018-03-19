/*
	Libreria ? : Super
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declaran las funcinones para el manejo del super mercado.
*/
#define MAX_CAJAS = 10;

// Tipo de super mercado el cual tiene las cajas 
typedef struct super
{	
	char nombreSuper[]; // nombre del super mercado
	int cajeras;
	caja cajas[cajeras]; // numero maximo de cajas
	boolean open;
}super;

typedef struct cajera
{
	int timeAtencion; // tiempo de atencion de la cajera
	boolean isVacia;
}cajera;

boolean isOpen(); 		// Para seber si esta abierto el super mercado
boolean isCajaEmpty() 	// para saber si la caja aun tiene clientes
void abrirSuper();		// inicializa todo 