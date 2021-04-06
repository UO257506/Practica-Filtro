#include "Main.h"
#include "Func.h"

/* Este archivo contendrá la definición de las funciones auxiliares que se
 * necesiten para la ejecución del código.
 * Pueden añadirse tantas como se quiera.
 * El objetivo es encapsular lo máximo posible el código y reutilizar todas las+
 * funciones posibles.
 * En el archivo FUNC.H deberán incluirse los prototipos de estas funciones.
 */

// Ejemplo:
// FUNCIÓN PARA INICIALIZACIÓN DE PUERTOS E/S
// Parámetros de entrada: ninguno (void).
// Parámetros de salida: ninguno (void).
void InitIO()
{
    LATD = 0xFFFF;                //Turn off all LEDS
    TRISD = 0xFFF0;               //Set LED pins as outputs
    TRISA = 0xFFFF;               //Set pushbutton switch pins as inputs
    return;
}// InitIO

void Efecto1(unsigned int cont){
    switch(cont){
        case 0:LATD=0xFFFE;
        break;
        case 1:LATD=0xFFFD;
        break;
        case 2:LATD=0xFFFB;
        break;
        case 3:LATD=0xFFF7;
        break;
        default:LATD=0xFFFF; 
    }
    return;
}

void Efecto2(unsigned int cont){
    switch(cont){
        case 0:LATD=0xFFFE;
        break;
        case 1:LATD=0xFFFC;
        break;
        case 2:LATD=0xFFF8;
        break;
        case 3:LATD=0xFFF0;
        break;
        case 4:LATD=0xFFF8;
        break;
        case 5:LATD=0xFFFC;
        break;
        case 6:LATD=0xFFFE;
        break;
        default:LATD=0xFFFF; 
    }
    return;
}

void Efecto2bis(unsigned int cont){
    switch(cont){
        case 0:LATD=((PORTD<<1) & 0xFFFE);//encender los leds
        break;
        case 1:LATD=((PORTD>>1) | 0x0008);//apagar los leds
        break;
    }
    return;

}