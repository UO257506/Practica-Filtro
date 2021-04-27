#include "Main.h"
#include "Func.h"

#include "dsp.h"
#include "math.h"

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

// VARIABLES COMUNES A UTILIZAR EN GENERAONDA Y FILTRAR
unsigned int fsample, freca, frecb, frecc;
fractional entrada[NUM_SAMPLES];//senoide generada
fractional filtrada[NUM_SAMPLES];//Array de datos filtrados, datos fraccionales 1.15 de [-1,1)
    
float sinA[NUM_SAMPLES]; //Array de senoide simulada A
float sinB[NUM_SAMPLES]; //Array de senoide simulada B
float sinC[NUM_SAMPLES]; //Array de senoide simulada C

void generaonda(void)
{
    unsigned int n = 0;

    fsample = 10000;    // Frecuencia de Muestreo de 10 KHz
    freca   = 	847;    // Senoide de 847 Hz 
    frecb	=	367;    // Senoide de 367 Hz
    frecc 	= 	123;    // Senoide de 123 Hz
			
    for (n=0; n < NUM_SAMPLES; n++)
    {
      sinA[n] = sin((2*PI*freca*n)/fsample);            // Creamos una senoide por puntos de la frecuencia A
      sinB[n] = sin((2*PI*frecb*n)/fsample);            // Creamos una senoide por puntos de la frecuencia B
      sinC[n] = sin((2*PI*frecc*n)/fsample);            // Creamos una senoide por puntos de la frecuencia C
      entrada[n] = ((sinA[n]+sinB[n]+sinC[n])/3)*0x8000;  // Escalamos el flotante a fraccional (Creo la señal de entrada)
      
    }
    return;
}

void filtrar (void)
{
    /* Variables externas generadas con la toolbox FilterDesigner de MatLab */
    extern FIRStruct pasobandaFilter;

   	FIRDelayInit (&pasobandaFilter); //Inicializamos el Filtro

  	FIR (NUM_SAMPLES, &filtrada[0], &entrada[0], &pasobandaFilter); //Llamamos a la rutina de Filtro
    
   return;
} 