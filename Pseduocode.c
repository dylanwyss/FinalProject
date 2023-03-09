void main()
{
	initGPIO();		// for inputs and outputs (LED)
	initTimerA();		// timer for sensor actions  
	initTimerB();		// timer for how often LED should blink
	initADC();		// for sensors
	initUART(); 		// for Wifi connection
	
	while(1)
	{
		LED = green;
		buzzer = level_0;  // buzzer off
		
		int smoke = readADC1();
		int temperature = readADC2();
		
		if(smoke > smoke_threshold)		
		{
			LED = yellow;
			Buzzer = level_1; 	// Lowest noise level
		} 
		
		if((smoke > smoke_threshold) && (temperature > temp_threshold))
		{
			if (time_enabled <= 30sec)
			{
				LED = red;
				Buzzer = level_2;		// Medium noise level 
			}
			else if(time_enabled > 30sec)
			{
				LED = blink_red;
				Buzzer = level_3;		// Highest noise level
			}
		}
		
		if((smoke > smoke_threshold) && (temperature > temp_threshold) && (time_enabled > 30sec))
		{
			UARTTransmit(msg)
				"There is a fire in this building. The current temperature is {temp}. The air quality is {smoke}.";
		}
	}
}
