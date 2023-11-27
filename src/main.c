#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void RCC_Config(void)
{
	// 8Mhz -> 168Mhz
	RCC->CR &= ~(1 << 0);
	RCC->CR |= 1 << 16;
	while(!(RCC->CR & (1 << 17)));
	RCC->CR |= 1<<19;
	RCC->PLLCFGR = 0x00000000;
	RCC->PLLCFGR |= (1 << 22);
	RCC->PLLCFGR |= (4<<0);
	RCC->PLLCFGR |= (168<<6);
	RCC->PLLCFGR &= ~(1 << 16);
	RCC->PLLCFGR &= ~(1 << 17);
	RCC->CR |= (1 << 24);
	while(!(RCC->CR & (1 << 25)));
	RCC->CFGR &= ~(1 << 0);
	RCC->CFGR |= (1 << 1);
	while(!(RCC->CFGR & (1 << 1)));
}
void GPIO_Config(void)
{
	RCC->AHB1ENR |= 1 << 3; 				//-> We enabled the clock line of GPIOD.

	//Pin of 12 became output.
	GPIOD->MODER |= 1 << 24;
	GPIOD->MODER &= ~(1 << 25);

	//Pin of 13 became output.
	GPIOD->MODER |= 1 << 26;
	GPIOD->MODER &= ~(1 << 27);

	//Pin of 14 became output.
	GPIOD->MODER |= 1 << 28;
	GPIOD->MODER &= ~(1 << 29);

	//Pin of 15 became output.
	GPIOD->MODER |= 1 << 30;
	GPIOD->MODER &= ~(1 << 31);

	//->Anyway, we didn't do anything because the default settings are push-pull.

	GPIOD->OSPEEDR |= 0xff000000; 			//-> All pins became very speed.
	//GPIOD->OSPEEDR |= 0xff << 24; 		//-> Any way of another.

	//->Anyway, we didn't do anything because the default settings are pull-up/pull-down.
}
int main(void)
{
	//Settings of Clock
	RCC_Config();
	SystemCoreClockUpdate();

	//Settings of GPIO
	GPIO_Config();

	while (1)
	{
		GPIOD->ODR |= 1 << 12; 			//-> Pin of 12 became set.
		GPIOD->ODR |= 1 << 13; 			//-> Pin of 13 became set.
		GPIOD->ODR |= 1 << 14; 			//-> Pin of 14 became set.
		GPIOD->ODR |= 1 << 15; 			//-> Pin of 15 became set.
		for(int i=0; i<1680000; i++); 	//-> Program waits.

		GPIOD->ODR &= ~(1 << 12); 		//-> Pin of 12 became reset.
		GPIOD->ODR |= 1 << 13; 			//-> Pin of 13 became set.
		GPIOD->ODR |= 1 << 14; 			//-> Pin of 14 became set.
		GPIOD->ODR |= 1 << 15;			//-> Pin of 15 became set.
		for(int i=0; i<1680000; i++); 	//-> Program waits.
	}
}







void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
