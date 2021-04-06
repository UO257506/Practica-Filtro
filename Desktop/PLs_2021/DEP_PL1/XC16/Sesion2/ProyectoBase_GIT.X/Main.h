/* 
 * File:   Main.h
 * Author: 
 */

/* Este es el archivo de cabecera principal.
 * En �l se incluyen todas las librer�as que son necesarias, tanto las del 
 * lenguaje C como las de manejo de perif�ricos (si se usan).
 * Tambi�n puede emplearse este archivo para declarar constante mediante
 * directivas #DEFINE.
 */

#ifndef MAIN_H
#define	MAIN_H

// -----------------------------------------------------------------------------
// INCLUDE
// -----------------------------------------------------------------------------
// En esta parte se definen las librer�as t�picas de C. 
// Pueden incluirse m�s si fuera necesario.
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <float.h>
#include <math.h>

/* A continuaci�n se incluyen las librer�as de perif�ricos.
 * Para usarlas, antes debe INSTALARSE la librer�a PLIB.
 * Adem�s de incluirlas aqu�, deben incluirse MANUALMENTE en el header files del
 * proyecto (click derecho sobre Header Files -> Add Existing Item).
 * Su ubicaci�n t�pica es:
 * C:\Program Files\Microchip\xc16\v1.50\support\peripheral_30F_24H_33F
 */
// Ejemplo:
#include <timer.h>

// Constantes para la definici�n de la frecuencia del oscilador principal
#define FCY 7370000                 //7.37MHz oscillator with 4xPLL -> 7.37MIPs
#define FOSC (7370000)
#include <libpic30.h>


/* Estas directivas #if se usan para incluir la librer�a del dispositivo.
 * En funci�n de la configuraci�n del proyecto, cambia autom�ticamente del
 * dspic30F6014 al dspic30F6014A.
 * Adem�s de esto, debe incluirse MANUALMENTE la librear�a .h en el proyecto.
 * Su ubicaci�n por defecto es:
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



