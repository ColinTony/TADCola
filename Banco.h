/*
	Libreria ? : Banco
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0
	Autor : Colin Heredia Luis Antonio
	DESCRIPCIÓN: Se definen las funciones y estructuras para el banco
*/
#define MAX_CAJAS 10

// estructura para las cajas del banco
typedef struct cajaBank
{
	int tiempoAte; 			// tiempo de atencion de las cajas 
	boolean isDisponible;	// saber si la caja no esta atendiendo

}cajaBank;

// estructura del banco y sus tres colas
typedef struct banco
{
	char nombreBanco[30];
	// colas del banco
	cola colaClie;			// cola de clientes del banco
	cola colaUsuario;		// cola de usuarios del banco
	cola colaPrefe; 		// cola de clientes preferentes

	int timeClie;			// tiempo de llegada de los clientes
	int timeUsuario;		// tiempo de llegada de los usuarios del banco
	int timePrefe;			// tiempo de llegada de los clientes preferentes 
	int numeroCajas; 		// numero de cajas establecidas por el usuario
	int cliente;			// numero del cliente

	cajaBank cajas[MAX_CAJAS]; 	// cajas creadas por el usuario

}banco;

void abrirBanco(banco *banco);		// inicializa las variables y dibuja el banco
void pedirTiempos(banco *banco);	// pedimos los tiempos de cada caja
void initBanco(banco *banco);		// iniciamos nuestra simulacion
