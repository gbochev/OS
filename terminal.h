/*
Terminal
 */
#include "vga.h"
#include "keyboard.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
 
void terminal_initialize()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}
 
void terminal_putchar(char c)
{
	if (c == '\n')  //newline character
	{	
		terminal_row++;
		terminal_column = -1; // \n and return one place back
	}
	else
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if ( ++terminal_column == VGA_WIDTH )
	{
		terminal_column = 0;
		if ( ++terminal_row == VGA_HEIGHT )
		{
			terminal_row = 0;
		}
	}
}
 
void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ )
		terminal_putchar(data[i]);
}

char terminal_readkey()
{
	char c = readKey();
	terminal_putchar(c);
	return c;
}
char* terminal_readline()
{
	char prev = 0;
	char c = 0;
	char array[32] = {0};
	int i = 0;
	while(c != '\n' && i < 32)
	{
	c = readKey();
	if(c != prev)
	{
		i++;
		terminal_putchar(c);
		array[i] = c;
		prev = c;
	}
	}
	return array;
}
