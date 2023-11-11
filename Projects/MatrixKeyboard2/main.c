#include "main.h"

void setup()
{
	// setup code here, to run once:
	
}

unsigned char key_pressed;

void loop()
{
	// code section to run repeatedly:
	char key = checkPressedButtonMatrixKeyboard4x4();
	if(key != -1)
	{
		key_pressed = key;
		P3 = key;
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