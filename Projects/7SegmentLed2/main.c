#include "main.h"

unsigned char code SEVEN_SEGMENT_LED_ANODE_CODES[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
unsigned char code SEVEN_SEGMENT_LED_CATHODE_CODES[] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void display(unsigned char number, unsigned int t_ms)
{
	unsigned char display_number = number % 100;	// Make sure 2 digits number
	unsigned char display_number_1 = display_number / 10;
	unsigned char display_number_0 = display_number % 10;
	
	unsigned int x;
	for(x = 0; x < t_ms/2; x++)
	{
		// Display display_number_1
		COUNT_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[display_number_1];
		COUNT_1_PIN = HIGH;
		delay_ms(1);
		COUNT_1_PIN = LOW;
		// Display display_number_0
		COUNT_PORT = SEVEN_SEGMENT_LED_ANODE_CODES[display_number_0];
		COUNT_0_PIN = HIGH;
		delay_ms(1);
		COUNT_0_PIN = LOW;
	}
}

unsigned char t_to_count_s[3] = {20, 10, 15};
unsigned char traffic_led_index;	// 0 RED, 1 YELLOW, 2 BLUE

void setup()
{
	// setup code here, to run once:
	GREEN_LED_PIN = HIGH;		// Active Low
	YELLOW_LED_PIN = HIGH;	// Active Low
	RED_LED_PIN = HIGH;			// Active Low
	COUNT_1_PIN = LOW;			// Active High - NPN
	COUNT_0_PIN = LOW;			// Active High - NPN
	COUNT_PORT = 0x00;
	traffic_led_index = 0;
}

void loop()
{
	char count_s;
	if(traffic_led_index == 0)
		GREEN_LED_PIN = LOW;
	else if (traffic_led_index == 1)
		YELLOW_LED_PIN = LOW;
	else if (traffic_led_index == 2)
		RED_LED_PIN = LOW;
	for(count_s = t_to_count_s[traffic_led_index]; count_s >= 0; count_s--)
	{
		display(count_s, 1000);
	}
	traffic_led_index++;
	if(traffic_led_index >= 3)
	{
		traffic_led_index = 0;
	}
	GREEN_LED_PIN = YELLOW_LED_PIN = RED_LED_PIN = HIGH;
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}

