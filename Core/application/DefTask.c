
#include "main.h"
#include "stm32f4xx_hal_conf.h"
#include "Myapp.h"
#include "stdbool.h"
#include "BuzzerTask.h"
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

osThreadId_t timerTaskHandle;
const osThreadAttr_t timerTask_attributes = {
  .name = "timerTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
void StarttimerTask(void *argument);
char txbuff[50];
void StarttimerTask(void *argument)
{
  /* USER CODE BEGIN StarttimerTask */
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
  /* Infinite loop */
  for(;;)
  {
	  TIM1->CCR1 = 2250;
	  		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	  		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	  		HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
	  		TIM2->ARR = 22500;
	  		__HAL_TIM_ENABLE(&htim2);
	  		TIM3->ARR = 45000;
	  		__HAL_TIM_ENABLE(&htim3);
	  		__HAL_TIM_ENABLE(&htim4);
	  		sprintf(txbuff,"ms: %ld\n\r",TIM4->CCR1);
	  			  captured_value1 = TIM4->CCR1;
	  			  HAL_UART_Transmit(&huart2, &txbuff, 15, 100);
	  		TIM4->CNT = 0;

	  	    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
    osDelay(1000);
  }
  /* USER CODE END StarttimerTask */
}

void deftask_init(){
	/* creation of timerTask */
	timerTaskHandle = osThreadNew(StarttimerTask, NULL, &timerTask_attributes);
}
