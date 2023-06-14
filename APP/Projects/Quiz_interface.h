/*
 * Quiz_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef APP_PROJECTS_QUIZ_INTERFACE_H_
#define APP_PROJECTS_QUIZ_INTERFACE_H_
/*============================================================================================*/
/*   INCLUDES   */
/*============================================================================================*/
#include "LED_Interface.h"
#include "LCD_Interface.h"
#include "PushButton_Interface.h"
#include "Timer_Interface.h"
#include "ADC_Interface.h"
#include "EEPROM_Interface.h"
#include "Keypad_Interface.h"
#include "Buzzer_Interface.h"
#include "GIE_Interface.h"
#include "WIFI_Interface.h"
#include "SSD_Interface.h"
#include "Relay_Interface.h"
//#include "ECU_Layer/ECU_LAYER.h"

/*============================================================================================*/
/*   Defines for BUTTONS A,B,C,D   */
/*============================================================================================*/
#define BTN_A PUSH_BUTTON_0
#define BTN_B PUSH_BUTTON_1
#define BTN_C PUSH_BUTTON_2
#define BTN_D PUSH_BUTTON_3

#define BTN_A_PIN PUSH_BUTTON_0_PIN
#define BTN_B_PIN PUSH_BUTTON_1_PIN
#define BTN_C_PIN PUSH_BUTTON_2_PIN
#define BTN_D_PIN PUSH_BUTTON_3_PIN
/*============================================================================================*/
/*   Defines for TIMER DIGITS HH:MM:SS   */
/*============================================================================================*/
#define TIMER_H 0
#define TIMER_M 3
#define TIMER_S 6
/*============================================================================================*/
/*   Defines for APP   */
/*============================================================================================*/
#define MAX_QUESTIONS 5

#define ANS_A BTN_A
#define ANS_B BTN_B
#define ANS_C BTN_C
#define ANS_D BTN_D



#endif /* APP_PROJECTS_QUIZ_INTERFACE_H_ */
