/*
	Libreria ? : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declara las funciones de Banco.h
*/

#include <stdio.h>
#include <stdlib.h>
// mis .h
#include "Presentacion.h"
#include "TADColaDin.h"	
#include "Banco.h"
#include "SuperMercado.h" // para usar el isMultiplo(int num);

/*
	void abrirBanco(banco *banco)
	Descripción: Realiza Dibuja las cajeras que pidio el usuario y el nombre del super mercado
	Recibe:  super
	Devuelve: void.
*/
void abrirBanco(banco *banco)
{
	// inicializar mis variables del banco y dibujar
	Initialize(&banco->colaClie); 		// cola clientes
	Initialize(&banco->colaUsuario);	// cola usuario
	Initialize(&banco->colaPrefe);		// cola Preferente

}

/*
	void pedirTiempos(banco *banco)
	Descripción: pedir los tiempos de atencion de las cajas
	Recibe:  baco para pedir los tiempos de cada cajas
	Devuelve: void.
*/
void pedirTiempos(banco *banco)
{

	puts("Ingrese el numero de cajeros que se atenderan");
	scanf("%d",&banco->numeroCajas); // pedimos el numero de cajas
}