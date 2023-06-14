/*
 * Relay_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */



/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "Relay_Config.h"
#include "Relay_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayInit(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	case RELAY_1: M_DIO_Void_SetPinDirection(RELAY_1_PIN,OUTPUT); break;
	case RELAY_2: M_DIO_Void_SetPinDirection(RELAY_2_PIN,OUTPUT); break;

	default:                                                      break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayOn(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	case RELAY_1: M_DIO_Void_SetPinValue(RELAY_1_PIN,HIGH); break;
	case RELAY_2: M_DIO_Void_SetPinValue(RELAY_2_PIN,HIGH); break;

	default:                                                break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayOff(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	case RELAY_1: M_DIO_Void_SetPinValue(RELAY_1_PIN,LOW); break;
	case RELAY_2: M_DIO_Void_SetPinValue(RELAY_2_PIN,LOW); break;
	default:                                               break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayBlink(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	case RELAY_1:
		M_DIO_Void_SetPinValue(RELAY_1_PIN,HIGH);
		_delay_ms(RELAY_BLINKING_TIME);
		M_DIO_Void_SetPinValue(RELAY_1_PIN,LOW);
		_delay_ms(RELAY_BLINKING_TIME);
		break;
	case RELAY_2:
		M_DIO_Void_SetPinValue(RELAY_2_PIN,HIGH);
		_delay_ms(RELAY_BLINKING_TIME);
		M_DIO_Void_SetPinValue(RELAY_2_PIN,LOW);
		_delay_ms(RELAY_BLINKING_TIME);
		break;

	default:   break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayTog(u8 Copy_U8_Relay)
{
	switch(Copy_U8_Relay)
	{
	case RELAY_1: M_DIO_Void_TogPin(RELAY_1_PIN); break;
	case RELAY_2: M_DIO_Void_TogPin(RELAY_2_PIN); break;

	default:                                      break;
	}
}
