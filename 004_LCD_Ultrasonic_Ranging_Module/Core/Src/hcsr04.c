#include "hcsr04.h"
#include "tim.h"


uint32_t Read_Hcsr04(){
	
	uint32_t local_time;
	HAL_GPIO_WritePin(Trigger_Sensor_GPIO_Port,Trigger_Sensor_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Trigger_Sensor_GPIO_Port,Trigger_Sensor_Pin,GPIO_PIN_SET);
	us_delay(10);
	HAL_GPIO_WritePin(Trigger_Sensor_GPIO_Port,Trigger_Sensor_Pin,GPIO_PIN_RESET);
	
	while(!HAL_GPIO_ReadPin(Sensor_ECHO_GPIO_Port,Sensor_ECHO_Pin));
	
	while(HAL_GPIO_ReadPin(Sensor_ECHO_GPIO_Port,Sensor_ECHO_Pin)){
		
		local_time++;
		us_delay(1);
		
	}
	
	HAL_Delay(60);
	
	return local_time;
	
}


