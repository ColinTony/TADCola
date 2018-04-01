/*
	Libreria ? : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declaran las funcinones para dibujar las cajas
*/

// Descripcion los codigos para los colores
    /*
    * 0x000 son punteros ? para los valores de los colores
    * FOREGROUND_BLUE 0x0001  color AZUL.
	* FOREGROUND_GREEN 0x0002 color VERDE.
	* FOREGROUND_RED 0x0004	color ROJO.
	* FOREGROUND_INTENSITY 0x0008 intensidad de color.
	* BACKGROUND_BLUE 0x0010	ponemos un fondo azul
	* informacion obtenida de la documentacion de Windows https://docs.microsoft.com/en-us/windows/console/char-info-str
    */
enum colores{
    BLACK             = 0,
    DARKBLUE          = 0x0001,
    DARKGREEN         = 0x0002,
    DARKCYAN          = 0x0002 | 0x0001,
    DARKRED           = 0x0004,
    DARKMAGENTA       = 0x0004 | 0x0001,
    DARKYELLOW        = 0x0004 | 0x0002,
    DARKGRAY          = 0x0004 | 0x0002 | 0x0001,
    GRAY              = 0x0008,
    BLUE              = 0x0008 | 0x0001,
    GREEN             = 0x0008 | 0x0002,
    CYAN              = 0x0008 | 0x0002 | 0x0001,
    RED               = 0x0008 | 0x0004,
    MAGENTA           = 0x0008 | 0x0004 | 0x0001,
    YELLOW            = 0x0008 | 0x0004 | 0x0002,
    WHITE             = 0x0008 | 0x0004 | 0x0002 | 0x0001,
 }colores;

void dibujar(superMerc *super); // con el dibujamos las cajas de las cajeras dependiendo el numero cajas //
void setColor(int valorColor);		// funcion para cambiar de color el texto que vayamos a imprimir en pantalla
void printCola(int x, int y , cola *cola);
