/* 
 * File:   Main.h
 * Author: 
 */

/* Este es el archivo de cabecera principal.
 * En él se incluyen todas las librerías que son necesarias, tanto las del 
 * lenguaje C como las de manejo de periféricos (si se usan).
 * También puede emplearse este archivo para declarar constante mediante
 * directivas #DEFINE.
 */

#ifndef MAIN_H
#define	MAIN_H

// -----------------------------------------------------------------------------
// INCLUDE
// -----------------------------------------------------------------------------
// En esta parte se definen las librerías típicas de C. 
// Pueden incluirse más si fuera necesario.
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <float.h>
#include <math.h>

/* A continuación se incluyen las librerías de periféricos.
 * Para usarlas, antes debe INSTALARSE la librería PLIB.
 * Además de incluirlas aquí, deben incluirse MANUALMENTE en el header files del
 * proyecto (click derecho sobre Header Files -> Add Existing Item).
 * Su ubicación típica es:
 * C:\Program Files\Microchip\xc16\v1.50\support\peripheral_30F_24H_33F
 */
// Ejemplo:
#include <timer.h>

// Constantes para la definición de la frecuencia del oscilador principal
#define FCY 7370000                 //7.37MHz oscillator with 4xPLL -> 7.37MIPs
#define FOSC (7370000)
#include <libpic30.h>


/* Estas directivas #if se usan para incluir la librería del dispositivo.
 * En función de la configuración del proyecto, cambia automáticamente del
 * dspic30F6014 al dspic30F6014A.
 * Además de esto, debe incluirse MANUALMENTE la librearía .h en el proyecto.
 * Su ubicación por defecto es:
 * C:\Program Files\Microchip\xc16\v1.50\support\dsPIC30F\h
 */
#if defined(__dsPIC30F6014__)
   #include <p30F6014.h>
    
#endif

#if defined(__dsPIC30F6014A__) 
    #include <p30F6014A.h>
    
#endif    
// -----------------------------------------------------------------------------
// DEFINITIONS
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */



