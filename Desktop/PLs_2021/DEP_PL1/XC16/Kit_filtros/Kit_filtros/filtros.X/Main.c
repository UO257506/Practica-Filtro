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

#include "dsp.h"
#include "math.h"

//---------------------------------------------------------------------------
// Global variables
//---------------------------------------------------------------------------
// En este espacio pueden declararse las variables globales o las constantes.
// Ejemplo:
// unsigned int MiValor = 0;


//---------------------------------------------------------------------------
// ISR routine
//---------------------------------------------------------------------------

// Llamada a la subrutina de interrupción. Descomentar estas líneas para activarla.
// Debe incluirse el nombre de la rutina de interrupción (vector de interrupción).
// Esta llamada a la función de interrupción debe repetirse tantas veces como
// vectores de interrupción haya (cada una, con su vector correspondiente)

//void __attribute__((interrupt, auto_psv)) /*NOMBRE VECTOR INTERRUPCIÓN*/(void)
//{
    
//}


//---------------------------------------------------------------------------
// Main routine
//---------------------------------------------------------------------------

// Función principal. Siempre incluye un bucle infinito.

int main (void)
{   
    // Aquí se declararían las variables LOCALES a la función Main.
    InitIO();
    
    generaonda();			// Señal generada como suma de tres senoides
	filtrar();				// Función para filtrar
    
    while (1)   // bucle infinito
    {
        
    }
    
    return 0;
    
}// Main
