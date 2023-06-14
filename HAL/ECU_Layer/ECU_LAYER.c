#include "ECU_LAYER.h"
void H_LED_Void_LedAndRlayBlink(void){
		M_DIO_Void_SetPinValue(RELAY_1_PIN,HIGH);
		M_DIO_Void_SetPinValue(LED_GRN_PIN,HIGH);
		_delay_ms(LED_BLINKING_TIME);
		M_DIO_Void_SetPinValue(LED_GRN_PIN,LOW);
		M_DIO_Void_SetPinValue(RELAY_1_PIN,LOW);
		_delay_ms(LED_BLINKING_TIME);
}

void H_LED_Void_LedAndRlayoff(void){
	H_LED_Void_LedOff(LED_GRN);
	H_RELAY_Void_RelayOff(RELAY_1);
}
