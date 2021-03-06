#include "ports.h"
#include "clock.h"
#include "displayml5.h"


extern void clock_reset(void);
extern void IRQ(void);

static time_type clockCounter;

void init_clock(void)
{
		//*((vector) IRQ_VEC_ADDRESS) testPtr = IRQ;
		clockCounter = 0;
		IRQ_VEC = IRQ;
		
		// // // // //
		#ifdef SIMULATOR
		RTICTL = 0x10; 	//ställer in tid för delay
		#else
		RTICTL = 0x49;
		#endif
		
		CRGINT |= 0x80; //etställer crgints sjunde bit
		// // // // //
		clock_reset();
}

void clock_inter(void)
{
	clockCounter++;
	#ifdef DISPLAY_ACTIVE
	display_dec(((unsigned int)clockCounter));
	#endif
	CRGFLG |= 0x80; //ackar, skriver etta till sjunde biten
}

time_type get_time(void)
{
	return clockCounter * 10;
}

void hold(time_type delay_time)
{
	time_type start_time = get_time();
	#ifdef SIMULATOR
	//simulator temp lösning
	while(get_time() == start_time);
	#else
	while(get_time() - start_time < delay_time);
	#endif
}
