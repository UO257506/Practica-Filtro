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


void Efecto0()
{ /*Cambiar el estado de los LEDs*/
    LATDbits.LATD0 =! LATDbits.LATD0;
    LATDbits.LATD1 =! LATDbits.LATD1;      
    LATDbits.LATD2 =! LATDbits.LATD2;
    LATDbits.LATD3 =! LATDbits.LATD3;
    
    return;
}

//LA menor prioridad debe ser la del CPU
void ConfigINT(){
    INTCON1bits.NSTDIS = 1;
    IPC4bits.INT1IP = 3; //DEfinimos la prioridad es ISR
    IFS1bits.INT1IF = 0; //limpia el flag
    IEC1bits.INT1IE = 1; //Habilita la mascara
    
    //Configuracion INT4 para temporizacion variable
    IPC9bits.INT4IP = 2; //DEfinimos la prioridad es ISR
    IFS2bits.INT4IF = 0; //limpia el flag
    IEC2bits.INT4IE = 1; //Habilita la mascara
    
    SET_CPU_IPL(1);
    
    return;
}

void PR1TMR1(){
    PR1 = (FCY/256)/2;  
    return;
}

void CambioPR1(unsigned int cont){
    float tf = (FCY/256)/2;
    PR1 = tf*cont;
    return;
    
    
}
