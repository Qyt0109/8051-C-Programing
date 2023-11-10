#include "main.h"

void setup()
{
	// setup code here, to run once:
	
}

unsigned char key_pressed;

unsigned char keys[] = {'7', '8', '9', '%',
												'4', '5', '6', '*',
												'1', '2', '3', '-',
												'C', '0', '=', '+'};

void loop()
{
	// code section to run repeatedly:
	char key = checkPressedButtonMatrixKeyboard4x4();
	if(key != -1)
		key_pressed = key;
	
}

void main()
{
	setup();
	while(1)
	{
		loop();
	}
}