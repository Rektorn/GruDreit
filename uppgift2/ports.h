typedef unsigned char* port8ptr;
typedef unsigned int* port16ptr;

#define	ML4IN_ADDRESS	0x600
#define	ML4OUT_ADDRESS	0x400
#define	ML2IN_ADDRESS	0x9C0
#define DISPLAY_DATA_REG_ADDRESS 0x9C3
#define DISPLAY_DATA_MODE_ADRESS 0x9C2

#define CRGINT_ADDRESS	0x38
#define	RTICTL_ADDRESS	0x3B
#define CRGFLG_ADDRESS	0x37

#define IRQ_VEC_ADRESS	0x3FF0

#define	ML4IN	*((port8ptr)	ML4IN_ADDRESS)
#define	ML4OUT	*((port8ptr)	ML4OUT_ADDRESS)
#define ML2IN	*((port8ptr)	ML2IN_ADDRESS)
#define DISPLAY_DATA_REG *((port8ptr) DISPLAY_DATA_REG_ADDRESS)
#define DISPLAY_DATA_MODE *((port8ptr) DISPLAY_DATA_MODE_ADRESS)
#define	CRGINT	*((port8ptr)	CRGINT_ADDRESS)
#define	RTICTL	*((port8ptr)	RTICTL_ADDRESS)
#define	CRGFLG	*((port8ptr)	CRGFLG_ADDRESS)
#define IRQ_VEC *((port16ptr)	IRQ_VEC_ADDRESS)
