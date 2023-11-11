/* __________________________________________________________________
___CAC CHAN LCD 16x2___

VSS: 0V						VDD: 5V						VEE: Dieu chinh do tuong phan
RS: Chon thanh ghi (RS=1: Doc/ghi du lieu, RS=0: Doc/ghi lenh)
R/W': Che do doc/ghi (R/W'=1: Doc (Read), R/W'=0: Ghi (Write))
E: Chan cho phep (Du lieu duoc doc/ghi tai thoi diem chan E chuyen
									trang thai tu cao xuong thap)
DB7-DB0: Bus du lieu de giao tiep voi LCD
LED+: Cuc duong den nen							LED-: Cuc am den nen
__________________________________________________________________

___CAC LENH CO BAN LCD 16x2___

Lenh									Chuc nang														T(us)

0x01		Xoa toan bo noi dung dang hien thi (Clear all)		1502
0x02		Di chuyen con tro ve vi tri dau man hinh					1502
0x06		Tu dong di chuyen con tro den vi tri tiep theo		 37
				moi khi xuat ra LCD 1 ky tu
0x0C		Bat hien thi va tat con tro												 37
0x0E		Bat hien thi va bat con tro												 37
0x80		Di chuyen con tro ve dau dong 1										 37
0xC0		Di chuyen con tro ve dau dong 2
0x38		Giao tiep 8 bit, hien thi 2 dong, font 5x7				 37
0x28		Giao tiep 4 bit, hien thi 2 dong, font 5x7				 37
___________________________________________________________________

___GUI LENH RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=0										Chon che do doc/ghi lenh
B3: Gui ma Lenh tuong ung		Gui lenh can giao tiep
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan lenh
		E=1
B5: Delay_us(T)							Delay de LCD thuc thi xong lenh
___________________________________________________________________

___GUI DATA RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=1										Chon che do doc/ghi du lieu
B3: Gui ma ASCII cua ky tu	Gui ky tu can hien thi
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan du lieu
		E=1
B5: Delay_us(T=37us)				Delay de LCD hien thi xong ky tu

*LUU Y: Ky tu duoc gui ra LCD se duoc hien thi tai vi tri con tro
___________________________________________________________________

___KHOI TAO LCD___

Tu khoi tao (HD44780): Che do giao tiep 8 bit, hien thi 1 dong tren,
											 tu dong tang con tro, tat hien thi
Khoi tao tuy chinh:
Cap nguon LCD, Delay 15-40ms (100ms)
Gui ma lenh 0011 xxxx	(Lay 0x38 cho de nho)
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
					[F] =1: Font 5x10 (hien thi ky tu ton mat ca 2 dong)
____________________________________________________________________

___VUNG NHO DDRAM LCD___

Vung DDRAM 80 byte luu cac ky tu can hien thi.
Danh dau dia chi che do 2 dong:
 /																													 \
|00	01	02	03	04	05	06	07	08	09	0A	0B	0C	0D	0E	0F| 10 11 ... 27
|H	E		L		L		O				W		O		R		L		D											|
|																															|
|40	41	42	43	44	45	46	47	48	49	4A	4B	4C	4D	4E	4F|	50 51 ... 67
 \																													 /
											 Vung hien thi
Set dia chi DDRAM de di chuyen con tro toi 1 vi tri trong DDRAM, tu do hien thi ky tu/chuoi ky tu tai 1 vi tri bat ki
Ma lenh:	1[7 bit DDRAM address]
VD: Xuat ky tu 'W' ra LCD tai dong 1 cot thu 7:
Gui lenh 1000 0110 (0x86)
Gui char 'W'

_____________________________________________________________________ */


#ifndef LCD_H
// {
	#define LCD_H
	
	// LCD lib settings
	#define LCD_8BIT 0x00
	#define LCD_4BIT 0x01
	#define LCD_1LINE 0x00
	#define LCD_2LINE 0x01
	#define LCD_5X8FONT 0x00
	#define LCD_5X10FONT 0x01

	// LCD CMD:

	#include "..\Common\common.h"
	#include "..\Delay\delay.h"
	#include "settings.h"
	#include "ascii.h"
	#include "port.h"

	#define LCD_CMD_CLEAR								0x01  		
	#define LCD_CMD_RETURN_HOME					0x02
	#define LCD_CMD_ENTRY_MODE					0x06
	#define LCD_CMD_TURN_OFF						0x08
	#define LCD_CMD_TURN_ON							0x0C
	#define LCD_CMD_CURSOR_OFF					0x0C  
	#define LCD_CMD_CURSOR_ON						0x0E
	#define LCD_CMD_CURSOR_ON_BLINK			0x0F
	#define LCD_CMD_MOVE_CURSOR_LEFT		0x10
	#define LCD_CMD_MOVE_CURSOR_RIGHT		0x11
	#define LCD_CMD_SHIFT_LEFT					0x18
	#define LCD_CMD_SHIFT_RIGHT					0x1C
	#define LCD_CMD_4BIT_1LINE_5x7FONT	0x20
	#define LCD_CMD_4BIT_2LINE_5x7FONT	0x28
	#define LCD_CMD_8BIT_1LINE_5x7FONT	0x30
	#define LCD_CMD_8BIT_2LINE_5x7FONT	0x38
	#define LCD_CMD_FIRST_ROW						0x80
	#define LCD_CMD_SECOND_ROW					0xC0

	void LCD_init();
	void LCD_send_cmd(byte cmd);
	void LCD_print_char(byte chr);
	void LCD_print_string(byte *str);
	void LCD_set_cursor_at(unsigned char row, unsigned char col);
	void LCD_print_char_at(unsigned char row, unsigned char col, byte chr);
	void LCD_print_string_at(unsigned char row, unsigned char col, byte *str);
	void LCD_turn_screen(bool is_on);
	void LCD_turn_screen_on_with_cursor(bool is_blink);
// }
#endif