#ifndef PORT_H
#define PORT_H

sbit IC74595_SH_CP_ROW_PIN = P2^0;// Shift Row bit data
sbit IC74595_DS_ROW_PIN = P2^1;		// Row bit data

sbit IC74595_SH_CP_COL_PIN = P2^4;// Shift Col bit data
sbit IC74595_DS_COL_PIN = P2^3;		// Col bit data

sbit IC74595_ST_CP_PIN = P2^2;		// Set output all


#endif