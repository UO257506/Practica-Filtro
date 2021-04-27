;.....
;    File   pasobanda.s 
;.....

    .equ pasobandaNumTaps, 41

;.....
; Allocate and initialize filter taps

		.section .pasobandaconst, "x"
		.align 128
pasobandaTaps:
.hword 0xfe77, 0xfd66, 0xfc67, 0xfb8b, 0xfadf, 0xfa6f, 0xfa42, 0xfa5f, 0xfac7 
.hword 0xfb75, 0xfc64, 0xfd87, 0xfed2, 0x0033, 0x0198, 0x02ef, 0x0424, 0x0528 
.hword 0x05ed, 0x0667, 0x0691, 0x0667, 0x05ed, 0x0528, 0x0424, 0x02ef, 0x0198 
.hword 0x0033, 0xfed2, 0xfd87, 0xfc64, 0xfb75, 0xfac7, 0xfa5f, 0xfa42, 0xfa6f 
.hword 0xfadf, 0xfb8b, 0xfc67, 0xfd66, 0xfe77 

;.....
; Allocate delay line in (uninitialized) Y data space

		.section .ybss,  "b"
		.align 128

pasobandaDelay:
		.space pasobandaNumTaps*2

; .....
; Allocate and intialize filter structure

		.section .data
		.global _pasobandaFilter

_pasobandaFilter:
.hword pasobandaNumTaps
.hword psvoffset(pasobandaTaps)
.hword psvoffset(pasobandaTaps)+pasobandaNumTaps*2-1
.hword psvpage(pasobandaTaps)
.hword pasobandaDelay
.hword pasobandaDelay+pasobandaNumTaps*2-1
.hword pasobandaDelay

; ....................................
; ....................................
