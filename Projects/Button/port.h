#ifndef PORT_H
// {
	#define PORT_H

	sbit button_pull_down = P1^0;		// Active High
	sbit button_pull_up = P1^1;			// Active Low

	sbit led_pull_down = P3^1;		// Source Current
	sbit led_pull_up = P3^0;			// Source Current
// }
#endif