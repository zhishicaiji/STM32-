#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
#include "Timer.h"

int16_t Speed;
int main(void){
	OLED_Init();
	Encoder_Init();
	Timer_Init();
	OLED_ShowString(1, 1, "Speed:");

	while(1){
		
		OLED_ShowSignedNum(1, 7, Speed, 5);
		// OLED_ShowNum(2, 5, TIM_GetCounter(TIM2), 5);
	}
}
