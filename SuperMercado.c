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
	// sin codigo(por ahora)
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
	int numeroCaja; // numero de la caja a formarse
	int aux; // auxiliar
	int i,j; // contador
	int mcd; // minimo comun divisor
	unsigned int tiempoBase = 0; // tiempo 
	unsigned int clientes = 0;
   	elemento cliente;
   	// inicializamos las cajas
   	for(i = 0; i<super->cajeras; i++)
   	{
   		// establecemos la disponibilidad por ahora de las cajeras
   		super->cajas[i].isDispo=TRUE; 
   		// inicializamos las colas
   		Initialize(&super->cajas[i].clientes);
   	}
   	// Obtenemos el minimo comun divisor entre el mcd de los tiempos con 
   	// la llegada del cliente
   	mcd = MCD(super->cajas[0].timeAte,super->timeClie);
   	/* Obtenemos el minimo comun divisor de los tiempos de atencion */
   	for (i = 1; i < super->cajeras; i++)
   		mcd = MCD(mcd,super->cajas[i].timeAte);
   	
   	// dividimos el tiempo de llegada entre mcd
   	super->timeClie /= mcd; 
	while(TRUE) // Bucle infinito
	{
		// esperamos los milisegundos
		EsperarMiliSeg(mcd); // Tiempo base
		if((tiempoBase%super->timeClie) == 0) // si ya transcurrio un multiplo del tiempo de llegada se forma un cliente en la fila
		{
			numeroCaja = rand() % super->cajeras; // numero aletario del 0 al 10
			clientes++; // sumamos un cliente
			cliente.n = clientes;
			Queue(&super->cajas[numeroCaja].clientes,cliente);
			aux = Size(&super->cajas[numeroCaja].clientes); // para la posicion en Y
			MoverCursor((numeroCaja)*17,aux+12);
			printf("%d",cliente.n);
		}
		// recorremos los cajeros
		for(i=0; i<super->cajeras; i++)
		{	// si es multiplo del tiempo de atencion o la caja esta disponible
			if(tiempoBase%super->cajas[i].timeAte || (super->cajas[i].isDispo == TRUE))// saber si la cajera puede antender
			{
				// preguntamos si no esta vacia
				if(!Empty(&super->cajas[i].clientes))
				{
					super->cajas[i].isDispo= FALSE;
					aux = Size(&super->cajas[i].clientes); // obtenemos tam de la cola
					cliente = Dequeue(& super->cajas[i].clientes);
					MoverCursor(i*17,10); // posiciones x,y
					printf("(-.-)->%d \n",cliente.n);
					if(!Empty(&super->cajas[i].clientes)) 
					{
						// si no esta vacia
						//reacomodamos las filas
						for(j=0; j<aux; j++) // aux->Tamaño de la cola
						{
							MoverCursor(i*17,13+j); // reajustamos la fila j?
							cliente = Element(&super->cajas[i].clientes,j+1);
							printf("%d", cliente.n);
						}
						MoverCursor(i*10,12+aux);
						printf("   %d  ",cliente.n);
					}
					else
					{// si esta vacia 
						MoverCursor(i*17,13);
						printf("  %d   ",cliente.n); // borramos 
					}
				}
				else // si no
				{
					if(super->cajas[i].isDispo==FALSE)
					{
						super->cajas[i].isDispo = TRUE; // esta disponible
						printf("        ");	
					}
				}
			}
		}
		// si ya se atendieron mas de 100 clientes podemos cerrar
		if(clientes>=100)
		{
			setColor(RED); // cambiamos el color Rojo
			MoverCursor(30,1); // movemos el cursor
			printf("LA TIENDA %s CERRARA EN CUANTO LAS COLAS SE VACIEN ", super->nombreSuper); // avisar que cerrara
			j = 0; // inicializamos denuevo el contador
			for(i=0; i<super->cajeras; i++)
			{
				if(Empty(&super->cajas[i].clientes))
					j++;// si esta vacia sumamos uno a j que cuenta nuestras cajas vacias
			}
			// si todas nuestras cajas estan vacias cerramos
			if(j==super->cajeras)
			{
				BorrarPantalla(); // borramos la pantalla
				setColor(DARKMAGENTA); // cambiamos de color
				MoverCursor(90,10);
				printf("%s", "LA TIENDA HA CERRADO SUS PUERTAS");
				// destruimos colas
				for(i=0; i<super->cajeras; i++)
					Destroy(&super->cajas[i].clientes);
				system("color 07"); // ponemos colores predeterminados
				break;
			}

		}
		tiempoBase++; // sumamos mi tiempo base
	}
}
/*
	int MCD (int menor , int mayor)
	Descripción: Algoritmo para sacar el minimo comun divisor usando algoritmo de euclides
	Recibe:  int menor , int mayor donde mayor>menor
	Devuelve: int
*/
int MCDEuclides(int menor , int mayor)
{
	int residuo = mayor%menor;
	if(residuo==0)
		return menor; // si la division es exacta , encontramos el MCD
	else // si no mandamos el residuo y volvemos a divir hasta que el residuo sea 0
		return MCDEuclides(residuo,menor); // recursiva
}
/*
	int MCD (int num1 , int num2)
	Descripción: Algoritmo para sacar el minimo comun divisor usando algoritmo de euclides
	Recibe:  int numero , int numero2
	Devuelve: int
*/
int MCD (int num1 , int num2)
{
	int aux_num; // auxiliar
	// acomodamos los numeros de mayor a menor
	if(num1>num2) // saber si num1 es mayor
	{
		aux_num=num1; // se guarda valor en auxiliar
		num1=num2; // se iguala a num2 
		num2=aux_num; // y se cambia el valor por el auxiliar
	}
	// num 1 es el menor y num2 es el mayor
	return MCDEuclides(num1,num2); // realizamos MCD con el algoritmo de euclides
}