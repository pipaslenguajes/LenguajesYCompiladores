include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.CODE 
MAIN:


	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

ETIQ_0: 
	 FLD (null) 	;Cargo operando 1
	 FLD (null) 	;Cargo operando 2
	 FDIV 		;Opero
	 FSTP (null) 	;Almaceno el resultado en una var auxiliar
	 FLD (null) 	;Cargo valor 
	 FSTP (null) 	; Se lo asigno a la variable que va a guardar el resultado 
