;ORG	$1000
	
GetKbdML15:	
	JSR	CheckKbdML15
	CMPB	#$FF
	BEQ 	GetKbdML15
	RTS
	
CheckKbdML15:
	LDAB	$9C0
	BITB	#$80
	BEQ	ReadKbd
	LDAB	#$FF
	JMP 	Retur
	
	
ReadKbd:
	PSHB
	JMP Read_Loop
	
Read_Loop:
	LDAB	$9C0
	BITB	#$80
	BEQ	Read_Loop
	PULB
	JMP	Retur
	
	
	
Retur:
	RTS
	

CheckKbd_First:
	LDAB	$9C0
	BITB	#$80
	BEQ	Retur
	LDAB 	#$FF
	JMP	Retur
	