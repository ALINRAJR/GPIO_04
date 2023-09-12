/*
===============================================================================

 Description : Displaying the numbers from 0 to 255 using GPIO Library


 Layered Architecture used for this project
 ************************************
 Application layer-04_Day24_17092021_GPIO004.c
 ************************************
 Board layer - Nothing
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

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
  * @brief  Crude Delay
  * @retval none
  */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}

/**
  * @brief Printing 8 bit number on GPIO
  * @param[in] num Number to display
  * @return None
  **/
void vAppPrintNum(uint8_t num)
{
	 vGpioSetByte(PORT1,PIN19,num);
}


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

   uint8_t num=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
	vGpioSetDir(PORT1,PIN19,OUTPUT);
	vGpioSetDir(PORT1,PIN20,OUTPUT);
	vGpioSetDir(PORT1,PIN21,OUTPUT);
	vGpioSetDir(PORT1,PIN22,OUTPUT);
	vGpioSetDir(PORT1,PIN23,OUTPUT);
	vGpioSetDir(PORT1,PIN24,OUTPUT);
	vGpioSetDir(PORT1,PIN25,OUTPUT);
	vGpioSetDir(PORT1,PIN26,OUTPUT);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

	 vGpioSetByte(PORT1,PIN19,num);
	 /* OR
	  * vAppPrintNum (num);
	  */
	  vAppDelay(1000);
	  /* Value will overflow to 0 after 255 */
	  num++;

  }
  /* End of Application entry point */
}




