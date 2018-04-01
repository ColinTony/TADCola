//Autor :  Dayron avila ramirez

// estructura para cada proceso con sus especificaciones
typedef struct  proceso
{
	char Nombre[45];			// nombre del proceso
	char Actividad[200];		// la actividad que realizara el proceso
	char ID[45];				// su ID
	int Tiempo;					// El tiempo que tardar en realizar el proceso
	int total;					//tiempo total de ejecucion

}proceso;

void Abrir_procesos();							//funcion que no recibe nada pide cuantos procesos son
void crear_procesos(int aux);					//llena los campos de los procesos con los que se va a trabajar 
void inicia_proceso(proceso mi_proceso[],int);	//empiezan a ejecutarse los procesos
