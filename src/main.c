/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Ahmed Salah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "IR_NEC_interface.h"
#include "DAC_interface.h"
#include "LEDMRX_interface.h"

#include "Audio_Hello.h"
#include "Audio_Help.h"
#include "Audio_Hungry.h"
#include "Audio_Water.h"


#define AUDIOFILES_SAMPLE_RATE		(8000UL)
#define ANIMATION_DELAY				(5)


int main (void)
{
	const u8 Hello_text[] = {	0,   0,  0,   0, 0,   0,  0,   0,
								0, 124, 16, 124, 0, 120, 88, 88, 0,
								124, 64, 0, 124, 64, 0, 48, 72, 72, 48,
								0, 0, 0, 0, 0, 0, 0,	0, 0				};

	const u8 Help_text[] = {	  0,   0,  0,   0, 0,   0,  0,   0,
								  0, 124, 16, 124, 0, 120, 88, 88, 0,
								124, 64, 0, 120, 24, 24,
								  0, 0, 0, 0, 0, 0,	0, 0 , 0			 };

	const u8 Hungry_text[] = {	  0,   0,  0,   0, 0,   0,  0,   0,
								  0, 124, 16, 124, 0, 120, 64, 120,
								  0, 120, 16, 112, 0, 88, 120, 0, 120,
								  16, 8, 0, 88, 80, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0	 };

	const u8 Water_text[] = {	  0,   0,  0,   0, 0,  0,  0,   0,
								  0, 60, 64, 112, 64, 60, 0, 48, 72,
								 72, 112, 64, 8, 124, 72, 0, 120, 88, 88, 0,
								120, 16, 8,0, 0, 0, 0, 0, 0, 0, 0, 0						 };

	MRCC_voidInitSysClock ();
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPAEN);
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPBEN);
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_AFIOEN);
	MRCC_voidEnableClock  (RCC_APB1,RCC_APB1_TIM2EN);


	HIR_NEC_voidInit();
	HDAC_voidInit ();
	HLEDMRX_voidInit();


	while(1)
	{
		switch( HIR_NEC_u8ReadReceivedFrame() )
		{
			case IR_NEC_NO_BUTTON_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_1_PRESSED:
				HDAC_voidPlay_Audiofile (Hello_raw, AUDIO_HELLO_LEN, AUDIOFILES_SAMPLE_RATE);
				HLEDMRX_voidDisplayAnimation(Hello_text, sizeof(Hello_text)/sizeof(u8), ANIMATION_DELAY);
				break;

			case IR_NEC_BUTTON_2_PRESSED:
				HDAC_voidPlay_Audiofile (Help_raw,   AUDIO_HELP_LEN, AUDIOFILES_SAMPLE_RATE);
				HLEDMRX_voidDisplayAnimation(Help_text, sizeof(Help_text)/sizeof(u8), ANIMATION_DELAY);
				break;

			case IR_NEC_BUTTON_3_PRESSED:
				HDAC_voidPlay_Audiofile (Hungry_raw, AUDIO_HUNGRY_LEN, AUDIOFILES_SAMPLE_RATE);
				HLEDMRX_voidDisplayAnimation(Hungry_text, sizeof(Hungry_text)/sizeof(u8), ANIMATION_DELAY);
				break;

			case IR_NEC_BUTTON_4_PRESSED:
				HDAC_voidPlay_Audiofile (Water_raw, AUDIO_WATER_LEN, AUDIOFILES_SAMPLE_RATE);
				HLEDMRX_voidDisplayAnimation(Water_text, sizeof(Water_text)/sizeof(u8), ANIMATION_DELAY);
				break;
		}
	}
}

