

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Private includes ----------------------------------------------------------*/
#include "gpio.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

 /**
  * @brief Setting direction for GPIO Controller
  * @param[in] uiGPIOx specify the Port base address
  * @param[in] ucPinnum specify the Pin number
  * @param[in] ucDirection specify the Direction
  * @return None
  **/
void vGpioSetDir(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum,uint8_t ucDirection)
{
		if(ucDirection==OUTPUT)
			uiGPIOx->FIODIR |= 1<<ucPinnum;
		else if(ucDirection==INPUT)
			uiGPIOx->FIODIR &= ~(1<<ucPinnum);
}

/**
 * @brief Setting Pin as HIGH for GPIO Controller
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the Pin number
 * @return None
 **/
void vGpioSetPin(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum)
{
		uiGPIOx->FIOSET = 1<<ucPinnum;
}

/**
 * @brief Setting Pin as LOW for GPIO Controller
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the Pin number
 * @return None
 **/
void vGpioClrPin(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum)
{
		uiGPIOx->FIOCLR = 1<<ucPinnum;
}

/**
 * @brief Setting Nibble starting from the specified Pin number
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the starting Pin number
 * @return None
 **/
void vGpioSetNibble(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum, uint8_t ucvalue)
{
		uiGPIOx->FIOCLR = 0xF<<ucPinnum;
		uiGPIOx->FIOSET = ucvalue<<ucPinnum;

}

/**
 * @brief Setting Byte starting from the specified Pin number
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the starting Pin number
 * @return None
 **/
void vGpioSetByte(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum, uint8_t ucvalue)
{
		uiGPIOx->FIOCLR = 0xFF<<ucPinnum;
		uiGPIOx->FIOSET = ucvalue<<ucPinnum;

}
















