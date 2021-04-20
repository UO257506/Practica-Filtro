/* 
 * File:   Main.c
 * Author: Local Hero
 *
 * Created on 26 de marzo de 2018, 10:18
 */

#include "Config.h"
#include "Main.h"
#include "Func.h"
#include "LCD_display.h"



// Global variables
//unsigned int Pot6[M];      // For storing ADC output
//unsigned int posicion = 0;
//
////---------------------------------------------------------------------------
//// ISR routine. ADC
////---------------------------------------------------------------------------
//void __attribute__((interrupt, auto_psv)) _ADCInterrupt(void)
//{
//	IFS0bits.ADIF = 0;          // Clean flag
//    Pot6[posicion] = ADCBUF6;   // Reading the ADC    
//    ADCON1bits.ADON = 1;        // turn ADC ON
//}


//---------------------------------------------------------------------------
// Main routine
//---------------------------------------------------------------------------

// Función principal. Siempre incluye un bucle infinito.

int main (void)
{   
    // Initialize 
    InitIO();                    // Initialize I/O ports
   /* InitTMR3();                  // Initialize TMR3
    InitADC();                  // Initialize ADC
    ConfigInt();               // Configure interrupts 
    
    T3CONbits.TON = 1;         // Start TMR3
        */
    
    InitLCD();
    MostrarNombre();
    while (1)   // bucle infinito
    {
   
    }
    
    return 0;
    
}// Main
