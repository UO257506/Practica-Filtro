#include "Main.h"
#include "Func.h"
//#include "LCD_display.h"

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
	TRISB = 0xFFFF;     // Initialize PUERTO B as input                
    TRISD = 0xFFF0;     // LED outputs
    LATD = 0xFFF0;      // LED on
    return;
}// InitIO

void InitLCD(void)
{
LCD_Display_Setup(); // INICIALIZA LCD
LCD_Display_Byte(HOME_CLEAR); // BORRA LCD
LCD_Display_Byte(CURSOR_ON); // PONE CURSOR
return;
}

//---------------------------------------------------------------------------
// InitTMR3
//---------------------------------------------------------------------------
void InitTMR3()
{   
    //Initialize Timer3 for 10ms period
    T3CON = 0;                    // Turn off Timer3 by clearing control register
	TMR3 = 0;                     // Start Timer3 at zero
	PR3 = (FCY/256)*0.001;         // Set period register value for 1ms (100 Hz)
    T3CON = 0x0030;               // Configure Timer3 (timer off, continue in IDLE, not gated, 1:256 prescaler, internal clock)    
    return;
}

void InitTMR1()
{   
    //Initialize Timer3 for 10ms period
    T1CON = 0;                    // Turn off Timer1 by clearing control register
	TMR1 = 0;                     // Start Timer1 at zero
	PR1 = (FCY/256)*0.5;         // Set period register value for 500 ms (100 Hz)
    T1CON = 0x0030;               // Configure Timer1 (timer off, continue in IDLE, not gated, 1:256 prescaler, internal clock)    
    return;
}

//---------------------------------------------------------------------------
// InitADC. ADC intial configuration
//---------------------------------------------------------------------------
void InitADC()
{   
    // ADCON1 CONFIGURATION
    ADCON1bits.ADON = 0;        // Initially, stopped.
    ADCON1bits.ADSIDL = 0;      // No IDLE
    ADCON1bits.FORM = 0b00;     // Output format = unsigned integer
    ADCON1bits.SSRC = 0b010;    // Source for triggering conversion = auto (111) con 010 disparo con TMR3
    ADCON1bits.ASAM = 1;        // Sampling after conversion ends

    // ADCON2 CONFIGURATION
    ADCON2bits.VCFG = 0b000;    // Vref+ = VDD, Vref- = VSS.
    ADCON2bits.SMPI = 0b1110;   // Interrupts after 12 conversion
    ADCON2bits.BUFM = 0;        // 16 words
    ADCON2bits.CSCNA = 1;
    ADCON2bits.ALTS = 0;
    ADCON2bits.BUFS = 0;
           
    // ADCON3 CONFIGURATION
    ADCON3bits.SAMC = 0b01111;   // 15·Tad 
    ADCON3bits.ADCS = 4;        // Clock Tad
    ADCON3bits.ADRC = 0;        // internal clock
    
    // ADCPCFG
    ADPCFG = 0xFFFF;	
    ADPCFGbits.PCFG8 = 0;       // AN as analog input
    
    // ADCSSL
    ADCSSL = 0x0000;
    ADCSSLbits.CSSL8 = 1;       //  habilitar AN8 conversion

    ADCON1bits.ADON = 1;        // turn ADC ON
    return;
}

//---------------------------------------------------------------------------
// ConfigInt(). For configuring interrupts
//---------------------------------------------------------------------------
void ConfigInt()
{
    // Configuring the interrupts
    INTCON1bits.NSTDIS = 1;         // Disable nesting interrputs 
    
    IFS0bits.T1IF = 0;              // Clear ADC flag de TMR1
    IEC0bits.T1IE = 1;              // Enable ADC mask de TMR1
    IPC0bits.T1IP = 4;              // ADC priority level de TMR1
    
    IFS0bits.ADIF = 0;              // Clear ADC flag 
    IEC0bits.ADIE = 1;              // Enable ADC mask 
    IPC2bits.ADIP = 5;              // ADC priority level 
    
    SET_CPU_IPL(3);                 // Set CPU priority level to a value below the lowest interrupt
    return;   
}

//------------------Funciones LCD--------------------//
void MostrarNombre(void)
{   
    unsigned int tamanio=40; 
    char nombre[tamanio];
    char valor[tamanio];
    
    sprintf(nombre,"Evelyn Yanchaliquin Gomez. \n");
    sprintf(valor,"Valor %.2f",4.25);
    
    unsigned char TxIndex=0; 
//nombre
    while (nombre[TxIndex])
    {
        LCD_Display_Byte(WRITE_CHAR);
        LCD_Display_Byte(nombre[TxIndex++]);
    }
    //valor 
    TxIndex=0; 
    while (valor[TxIndex])
    {
        LCD_Display_Byte(WRITE_CHAR);
        LCD_Display_Byte(valor[TxIndex++]);
    }
}


void PrintTemperatura(float t){
    unsigned int tamanio=40; 
    char temp[tamanio];
    
    sprintf(temp,"La temperatura es de %.2f \223C ",t);
    
    unsigned char TxIndex=0; 
    //Temperatura leida
    while (temp[TxIndex])
    {
        LCD_Display_Byte(WRITE_CHAR);
        LCD_Display_Byte(temp[TxIndex++]);
    }

}

void PrintPotencia(float pot){
    unsigned int tamanio=50; 
    char potencia[tamanio];
    
    sprintf(potencia,"Valor del potenciometro es %.2f V ",pot);
    
    unsigned char TxIndex=0; 
    //Temperatura leida
    while (potencia[TxIndex])
    {
        LCD_Display_Byte(WRITE_CHAR);
        LCD_Display_Byte(potencia[TxIndex++]);
    }

}