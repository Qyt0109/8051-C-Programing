#include "main.h"

unsigned char code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
unsigned char code SEVEN_SEGMENT_LED_CATHODE_CODES[] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

// Check button pressed inside 7 segment led sweep

void setup()
{
	// setup code here, to run once:
	CONTINUE_PAUSE_BUTTON = LOW;// Active HIGH
	START_STOP_BUTTON = LOW;		// Active HIGH
	SEVEN_SEGMENT_LED_CONTROL_PIN_1 = LOW;	// Active HIGH
	SEVEN_SEGMENT_LED_CONTROL_PIN_0 = LOW;	// Active HIGH
	GREEN_LED_PIN = HIGH;		// Active LOW
	YELLOW_LED_PIN = HIGH; 	// Active LOW
}

bit IS_PAUSE = TRUE;
bit IS_STOP = TRUE;


void checkStartStopButtonToToggleIsStop()
{
	if(START_STOP_BUTTON == HIGH)
	{
		delay_ms(20);
		START_STOP_BUTTON = LOW;
		if(START_STOP_BUTTON == HIGH)
		{
			IS_STOP = !IS_STOP;
			while(START_STOP_BUTTON == HIGH)
			{
				// Wait for the button to be released...
			}
		}
	}
}

void checkContinuePauseButtonToToggleIsPause()
{
	if(CONTINUE_PAUSE_BUTTON == HIGH)
	{
		delay_ms(20);
		CONTINUE_PAUSE_BUTTON = LOW;
		if(CONTINUE_PAUSE_BUTTON == HIGH)
		{
			IS_PAUSE = !IS_PAUSE;
			while(CONTINUE_PAUSE_BUTTON == HIGH)
			{
				// Wait for the button to be released...
			}
		}
	}
}

unsigned char display_number = 0;

#define T_LED_SWEEP_DELAY_MS 1
#define T_TO_DISPLAY_EACH_MS 1000
void fastDisplay(unsigned number)
{
	SEVEN_SEGMENT_LED_DATA_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[(number % 100) / 10];
	SEVEN_SEGMENT_LED_CONTROL_PIN_1 = HIGH;
	delay_ms(T_LED_SWEEP_DELAY_MS);
	SEVEN_SEGMENT_LED_CONTROL_PIN_1 = LOW;
	SEVEN_SEGMENT_LED_DATA_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[(number % 100) % 10];
	SEVEN_SEGMENT_LED_CONTROL_PIN_0 = HIGH;
	delay_ms(T_LED_SWEEP_DELAY_MS);
	SEVEN_SEGMENT_LED_CONTROL_PIN_0 = LOW;
}

void setStatusLed()
{
	GREEN_LED_PIN = IS_STOP;
	YELLOW_LED_PIN = !IS_PAUSE || IS_STOP;
}

void loop()
{
	// code section to run repeatedly:
	setStatusLed();
	checkStartStopButtonToToggleIsStop();
	while(IS_STOP == FALSE)
	{
		{
			unsigned int x;
			for(x = 0; x < T_TO_DISPLAY_EACH_MS/(T_LED_SWEEP_DELAY_MS * 2) && IS_STOP == FALSE; x++)
			{
				fastDisplay(display_number);
				checkStartStopButtonToToggleIsStop();
				checkContinuePauseButtonToToggleIsPause();
				setStatusLed();
			}
		}
		if(IS_PAUSE == FALSE)
		{
			display_number++;
		}
	}
	// RESET
	display_number = 0;
	IS_PAUSE = TRUE;
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}