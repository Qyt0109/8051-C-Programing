/* Example settings.h
#ifndef SETTINGS_H
// {
	#define SETTINGS_H
	
	#define FREQ_OSC FREQ_12MHZ
	#define DELAY_MODE DELAY_USING_FOR_LOOP
	
	#define LCD_SETTINGS_USING_DELAY LCD_DELAY_FOR_LOOP
	#define LCD_SETTINGS_DISPLAY_MODE LCD_4BIT_1LINE_5x7FONT
// }
#endif
*/

/* Example port.h
#ifndef PORT_H
// {
	#define PORT_H

	sbit LCD_RS = P2^0;
	sbit LCD_RW = P2^1;
	sbit LCD_EN = P2^2;

	sbit LCD_D0 = P3^0;
	sbit LCD_D1 = P3^1;
	sbit LCD_D2 = P3^2;
	sbit LCD_D3 = P3^3;
	sbit LCD_D4 = P3^4;
	sbit LCD_D5 = P3^5;
	sbit LCD_D6 = P3^6;
	sbit LCD_D7 = P3^7;
// }
#endif
*/

#include "lcd.h"

// Validation
#ifndef DELAY_MODE
	#error "DELAY_MODE not defined!"
#endif

#ifndef LCD_SETTINGS_BIT
// {
	#error "LCD_SETTINGS_BIT not defined!"
// }
#endif

#ifndef LCD_SETTINGS_LINE
// {
	#error "LCD_SETTINGS_LINE not defined!"
// }
#endif

#ifndef LCD_SETTINGS_FONT
// {
	#error "LCD_SETTINGS_FONT not defined!"
// }
#endif

// Delay for sending cmd/dta
#if (DELAY_MODE == DELAY_USING_TIMER_0 || DELAY_MODE == DELAY_USING_TIMER_1)
// {
	#error "TODO: Need to implement for this DELAY_MODE config!"
	void LCD_delay1502us()
	{
		delay_us(1502);
	}
	
	void LCD_delay37us()
	{
		delay_us(37);
	}
// }
#elif (DELAY_MODE == DELAY_USING_FOR_LOOP)
// {
	void LCD_delay1502us()
	{
		delay_ms(2);
	}
	
	void LCD_delay37us()
	{
		delay_ms(1);
	}
	
	void LCD_init()
	{
		/* ___KHOI TAO LCD___
		Tu khoi tao (HD44780): Che do giao tiep 8 bit, hien thi 1 dong tren,
													 tu dong tang con tro, tat hien thi
		Khoi tao tuy chinh:
		Cap nguon LCD, Delay 15-40ms (100ms)
		Gui ma lenh 0011 xxxx	(Lay 0x30 cho de nho)
		Delay 4100us	(5ms)
		Gui ma lenh 0011 xxxx
		Delay 100us		(1ms)
		Gui ma lenh 0011 xxxx
		Gui ma lenh 001[DL] [N][F]xx (Thuong lay 0x38)
		trong do: [DL]=0: Giao tiep 8 bit (DB7-DB0)
							[DL]=1:	Giao tiep 4 bit (DB7-DB4), byte lenh/du lieu se duoc gui/nhan 4 bit cao truoc, 4 bit thap sau
							[N]	=0: Hien thi 1 dong
							[N] =1: Hien thi 2 dong
							[F] =0: Font 5x8	(hien thi ky tu o dong tren hoac dong duoi)
							[F] =1: Font 5x10 (hien thi ky tu ton mat ca 2 dong) */
		LCD_send_cmd(0x30);
		delay_ms(5);
		LCD_send_cmd(0x30);
		delay_ms(1);
		LCD_send_cmd(0x30);
		
		LCD_send_cmd(0x20 | (LCD_SETTINGS_BIT ? 0x10 : 0x00) | (LCD_SETTINGS_LINE ? 0x08 : 0x00) | (LCD_SETTINGS_FONT ? 0x04 : 0x00));
	}
// }
#else
// {
	#error "No any LCD_SETTINGS_USING_DELAY with that code, make sure using LCD_DELAY_TIMER or LCD_DELAY_FOR_LOOP instead!"
// }
#endif

#if (LCD_SETTINGS_BIT == LCD_4BIT)
// {
	void LCD_out(byte out_byte)
	{
		LCD_D0 = out_byte & 0x01;		// ---- ---x
		LCD_D1 = out_byte & 0x02;		// ---- --x-
		LCD_D2 = out_byte & 0x04;		// ---- -x--
		LCD_D3 = out_byte & 0x08;		// ---- x---
	}
// }
#elif (LCD_SETTINGS_BIT == LCD_8BIT)
// {
	void LCD_out(byte b)
	{
		LCD_D0 = b & 0x01;		// ---- ---x
		LCD_D1 = b & 0x02;		// ---- --x-
		LCD_D2 = b & 0x04;		// ---- -x--
		LCD_D3 = b & 0x08;		// ---- x---
		LCD_D4 = b & 0x10;		// ---x ----
		LCD_D5 = b & 0x20;		// --x- ----
		LCD_D6 = b & 0x40;		// -x-- ----
		LCD_D7 = b & 0x80;		// x--- ----
	}
	void LCD_send(byte b)
	{
		LCD_out(b);
		LCD_EN = LOW;
		LCD_EN = HIGH;
	}
	void LCD_send_cmd(byte cmd)
	{
		LCD_RS = LOW;		// RS LOW to send cmd
		LCD_send(cmd);
		if (cmd == LCD_CMD_CLEAR || cmd == LCD_CMD_RETURN_HOME)
			LCD_delay1502us();
		else
			LCD_delay37us();
	}
	void LCD_print_char(byte chr)
	{
		LCD_RS = HIGH;		// RS HIGH to send char
		LCD_send(chr);
		LCD_delay37us();
	}
	void LCD_print_string(byte *str)
	{
		unsigned int chr_idx;
		while (str[chr_idx] != ASCII_NULL)	// Print char untill null (\n - 0 - end of string)
		{
			LCD_print_char(str[chr_idx]);
			chr_idx ++;
		}
	}
	
// }
#else
// {
	#error "No any LCD_SETTINGS_DISPLAY_MODE with that code, make sure using LCD_4BIT_1LINE_5x7FONT/LCD_4BIT_2LINE_5x7FONT/LCD_8BIT_1LINE_5x7FONT/LCD_8BIT_2LINE_5x7FONT instead!"
// }
#endif
void LCD_turn_screen(bool is_on)
{
	LCD_send_cmd(is_on ? LCD_CMD_TURN_ON : LCD_CMD_TURN_OFF);
}

void LCD_turn_screen_on_with_cursor(bool is_blink)
{
	LCD_send_cmd(is_blink ? LCD_CMD_CURSOR_ON_BLINK : LCD_CMD_CURSOR_ON);
}


