
// Autor : Dayron avila ramirez

#include "proceso.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADColaDin.h"
#include <windows.h>
#include "presentacion.h"

/*
	void Abrir_procesos();
	Descripción: declara cuandos procesos se van a realizar
	Devuelve: void
*/
void Abrir_procesos()
{
	int aux;
	puts("Hola");
	puts(" Bienvenido a simulacion de procesos. Indica la cantidad de procesos a realizar ");
	scanf("%d",&aux);
	crear_procesos(aux);//llamada de la funcion que recibe como argumento un entero que es el numero de procesos que vamos a realizar

}

/*
	void crear_procesos(int aux);
	Recibe: int aux.
	Descripción: Recibe el numero de procesos a realizar para pedir la informacion de cada uno de ellos
	Devuelve: void
*/
void crear_procesos(int aux)//funcion que recibe el entero que es el numero de procesos a realizar, no retorna nada
{
	int i;
	proceso mi_proceso[aux];//creamos un arrelo del tamaño del numero de procesos, en este arreglo tendremos una estructura con los datos a llenar
	for (i =0; i< aux ;i++)
	{
		printf("Nombre del proceso %d\n",i+1);//solicitamos el nombre del proceso
	    scanf("%s",&mi_proceso[i].Nombre);//guardamos el nombre aunque lleve espacios la funcion fgets nos deja guardarlo, no sirve asi , decidi un scanf sin contar espacios
		printf("Dime la actividad del proceso %d\n",i+1);//solicitamos la actividad del proceso
		scanf("%s",&mi_proceso[i].Actividad);//guardamos esa actividad
		printf("Escribe ID del proceso %d\n",i+1);//solicitamos el ID
		scanf("%s",&mi_proceso[i].ID);//lo guardamos 
		printf("Dame el tiempo en segundos del proceso %d \n",i+1);//finalmente pedimos el tiempo que tardara en ejecutarse
		scanf("%d",&mi_proceso[i].Tiempo);//lo guardamos en tiempo dentro de nuestra estructura
		mi_proceso[i].total=0;
	}
	i=aux;
	inicia_proceso(mi_proceso,i);//funcion que recibe un arreglo que en este caso es nuetsro arreglo con los datos de los procesos y un entero que es el numero de procesos

}

// documentar
void inicia_proceso(proceso mi_proceso[],int aux)
{
	cola listos, terminados;
	int contador=0,n=2,i; // contadores
	elemento e,e2,e3; // elementos auxiliares

	// inicializamos nuestras colas
	Initialize(&listos);
	Initialize(&terminados);

	for (contador= 0;contador<aux;contador++)
	{
		e.n=contador;// nos servira como identificador de cada proceso 
		Queue(&listos,e);//los metemos a la cola de listos en el orden que nos dieron los procesos
	}
	contador=0;
	i=0;// ciclo infinito que nos servira para realizar los procesos
	while(n>1)
	{
		EsperarMiliSeg(1000);// tiempo de espera 
		contador++;// nuestro contador que nos servira para saber el tiempo total de cada proceso 
		BorrarPantalla();// borramos la pantalla para ver la nueva informacion

		if (contador == 1)// al inicio no hay proceso anterior pero si actual y siguiente por lo que solo se aplicara una vez esta parte de codigo
		{
			 
			 printf("El Ultimo proceso es :\t\t\t\n");
			 printf("El ID del ultimo proceso es:\t\t\t\n");
			 printf("La actividad del proceso es:\t\t\n");// damos informacion sobre el nombre la actividad y su estado en cuestion de tiempo
			 printf("El Tiempo faltante para concluir es:\t\t\n");
			 printf("\n\n\n");
			 e=Dequeue(&listos);// sacamos el primer identificador y damos a conocer su estado de proceso
			 printf("El Proceso actual es :\t\t\t%s\n",mi_proceso[e.n].Nombre);
			 printf("El ID del proceso es:\t\t\t%s\n",mi_proceso[e.n].ID);
			 printf("La actividad del proceso es:\t\t%s\n",mi_proceso[e.n].Actividad);
			 printf("El Tiempo de ejecucion total:\t\t%d\n",contador);
			 mi_proceso[e.n].Tiempo--;// Como pedimos el tiempo que tarda cada cosa le iremos quitando uno hasta llegar a cero
			 mi_proceso[e.n].total++;// le sumaremos uno a total ya que al final nos piden el tiempo total de ejecucion
			 e2=e;// lo copiamos para ahora mostrar el proceso actual , como el proceso anterior o el ultimo proceso
			 
			 if (mi_proceso[e.n].Tiempo==0)// en caso de que algun proceso haya acabdo 		
			 	Queue(&terminados,e);// lo meteremos en ves de la cola de listos a la de terminados
			 else
			 	Queue(&listos,e);// si aun no acaba el proceoso entonces a la de listos

			 printf("\n\n\n");
			 e=Dequeue(&listos);// sacamos el siguiente proceso para ponerlo como el siguiente proceso a realizar,
			 printf("El Proceso siguiente es :\t\t\t%s\n",mi_proceso[e.n].Nombre);
			 printf("El ID del procesosiguiente es:\t\t\t%s\n",mi_proceso[e.n].ID);
			 printf("La actividad del proceso siguiente es:\t\t%s\n",mi_proceso[e.n].Actividad);
			 printf("El Tiempo faltante para concluir es:\t\t%d\n",mi_proceso[e.n].Tiempo);
			 printf("\n\n\n");

		}
		else// esta parte ya se estara haciendo todo el tiempo hasta que acaben los procesos 
		{
			 printf("El Ultimo proceso es :\t\t\t%s\n",mi_proceso[e2.n].Nombre);
			 printf("El ID del ultimo proceso es:\t\t\t%s\n",mi_proceso[e2.n].ID);
			 printf("La actividad del proceso es:\t\t%s\n",mi_proceso[e2.n].Actividad);
			 printf("El Tiempo faltante para concluir es:\t\t%d\n",mi_proceso[e2.n].Tiempo);
			 printf("\n\n\n");
			 printf("El Proceso actual es :\t\t\t%s\n",mi_proceso[e.n].Nombre);
			 printf("El ID del proceso es:\t\t\t%s\n",mi_proceso[e.n].ID);
			 printf("La actividad del proceso es:\t\t%s\n",mi_proceso[e.n].Actividad);
			 printf("El Tiempo de ejecucion total:\t\t%d\n",contador);
			 printf("\n\n\n");
			 // movemos los tiempos
			 mi_proceso[e.n].Tiempo--;
			 mi_proceso[e.n].total++;
			 e2=e;
			 // preguntamos si el proceso no ha terminado
			 if (mi_proceso[e.n].Tiempo==0)
			 {
			 	mi_proceso[e.n].total+=contador;
			 	Queue(&terminados,e);
			 }
			 else
			 	Queue(&listos,e); // encolamos el proceso a listos

			// si ya no hay procesos que realizar
		 	if (Empty(&listos))// ojo en caso de que ya este vacia la cola de listos ya acabaron los procesos por lo que podemos concluir la simulacion
		 	{
			 printf("El Proceso siguiente es :\t\t\t\n");
			 printf("El ID del procesosiguiente es:\t\t\t\n");
			 printf("La actividad del proceso siguiente es:\t\t\n");
			 printf("El Tiempo faltante para concluir es:\t\t\n");
			 printf("\n\n\n");
			 EsperarMiliSeg(1000);
			 BorrarPantalla();
			 printf("Los procesos han terminado \n\n\n");
			
			 for (i= 0; i <aux ;i++)
			 {
			 	e3=Dequeue(&terminados);// aqui sacaremos el identificador del proceso que acabo primero  y mostraremos us datos
			 	printf("%d.- El proceso\t\t\t%s\n",i+1,mi_proceso[e3.n].Nombre);
			 	printf("Actividad del proceso\t\t\t%s\n",mi_proceso[e3.n].Actividad);
			 	printf("Tiempo total que tardo\t\t\t%d\n",mi_proceso[e3.n].total);
			 }
			 	// Destruimos las colas
			 	Destroy(&terminados);
			 	Destroy(&listos);
			 	system("pause"); // que se pare el proceso 
			 	exit(0);// cuando se acabe de mostrar salimos de la simulacion

			 }
			 
			 e=Dequeue(&listos); // desencolamos
			 printf("El Proceso siguiente es :\t\t\t%s\n",mi_proceso[e.n].Nombre);
			 printf("El ID del procesosiguiente es:\t\t\t%s\n",mi_proceso[e.n].ID);
			 printf("La actividad del proceso siguiente es:\t\t%s\n",mi_proceso[e.n].Actividad);
			 printf("El Tiempo faltante para concluir es:\t\t%d\n",mi_proceso[e.n].Tiempo);
			 printf("\n\n\n");
			 
		}
			
	}



}
