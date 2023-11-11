#include "lcd.h"
#include "main.h"

// Validation
#ifndef LCD_SETTINGS_USING_DELAY
	#error "Missing #define LCD_SETTINGS_USING_DELAY LCD_DELAY_TIMER or #define LCD_SETTINGS_USING_DELAY LCD_DELAY_FOR_LOOP in main.h file!"
#endif

#ifndef LCD_SETTINGS_DISPLAY_MODE
	#error "Missing #define LCD_SETTINGS_DISPLAY_MODE LCD_4BIT_1LINE_5x7FONT/LCD_4BIT_2LINE_5x7FONT/LCD_8BIT_1LINE_5x7FONT/LCD_8BIT_2LINE_5x7FONT in main.h file!"
#endif

// Implement coresponding LCD_delay_ms
#if(LCD_SETTINGS_USING_DELAY == LCD_DELAY_TIMER)
	#error "Not yet implement LCD_delay_us for this LCD_SETTINGS_USING_DELAY config!"
	void LCD_delay_us(unsigned int t_us)
	{
		// TODO: Implement this
	}
#elif(LCD_SETTINGS_USING_DELAY == LCD_DELAY_FOR_LOOP)
	void LCD_delay_us(unsigned int t_us)
	{
		delay_us(t_us);
	}
#else
	#error "No any LCD_SETTINGS_USING_DELAY with that code, make sure using LCD_DELAY_TIMER or LCD_DELAY_FOR_LOOP instead!"
#endif

#if(LCD_SETTINGS_DISPLAY_MODE == LCD_4BIT_1LINE_5x7FONT || LCD_SETTINGS_DISPLAY_MODE == LCD_4BIT_2LINE_5x7FONT)
	void LCD_out(unsigned char byte)
	{
		LCD_D0 = byte & 0x01;		// ---- ---x
		LCD_D1 = byte & 0x02;		// ---- --x-
		LCD_D2 = byte & 0x04;		// ---- -x--
		LCD_D3 = byte & 0x08;		// ---- x---
	}
	void LCD_cmd(unsigned char cmd)
	{
		
	}
#elif(LCD_SETTINGS_DISPLAY_MODE == LCD_8BIT_1LINE_5x7FONT || LCD_SETTINGS_DISPLAY_MODE == LCD_8BIT_2LINE_5x7FONT)
	void LCD_out(unsigned char byte)
	{
		LCD_D0 = byte & 0x01;		// ---- ---x
		LCD_D1 = byte & 0x02;		// ---- --x-
		LCD_D2 = byte & 0x04;		// ---- -x--
		LCD_D3 = byte & 0x08;		// ---- x---
		LCD_D4 = byte & 0x10;		// ---x ----
		LCD_D5 = byte & 0x20;		// --x- ----
		LCD_D6 = byte & 0x40;		// -x-- ----
		LCD_D7 = byte & 0x80;		// x--- ----
	}
	void LCD_send(unsigned char byte)
	{
		LCD_RS = LOW;
		LCD_out(byte);
		LCD_EN = LOW;
		LCD_EN = HIGH;
	}
	void LCD_send_cmd(unsigned char cmd)
	{
		LCD_send(cmd);
		if(cmd == LCD_CLEAR || cmd == LCD_RETURN_HOME)
			LCD_delay_us(1502);
		else
			LCD_delay_us(37);
	}
#else
	#error "No any LCD_SETTINGS_DISPLAY_MODE with that code, make sure using LCD_4BIT_1LINE_5x7FONT/LCD_4BIT_2LINE_5x7FONT/LCD_8BIT_1LINE_5x7FONT/LCD_8BIT_2LINE_5x7FONT instead!"
#endif
	


