/*
 * Relay_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define RELAY_1    1
#define RELAY_2    2

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_RELAY_Void_RelayInit(u8);
void H_RELAY_Void_RelayOn(u8);
void H_RELAY_Void_RelayOff(u8);
void H_RELAY_Void_RelayBlink(u8);
void H_RELAY_Void_RelayTog(u8);

#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */
