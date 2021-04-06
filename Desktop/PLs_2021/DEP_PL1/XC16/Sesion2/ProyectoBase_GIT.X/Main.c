/*
 * File:   Main.c
 * Author: SEA - Aitor VA
 * D.E.P. - GiTELE - 2019-2020
 */

/* 
 * File:   Main.c
 * Author: AVA

 */

/* Este proyecto tiene como objetivo proveer los archivos base y la estructura
 * Típica de programación para usar durante la asignatura. Léease con atención
 * las recomendaciones y las instrucciones de uso.
 */

// SIEMPRE SE INCLUIRÁN ESTOS ARCHIVOS DE CABECERA:
#include "Config.h"
#include "Main.h"
#include "Func.h"

//---------------------------------------------------------------------------
// Global variables
//---------------------------------------------------------------------------
// En este espacio pueden declararse las variables globales o las constantes.
unsigned int caso1 = 0;
unsigned int caso2 = 0;
unsigned int casos = 0;
unsigned int efecto = 0;
unsigned int pulso = 1;

//---------------------------------------------------------------------------
// ISR routine
//---------------------------------------------------------------------------

// Llamada a la subrutina de interrupción. Descomentar estas líneas para activarla.
// Debe incluirse el nombre de la rutina de interrupción (vector de interrupción).
// Esta llamada a la función de interrupción debe repetirse tantas veces como
// vectores de interrupción haya (cada una, con su vector correspondiente)

void __attribute__((interrupt, auto_psv))_T1Interrupt(void)
{
      IFS0bits.T1IF = 0;
      casos++;
      if(casos == 8){
            casos=0;
        }
      switch(efecto){
          case 0:
              Efecto0();
              break;
          case 1:
              Efecto1(casos);
              break;
          case 2:
              Efecto2(casos);
              break;
          default:
              Efecto0();
              break;
      }
      
      CambioPR1(pulso);
 
}

//Interrupcion SW1 -> CAMBIA EFECTO
void __attribute__((interrupt, auto_psv))_INT1Interrupt(void){
    IFS1bits.INT1IF = 0;
    efecto++;
    if (efecto == 3){
        efecto = 0;  //RESET de efectos
        casos = 0; //RESET de casos
        LATD = 0xFFFF; //APAGO LOS LEDS 
    }//Cierrp if     

}

//Interrupcion SW4 -> Cambia temporizacion
void __attribute__((interrupt, auto_psv))_INT4Interrupt(void){
   
    IFS2bits.INT4IF = 0;
    pulso++;
    if (pulso == 5){
        pulso = 1;  //RESET de efectos
    }//Cierrp if 
 
}
//---------------------------------------------------------------------------
// Main routine
//---------------------------------------------------------------------------

// Función principal. Siempre incluye un bucle infinito.

int main (void)
{   
    // Aquí se declararían las variables LOCALES a la función Main.
    InitIO();
    
    //primer metodo (funciones propias)
    //T1CON = 0;
    //TMR1 = 0;
    PR1TMR1;//Temporizar a 0.5 s 
    //T1CON = 0x8030
    
    
    //segundo metodo (registros)
    CloseTimer1();
    WriteTimer1(0);
    ConfigIntTimer1(T1_INT_ON & T1_INT_PRIOR_1); //PARA INTERRUPCION
    OpenTimer1(T1_ON & T1_IDLE_STOP & T1_GATE_OFF & T1_PS_1_256 & T1_SYNC_EXT_OFF & T1_SOURCE_INT,PR1);
    
    
    //timer2 y timer3
    /*float PR = 0;
    PR = (FCY/1)/2;
    
    CloseTimer23();
    WriteTimer23(0);
    OpenTimer23(T2_ON & T2_IDLE_STOP & T2_GATE_OFF & T2_PS_1_1 & T2_32BIT_MODE_ON & T2_SOURCE_INT,PR);
    */

    
     ConfigINT();
     CambioPR1(pulso);
    while (1)   // bucle infinito
    {
        
    }
   
    return 0;
    
}// Main
