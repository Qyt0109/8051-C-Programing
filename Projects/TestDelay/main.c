#include "main.h"

void main()
{
	while(1)
	{
		P3_0 = 0;
		delay_ms(1000);
		P3_0 = 1;
		delay_ms(1000);
	}
}