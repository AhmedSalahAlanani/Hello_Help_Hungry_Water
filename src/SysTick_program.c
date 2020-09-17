/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MSysTick_voidInit (void)
{
	#if (SYSTICK_CLOCKSOURCE == SYSTICK_CLOCKSOURCE_AHB)
		SysTick->CTRL = 4;
	#elif (SYSTICK_CLOCKSOURCE==SYSTICK_CLOCKSOURCE_AHB_DIV8)
		SysTick->CTRL = 0;
	#endif
}
//***************************************************************************************************************
void MSysTick_voidSetBusyWait (u32 Copy_u32Ticks)
{
	Systick_Timer_State = SYSTICK_TIMER_STATE_BUSY;

	SysTick->VAL   = 0;	
	SysTick->LOAD  = ((Copy_u32Ticks)&(0xFFFFFF));
	SysTick->CTRL  = 1;

	while(!((SysTick->CTRL)&(0x10000)));

	SysTick->CTRL  = 0;

	Systick_Timer_State = SYSTICK_TIMER_STATE_FREE;
}
//***************************************************************************************************************
void MSysTick_voidSetIntervalSingle   (u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	MSysTick_voidSetIntervalPeriodic (Copy_u32Ticks,Copy_ptr);
	Callback_Mode	 =  SYSTICK_CALLBACK_MODE_SINGLE;
}
//***************************************************************************************************************
void MSysTick_voidSetIntervalPeriodic (u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	Systick_Timer_State = SYSTICK_TIMER_STATE_BUSY;

	SysTick_Callback = Copy_ptr;
	Callback_Mode	 =  SYSTICK_CALLBACK_MODE_PERIODIC;

	SysTick->CTRL  =   0;
	SysTick->VAL   =   0;
	SysTick->LOAD  = ((Copy_u32Ticks)&(0xFFFFFF));
	SysTick->CTRL  =   3;
}
//***************************************************************************************************************
void MSysTick_voidStopInterval (void)
{
	SysTick->CTRL  = 0;
	SysTick->LOAD  = 0;
	SysTick->VAL   = 0;	

	Systick_Timer_State = SYSTICK_TIMER_STATE_FREE;
}
//***************************************************************************************************************
u32  MSysTick_u32GetElapsedTime  (void)
{
	return((SysTick->LOAD)-(SysTick->VAL));
}
//***************************************************************************************************************
u32  MSysTick_u32GetRemainingTime(void)
{
	return(	SysTick->VAL);
}
//***************************************************************************************************************
u8 MSysTick_u8GetSystickState (void)
{
	return Systick_Timer_State;
}
//***************************************************************************************************************
void MSysTick_voidSetSystickStateBusy (void)
{
	Systick_Timer_State = SYSTICK_TIMER_STATE_BUSY;
}
//***************************************************************************************************************
void MSysTick_voidSetSystickStateFree (void)
{
	Systick_Timer_State = SYSTICK_TIMER_STATE_FREE;
}
//***************************************************************************************************************
void SysTick_Handler (void)
{
	volatile __attribute__((unused))  u8  dummy = SysTick->CTRL;

	if(	Callback_Mode == SYSTICK_CALLBACK_MODE_SINGLE)
	{
		MSysTick_voidStopInterval ();
	}
	
	if(SysTick_Callback != 0)
	{
		SysTick_Callback();
	}
}
//***************************************************************************************************************
