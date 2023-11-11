#include "main.h"

byte code MATRIX_LED_5X7_CODES[16][5]  = {{0xC1, 0xAE, 0xB6, 0xBA, 0xC1},		// 0
																					{0x7F, 0xBD, 0x00, 0xBF, 0x7F},		// 1
																					{0x1D, 0x2E, 0x36, 0x36, 0x39},		// 2
																					{0x5D, 0x3E, 0x36, 0x36, 0x49},		// 3
																					{0x67, 0x6B, 0x6D, 0x00, 0x6F},		// 4
																					{0x50, 0x36, 0x36, 0x36, 0x4E},		// 5
																					{0x41, 0x36, 0x36, 0x36, 0x4D},		// 6
																					{0x7E, 0x7E, 0x0E, 0x76, 0x78},		// 7
																					{0x49, 0x36, 0x36, 0x36, 0x49},		// 8
																					{0x59, 0x36, 0x36, 0x36, 0x41},		// 9
																					{0x01, 0x76, 0x76, 0x76, 0x01},		// A
																					{0x00, 0x36, 0x36, 0x36, 0x49},		// B
																					{0x41, 0x3E, 0x3E, 0x3E, 0x5D},		// C
																					{0x00, 0xBE, 0xBE, 0xBE, 0x41},		// D
																					{0x00, 0x36, 0x36, 0x36, 0x3E},		// E
																					{0x00, 0x76, 0x76, 0x76, 0x7E}};	// F

void setup()
{
	// setup code here, to run once:
}

#define DELAY_MS 1000
// With SPACING and OFFSET
#define TIME 2
#define SPACING 3
#define OFFSET (5 + SPACING) * (TIME - 1) + 1
// Stand still
#define SPACING_OFF 0
#define OFFSET_OFF 0


bit mode;
void checkSwitchModeButtonToToggleMode()
{
	SWITCH_MODE_BUTTON = LOW;
  if(SWITCH_MODE_BUTTON == HIGH)
  {
  	delay_ms(20);
  	mode = !mode;
  	while(SWITCH_MODE_BUTTON == HIGH)
  	{
  		// Waiting for button to be released
  	}
  }
}

void loop()
{
	// code section to run repeatedly:
	unsigned char code_index;
	unsigned char number_of_codes = sizeof(MATRIX_LED_5X7_CODES) / sizeof(MATRIX_LED_5X7_CODES[0]);
	if(mode)
	{
		// With SPACING and OFFSET
		for(code_index = 0; code_index < number_of_codes; code_index++)
		{
			unsigned char off_set;
			for(off_set = 0; off_set < OFFSET; off_set++)
			{
				unsigned char x;
				for(x = 0; x < (DELAY_MS/(MATRIX_LED_5X7_DELAY_MS * 5))/5; x++)
				{
					MATRIX_LED_5X7_fastDisplay(MATRIX_LED_5X7_CODES[code_index], off_set, SPACING);
					checkSwitchModeButtonToToggleMode();
					if(!mode)
						break;
				}
				if(!mode)
					break;
			}
			if(!mode)
				break;
		}
	}
	else
	{
		// Stand still
		for(code_index = 0; code_index < number_of_codes; code_index++)
		{
			unsigned char x;
			for(x = 0; x < (DELAY_MS/(MATRIX_LED_5X7_DELAY_MS * 5)); x++)
			{
				MATRIX_LED_5X7_fastDisplay(MATRIX_LED_5X7_CODES[code_index], OFFSET_OFF, SPACING_OFF);
				checkSwitchModeButtonToToggleMode();
				if(mode)
					break;
			}
			if(mode)
				break;
		}
	}
}

void main()
{
	setup();
	while(TRUE)
	{
		loop();
	}
}