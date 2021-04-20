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



//Global variables
//unsigned int Pot6[M];      // For storing ADC output
//unsigned int posicion = 0;
//

float temperatura=0.0;
float POT=0.0;
////---------------------------------------------------------------------------
//// ISR routine. ADC
////---------------------------------------------------------------------------
//void __attribute__((interrupt, auto_psv)) _ADCInterrupt(void)
//{
//	IFS0bits.ADIF = 0;          // Clean flag
//    Pot6[posicion] = ADCBUF6;   // Reading the ADC    
//    ADCON1bits.ADON = 1;        // turn ADC ON
//}

void __attribute__((interrupt, auto_psv)) _ADCInterrupt(void)
{
    //lectura del sensor de temperatura
    /*
	IFS0bits.ADIF = 0;          // Clean flag
    unsigned int valorADC=0;
    float voltage_level =0.0;
    
    valorADC = ADCBUF8;   // leer el buffer de ADC    
    voltage_level = valorADC*(5.0/4095); //normalizar el valor de tension de CAD
    temperatura = (100*voltage_level)-50;  //
    */
    
    //Lectura del potenciometro
    IFS0bits.ADIF = 0;          // Clean flag
    unsigned int potADC=0;
    potADC = ADCBUF4;   // leer el buffer de ADC    
    POT = potADC*(5.0/4095); //normalizar el valor de tension de CAD
  

}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)//sensor de temperatura
{
	IFS0bits.T1IF = 0;          // limpiar el flag
    T1CONbits.TON = 0;          //arrancar TMR1
    TMR1 = 0;                   //Limpiar TMR1
    
    InitLCD();                  //Inicializacion del LCD
    //PrintTemperatura(temperatura); //llamar a la funcion para visualizar la temperatura
    PrintPotencia(POT);
    
    T1CONbits.TON = 1; //encendemos TMR1
    
}
//---------------------------------------------------------------------------
// Main routine
//---------------------------------------------------------------------------

// Función principal. Siempre incluye un bucle infinito.

int main (void)
{   
    // Initialize 
    InitIO();                    // Initialize I/O ports
    
    InitTMR3();                  // Initialize TMR3
    InitTMR1();                  // Initialize TMR1
    
    InitADC();                  // Initialize ADC
    ConfigInt();               // Configure interrupts 
    
    T1CONbits.TON = 1;         // Start TMR3
    T3CONbits.TON = 1;         // Start TMR3
     
    
    //InitLCD();
    //MostrarNombre();


    while (1)   // bucle infinito
    {
   
    }
    
    return 0;
    
}// Main
