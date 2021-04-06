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
// Ejemplo:
// unsigned int MiValor = 0;
unsigned int caso1 = 0;
unsigned int caso2 = 0;

//---------------------------------------------------------------------------
// ISR routine
//---------------------------------------------------------------------------

// Llamada a la subrutina de interrupción. Descomentar estas líneas para activarla.
// Debe incluirse el nombre de la rutina de interrupción (vector de interrupción).
// Esta llamada a la función de interrupción debe repetirse tantas veces como
// vectores de interrupción haya (cada una, con su vector correspondiente)

void __attribute__((interrupt, auto_psv))_T1Interrupt(void)
{
    if(PORTAbits.RA12==0){ //sw1=RA12
        caso2++;
        if(caso2==8){
            caso2=0;
        }
        Efecto2(caso2);
    }
    if(PORTAbits.RA12==1){ //sw1=RA12
        caso1++;
        if(caso1==4){
            caso1=0;
        }
        Efecto1(caso1);
    }
    IFS0bits.T1IF = 0;
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
    PR1 = (FCY/256)/2;
    //T1CON = 0x8030;
    
    
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
    
    /*estas variables se comentan para declararlas arriba
    para el uso de interrupcion
    */
    //unsigned int caso1 = 0;
    //unsigned int caso2 = 0;
    unsigned int desplaza;
    
    while (1)   // bucle infinito
    {
       // __delay_ms(500);
        
        //primer dia
        /*LATDbits.LATD0=!LATDbits.LATD0;}
        
        if(PORTAbits.RA15==0){  //sw4
            LATDbits.LATD3=0; //led4
            LATDbits.LATD2=1; //led3
        }
        
        if(PORTAbits.RA14==0){  //sw3
            LATDbits.LATD3=1; //led4
            LATDbits.LATD2=0; //led3
        }
        */
        
        //EFECTO1
       /* if(IFS0bits.T1IF==1){
            IFS0bits.T1IF = 0;
            caso1++;
            if(caso1==4){
                caso1=0;
            }
            Efecto1(caso1);
          }
        */
        
        //EFECTO2
        /*if(IFS0bits.T1IF==1){
            IFS0bits.T1IF = 0;
            caso2++;
            if(caso2==8){
                caso2=0;
            }
            Efecto2(caso2);
        }
        */
        
        //EFECTO2bis
        /*if(IFS0bits.T1IF==1){
            IFS0bits.T1IF = 0;
            if(PORTDbits.RD3==0){
                desplaza = 1;
            }
            if(PORTDbits.RD0==1){
                desplaza = 0;
            }
            Efecto2bis(desplaza);
        }
        */
        
        //EFECTO1 EFECTO2 segun SW1
        /*if(IFS0bits.T3IF==1){ //cambio a T3IF en vez de T1IF para cambiar el timer
            IFS0bits.T3IF = 0;
            if(PORTAbits.RA12==0){ //sw1=RA12
                caso2++;
                if(caso2==8){
                    caso2=0;
                }
                Efecto2(caso2);
            }
            if(PORTAbits.RA12==1){ //sw1=RA12
                caso1++;
                if(caso1==4){
                    caso1=0;
                }
                Efecto1(caso1);
            }
        }
        */
        
    }
    
    return 0;
    
}// Main
