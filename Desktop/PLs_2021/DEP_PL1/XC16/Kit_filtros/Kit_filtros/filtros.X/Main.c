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
 * T�pica de programaci�n para usar durante la asignatura. L�ease con atenci�n
 * las recomendaciones y las instrucciones de uso.
 */

// SIEMPRE SE INCLUIR�N ESTOS ARCHIVOS DE CABECERA:
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

// Llamada a la subrutina de interrupci�n. Descomentar estas l�neas para activarla.
// Debe incluirse el nombre de la rutina de interrupci�n (vector de interrupci�n).
// Esta llamada a la funci�n de interrupci�n debe repetirse tantas veces como
// vectores de interrupci�n haya (cada una, con su vector correspondiente)

//void __attribute__((interrupt, auto_psv)) /*NOMBRE VECTOR INTERRUPCI�N*/(void)
//{
    
//}


//---------------------------------------------------------------------------
// Main routine
//---------------------------------------------------------------------------

// Funci�n principal. Siempre incluye un bucle infinito.

int main (void)
{   
    // Aqu� se declarar�an las variables LOCALES a la funci�n Main.
    InitIO();
    
    generaonda();			// Se�al generada como suma de tres senoides
	filtrar();				// Funci�n para filtrar
    
    while (1)   // bucle infinito
    {
        
    }
    
    return 0;
    
}// Main
