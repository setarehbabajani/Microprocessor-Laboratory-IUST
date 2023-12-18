;Setareh Babajani
;student id: 99521109

.include "m32def.inc"
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16
		LDI		R16,0xFF
		OUT		DDRC,R16		
		OUT		DDRD,R16	
		OUT		PORTA,R16		
		LDI		R16,0x00
		OUT		DDRA,R16		
		LDI		R24,0
		LDI		R25,0
		LDI		R27,1

BEGIN:	IN		R16,PINA
	    CALL	DELAY2
		CPI		R27,0
		BRNE	B1
		CALL 	CHSE			

B1:		LDI		R20,0
		LDI		R21,0
		LDI		R22,0
		LDI		R23,0
		MOV  	R26,R24

D0:		CPI		R26,10
		BRLO	D1
		LDI		R18,10
		SUB		R26,R18
		INC		R22				
		RJMP	D0

D1:		MOV		R23,R26				
		MOV	    R26,R25

D2:		CPI		R26,10
		BRLO	D3
		LDI		R18,10
		SUB		R26,R18
		INC		R20				
		RJMP	D2

D3:		MOV		R21,R26		
		LDI		R16,0b11111110	
		OUT		PORTD,R16
		MOV		R16,R20
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		LDI		R16,0b11111101	
		OUT		PORTD,R16
		MOV		R16,R21
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		LDI		R16,0b11111011	
		OUT		PORTD,R16
		MOV		R16,R22
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		LDI		R16,0b11110111	
		OUT		PORTD,R16
		MOV		R16,R23
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		RJMP	BEGIN

CHSE:	LDI		R17,0x01
		AND 	R17,R16
		CPI		R17,0
		BREQ	CH1			
		RJMP	CH2			

CH1:	CALL	INCR
        RJMP	CH3

CH2:	CALL	DECR

CH3:	RET
		
INCR:	INC		R24
        CPI		R24,100
		BRLO	I1
		LDI		R24,0
		INC		R25
		CPI		R25,100
		BRLO	I1
		LDI		R25,0

I1:		RET

DECR:	CPI		R24,0
        BREQ	DE1		
		DEC		R24	
		RJMP	DE3

DE1:	LDI		R24,99
		CPI		R25,0
        BREQ	DE2
		DEC		R25
		RJMP	DE3

DE2:	LDI		R25,99

DE3:	RET

DELAY2:	CPI		R27,10
		BREQ	L2_1
		INC		R27
		RJMP	L2_2

L2_1:	LDI		R27,0

L2_2:	RET

DELAY:	LDI		R17,0x01

L1:		LDI		R18,0x15

L2:		LDI		R19,0xFF

L3:		DEC		R19
		BRNE	L3
		DEC		R18
		BRNE	L2
		DEC		R17
		BRNE	L1
		RET

CONVERT:				
		CPI		R16,0
		BRNE	C1
		LDI		R16,0x3F
		RET

C1:		CPI		R16,1
		BRNE	C2
		LDI		R16,0x06
		RET

C2:		CPI		R16,2
		BRNE	C3
		LDI		R16,0x5B
		RET

C3:		CPI		R16,3
		BRNE	C4
		LDI		R16,0x4F
		RET

C4:		CPI		R16,4
		BRNE	C5
		LDI		R16,0x66
		RET

C5:		CPI		R16,5
		BRNE	C6
		LDI		R16,0x6D
		RET

C6:		CPI		R16,6
		BRNE	C7
		LDI		R16,0x7D
		RET

C7:		CPI		R16,7
		BRNE	C8
		LDI		R16,0x07
		RET

C8:		CPI		R16,8
		BRNE	C9
		LDI		R16,0x7F
		RET

C9:		CPI		R16,9
		BRNE	C10
		LDI		R16,0x6F

C10:	RET
