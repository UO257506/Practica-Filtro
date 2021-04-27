;.....
;    File   pasoaltos1.s 
;.....

    .equ pasoaltos1NumTaps, 61

;.....
; Allocate and initialize filter taps

		.section .pasoaltos1const, "x"
		.align 128
pasoaltos1Taps:
.hword 0xffe4, 0xffe6, 0xffec, 0xfffa, 0x000f, 0x002a, 0x0045, 0x0059, 0x0059 
.hword 0x003d, 0x0000, 0xffa8, 0xff45, 0xfef2, 0xfecf, 0xfef6, 0xff78, 0x0050 
.hword 0x015d, 0x0267, 0x0324, 0x0346, 0x028a, 0x00ce, 0xfe16, 0xfa97, 0xf6b1 
.hword 0xf2e1, 0xefac, 0xed89, 0x6ce4, 0xed89, 0xefac, 0xf2e1, 0xf6b1, 0xfa97 
.hword 0xfe16, 0x00ce, 0x028a, 0x0346, 0x0324, 0x0267, 0x015d, 0x0050, 0xff78 
.hword 0xfef6, 0xfecf, 0xfef2, 0xff45, 0xffa8, 0x0000, 0x003d, 0x0059, 0x0059 
.hword 0x0045, 0x002a, 0x000f, 0xfffa, 0xffec, 0xffe6, 0xffe4 

;.....
; Allocate delay line in (uninitialized) Y data space

		.section .ybss,  "b"
		.align 128

pasoaltos1Delay:
		.space pasoaltos1NumTaps*2

; .....
; Allocate and intialize filter structure

		.section .data
		.global _pasoaltos1Filter

_pasoaltos1Filter:
.hword pasoaltos1NumTaps
.hword psvoffset(pasoaltos1Taps)
.hword psvoffset(pasoaltos1Taps)+pasoaltos1NumTaps*2-1
.hword psvpage(pasoaltos1Taps)
.hword pasoaltos1Delay
.hword pasoaltos1Delay+pasoaltos1NumTaps*2-1
.hword pasoaltos1Delay

; ....................................
; ....................................
