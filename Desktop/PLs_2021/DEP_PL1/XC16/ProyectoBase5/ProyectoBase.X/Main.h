/* 
 * File:   Main.h
 * Author: Local Hero
 *
 * Created on 15 de marzo de 2018, 10:57
 */


#ifndef MAIN_H
#define	MAIN_H

// -----------------------------------------------------------------------------
// INCLUDE
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <float.h>

#define FCY         7372800             // xtal = 7.3728Mhz; PLLx4
#define FOSC        7372800
#define TEMPO10M    288                     //For 10ms
#define MITAD       4096/2
#define M           3

#define LF 0x0A // Nueva línea 
#define CR 0x0D// Retorno de carro
#define NUL 0x00// Blanco
#define SPACE 0x20// Espacio
#define WRITE_CHAR 0xA8 // Comando escribe carácter
#define HOME_CLEAR 0x82 // Comando cursor inicio
#define CURSOR_ON 0x8C // Comando para activar el cursor


#include <libpic30.h>


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



