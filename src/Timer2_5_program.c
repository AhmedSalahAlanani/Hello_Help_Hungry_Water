/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer2_5_interface.h"
#include "Timer2_5_private.h"
#include "Timer2_5_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MTimer2_voidInit (void)
{
	#if (TIMER2_ENABLE == 1)
	
		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM2->CR1 = (0x0);		//DIR = 0
		#elif(TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM2->CR1 = (0x10);		//DIR = 1
		#endif
	
	TIM2->PSC =  TIM2_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer2_voidSetBusyWait(u16 Copy_u16Ticks)
{
	(TIM2->CR1) &= ~(0x2);			//UDIS = 0
	(TIM2->CR1) &= ~(0x80);			//ARPE = 0 ;
	(TIM2->ARR)  =  Copy_u16Ticks;	
	(TIM2->CR1) |=  (0x1);			//CEN = 1
	
	while(!((TIM2->SR)&(0x1))); 	//POLL UIF
	
	(TIM2->SR)  &= ~(0x1);			//UIF = 0
	(TIM2->ARR)  = 0;	
	(TIM2->CR1) &= ~(0x1);			//CEN = 0
}
//***************************************************************************************************************
void MTimer3_voidInit (void)
{
	#if (TIMER3_ENABLE == 1)
	
		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM3->CR1 = (0x0);		//DIR = 0
		#elif(TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM3->CR1 = (0x10);		//DIR = 1
		#endif
	
	TIM3->PSC =  TIM3_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	(TIM3->CR1) &= ~(0x2);			//UDIS = 0
	(TIM3->CR1) &= ~(0x80);			//ARPE = 0 ;
	(TIM3->ARR)  =  Copy_u16Ticks;	
	(TIM3->CR1) |=  (0x1);			//CEN = 1
	
	while(!((TIM3->SR)&(0x1))); 	//POLL UIF
	
	(TIM3->SR)  &= ~(0x1);			//UIF = 0
	(TIM3->ARR)  = 0;	
	(TIM3->CR1) &= ~(0x1);			//CEN = 0
}
//***************************************************************************************************************
void MTimer4_voidInit (void)
{
	#if (TIMER4_ENABLE == 1)
	
		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM4->CR1 = (0x0);		//DIR = 0
		#elif(TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM4->CR1 = (0x10);		//DIR = 1
		#endif
	
	TIM4->PSC =  TIM4_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer4_voidSetBusyWait(u16 Copy_u16Ticks)
{
	(TIM4->CR1) &= ~(0x2);			//UDIS = 0
	(TIM4->CR1) &= ~(0x80);			//ARPE = 0 ;
	(TIM4->ARR)  =  Copy_u16Ticks;	
	(TIM4->CR1) |=  (0x1);			//CEN = 1
	
	while(!((TIM4->SR)&(0x1)));		//POLL UIF
	
	(TIM4->SR)  &= ~(0x1);			//UIF = 0
	(TIM4->ARR)  = 0;	
	(TIM4->CR1) &= ~(0x1);			//CEN = 0
}
//***************************************************************************************************************
void MTimer5_voidInit (void)
{
	#if (TIMER5_ENABLE == 1)
	
		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM5->CR1 = (0x0);		//DIR = 0
		#elif(TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM5->CR1 = (0x10);		//DIR = 1
		#endif
	
	TIM5->PSC =  TIM5_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer5_voidSetBusyWait(u16 Copy_u16Ticks)
{
	(TIM5->CR1) &= ~(0x2);			//UDIS = 0
	(TIM5->CR1) &= ~(0x80);			//ARPE = 0 ;
	(TIM5->ARR)  =  Copy_u16Ticks;	
	(TIM5->CR1) |=  (0x1);			//CEN = 1
	
	while(!((TIM5->SR)&(0x1))); 	//POLL UIF
	
	(TIM5->SR) &= ~(0x1);			//UIF = 0
	(TIM5->ARR) = 0;	
	(TIM5->CR1) &= ~(0x1);			//CEN = 0
}
//***************************************************************************************************************
