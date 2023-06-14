#include "Quiz_interface.h"
#include "ccs.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is the database for Correct Answers to Questions */
u8 volatile Questions[MAX_QUESTIONS] = { ANS_A, ANS_B, ANS_C, ANS_D, ANS_A };
u8 volatile Question_num = 0; //max is 5

static volatile u8 seconds = 0, minutes = 0, hours = 0;

void Timer_ISR(void) {
	seconds++;

	if (seconds == 60) {
		seconds = 0;
		minutes++;
	}
	if (minutes == 60) {
		minutes = 0;
		hours++;
	}
	if (hours == 24) {
		hours = 0;
	}
}

void Display_Timer(void) {

	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_H + 2);
	H_Lcd_Void_LCDWriteCharacter(':');
	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_M + 2);
	H_Lcd_Void_LCDWriteCharacter(':');

	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_H);
	H_Lcd_Void_LCDWriteNumber(hours / 10);
	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_H + 1);
	H_Lcd_Void_LCDWriteNumber(hours % 10);

	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_M);
	H_Lcd_Void_LCDWriteNumber(minutes / 10);
	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_M + 1);
	H_Lcd_Void_LCDWriteNumber(minutes % 10);

	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_S);
	H_Lcd_Void_LCDWriteNumber(seconds / 10);
	H_Lcd_Void_LCDGoTo(0, 6 + TIMER_S + 1);
	H_Lcd_Void_LCDWriteNumber(seconds % 10);

}

void Display_General(void) {
	H_Lcd_Void_LCDGoTo(2, 1);
	H_Lcd_Void_LCDWriteString((u8*) "Q-");
	H_Lcd_Void_LCDGoTo(2, 3);
	H_Lcd_Void_LCDWriteNumber((Question_num + 1) / 10);
	H_Lcd_Void_LCDGoTo(2, 4);
	H_Lcd_Void_LCDWriteNumber((Question_num + 1) % 10);

	H_Lcd_Void_LCDGoTo(2, 11);
	H_Lcd_Void_LCDWriteString((u8*) "A B C D");

}
void Wrong_Answer(void) {
	minutes++;
	M_Timer_Void_TimerStop(TIMER0_CHANNEL);
	H_Buzzer_Void_BuzzerOnce();
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(1, 6);
	H_Lcd_Void_LCDWriteString((u8*) "WRONG!");
	H_Lcd_Void_LCDGoTo(3, 2);
	H_Lcd_Void_LCDWriteString((u8*) "PENALTY: +1 MIN");
	_delay_ms(2000);
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(0, 6);

}
void Game_Over(void) {
	Question_num=0;
	M_Timer_Void_TimerStop(TIMER0_CHANNEL);
	H_Buzzer_Void_BuzzerTwice();
	H_Lcd_Void_LCDClear();
	Display_Timer();
	H_Lcd_Void_LCDGoTo(2, 4);
	H_Lcd_Void_LCDWriteString((u8*) "GAME OVER!");

	_delay_ms(10000);
	H_Lcd_Void_LCDClear();
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);
}
void Correct_Answer(void) {
	Question_num++;
	H_Buzzer_Void_BuzzerOnce();
	M_Timer_Void_TimerStop(TIMER0_CHANNEL);
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(1, 6);
	H_Lcd_Void_LCDWriteString((u8*) "Correct!");
	_delay_ms(2000);
	H_Lcd_Void_LCDClear();
	if (Question_num == MAX_QUESTIONS)
		Game_Over();
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);

}

void Check_Button(void) {
	if (PUSH_BUTTON_PRESSED == (H_PushButton_U8_PushButtonReadOnce(BTN_A))) {
		(Questions[Question_num] == ANS_A) ? Correct_Answer() : Wrong_Answer();
	} else if (PUSH_BUTTON_PRESSED == (H_PushButton_U8_PushButtonReadOnce(BTN_B))) {
		(Questions[Question_num] == ANS_B) ? Correct_Answer() : Wrong_Answer();
	} else if (PUSH_BUTTON_PRESSED == (H_PushButton_U8_PushButtonReadOnce(BTN_C))) {
		(Questions[Question_num] == ANS_C) ? Correct_Answer() : Wrong_Answer();
	} else if (PUSH_BUTTON_PRESSED == (H_PushButton_U8_PushButtonReadOnce(BTN_D))) {
		(Questions[Question_num] == ANS_D) ? Correct_Answer() : Wrong_Answer();
	}
}
int main() {
	H_Buzzer_Void_BuzzerInit();
	H_Buzzer_Void_BuzzerTwice();

	H_PushButton_Void_PushButtonInit(BTN_A);
	H_PushButton_Void_PushButtonInit(BTN_B);
	H_PushButton_Void_PushButtonInit(BTN_C);
	H_PushButton_Void_PushButtonInit(BTN_D);

	H_Lcd_Void_LCDInit();
	//H_Lcd_Void_LCDGoTo(0, 6);
	//H_Lcd_Void_LCDWriteString((u8*) Timer_Digits);

	M_GIE_Void_GlobalInterruptEnable(); /*Do Not Forget to Enable I-Bit */
	M_Timer_Void_TimerInit();
	M_Timer_Void_SetCallBack(Timer_ISR);
	M_Timer_Void_TimerSetTime(1000); //interrupt every 1 second
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);

	while (1) {
		Display_Timer();
		Display_General();
		Check_Button();
	}
	return 0;
}

/*
 //	itoa( hours / 10   , Timer_Digits[TIMER_H2]   , 10);
 //	itoa( hours % 10   , Timer_Digits[TIMER_H1]   , 10);
 //	itoa( minutes / 10 , Timer_Digits[TIMER_M2]  , 10);
 //	itoa( minutes % 10 , Timer_Digits[TIMER_M1]  , 10);
 //	itoa( seconds / 10 , Timer_Digits[TIMER_S2]  , 10);
 //	itoa( seconds % 10 , Timer_Digits[TIMER_S1]  , 10);*/
