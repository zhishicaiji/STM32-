#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"

uint8_t KeyNum;
int8_t Speed;

int main(void){
	OLED_Init();
	Motor_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Speed:");		//1行1列显示字符串Speed:


	while(1){
		KeyNum = Key_GetNum();
		if (KeyNum == 1)					//按键1按下
		{
			Speed += 20;					//速度变量自增20
			if (Speed > 100)				//速度变量超过100后
			{
				Speed = -100;				//速度变量变为-100
											//此操作会让电机旋转方向突然改变，可能会因供电不足而导致单片机复位
											//若出现了此现象，则应避免使用这样的操作
			}
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1, 7, Speed, 3);
	}
}
