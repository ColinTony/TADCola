/*
	Libreria ? : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se define la funcion para dibujar las cajas de las cajeras
*/


#include <stdio.h>
#include <Windows.h> // para poder obtener las medidas de la pantalla
#include "Presentacion.h"
#include "TADColaDin.h"
#include "SuperMercado.h"
#include "Dibujar.h"


#define ANCHO  9
#define ALTO   5
/*
	void dibujar(super *super)
	Descripción: Realiza Dibuja las cajeras que pidio el usuario y el nombre del super mercado
	Recibe:  super
	Devuelve: void.
*/
void dibujar(superMerc *super)
{
	// debemos tambien mostrar si esta cerrado o abierto el mercado.
	int colu=0; 	// columna de las cajeras
	int x = 0; // multiplicador para la posicion x
	BorrarPantalla(); // borramos pantalla
	// cambiar el color de las letras para mejor presentacion en C
	// buscar comandos del CMD	
	// color a,b,c,d,e,f,g
	system("mode con: cols=190 lines=50"); // Establecemos por defecto un tamaño de pantalla
	setColor(DARKGREEN); // cambiamos el color a
	MoverCursor(30,0); // movemos el cursor
	printf("NOMBRE DEL SUPERMERCADO: %s\n", super->nombreSuper); // impmimimos el nombre del SuperMercado (buscar como cambiar el tamaño de letra)
	setColor(DARKYELLOW);// ponbemos el color amarillo
	//Recorrer cada colu
	for(colu=1; colu<=super->cajeras; colu++)
	{	
		//Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
		MoverCursor(x*17,8); // cada repeticion se mueve en x -> 10
		EsperarMiliSeg(1000);
		printf("|Caja #%d|",colu); // dibujamos las cajas
		
		x++;
	}

}
/*
	void setColor(int valorColor)
	Descripción: Realiza Dibuja las cajeras que pidio el usuario y el nombre del super mercado
	Recibe:  int con el valor del color deseado
	Devuelve: void.
	Observaciones : En este metodo se utilizan tipos de datos de la api de Windows
*/
void setColor(int valorColor)
{
	HANDLE hOut; // No tengo idea que haga el HANDLE , busque informacion y no se como funciona.

    //La función GetStdHandle devuelve un manipulador para el dispositivo estándar de entrada, salida o error.
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); // dispositivo input, output o error (hexadecimal) vmaos a manipular la salida
 	// Establece los atributos de los caracteres escritos en el búfer de la pantalla de la consola mediante la función WriteFile o WriteConsole
 	// o repetidos por la función ReadFile o ReadConsole. Esta función afecta el texto escrito después de la llamada a la función.
    SetConsoleTextAttribute(hOut,valorColor); // le mandamos el puntero hacia el valor del color
    // Descripcion los codigos para los colores
    /*
    * 0x000 son punteros para los valores de los colores
    *FOREGROUND_BLUE 0x0001  color AZUL.
	*FOREGROUND_GREEN 0x0002 color VERDE.
	*FOREGROUND_RED 0x0004	color ROJO.
	*FOREGROUND_INTENSITY 0x0008 intensidad de color.
	BACKGROUND_BLUE 0x0010	ponemos un fondo azul
	* informacion obtenida de la documentacion de Windows https://docs.microsoft.com/en-us/windows/console/char-info-str
    */
}