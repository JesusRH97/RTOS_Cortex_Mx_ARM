#include <stdint.h>
#include "led.h"

void LED_initAll(void)
{
	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	uint32_t *pGpiodModeReg = (uint32_t*)0x40020C00;


	*pRccAhb1enr |= ( 1 << 3);
	/* Configure LED_GREEN */
	*pGpiodModeReg |= ( 1 << (2 * LED_GREEN));
	*pGpiodModeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpiodModeReg |= ( 1 << (2 * LED_RED));
	*pGpiodModeReg |= ( 1 << (2 * LED_BLUE));

#if 0
	/* Configure the output type */
	*pGpioOpTypeReg |= ( 1 << (2 * LED_GREEN));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_RED));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_BLUE));
#endif

	LED_setOff(LED_GREEN);
	LED_setOff(LED_ORANGE);
	LED_setOff(LED_RED);
	LED_setOff(LED_BLUE);
}

void LED_setOn(uint8_t ledNo)
{
  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
  *pGpiodDataReg |= ( 1 << ledNo);
}

void LED_setOff(uint8_t ledNo)
{
	  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
	  *pGpiodDataReg &= ~( 1 << ledNo);
}
