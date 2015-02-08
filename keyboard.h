/*
Keyboard
driver
*/
static const size_t MAX_STRING = 32;

uint8_t inportb(uint16_t port)
{
	uint8_t ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

char getkbcode()
{
	char scancode = inportb(0x60);
	if(scancode == 0x10)
		return 'Q';
	if(scancode == 0x14)
		return 'T';
	if(scancode == 0x18)
		return 'O';
	if(scancode == 0x1C)
		return '\n';
	if(scancode == 0x20)
		return 'D';
	if(scancode == 0x24)
		return 'J';
	if(scancode == 0x2C)
		return 'Z';
	if(scancode == 0x30)
		return 'B';
	if(scancode == 0x34)
		return '.';	
	if(scancode == 0x0C)
		return '-';
	if(scancode == 0x08)
		return '7';
	if(scancode == 0x04)
		return '3';
	if(scancode == 0x05)
		return '4';
	if(scancode == 0x09)
		return '8';	
	if(scancode == 0x0D)
		return '=';	
	if(scancode == 0x11)
		return 'W';	
	if(scancode == 0x15)
		return 'Y';	
	if(scancode == 0x19)
		return 'P';
	if(scancode == 0x21)
		return 'F';	
	if(scancode == 0x25)
		return 'K';	
	if(scancode == 0x2D)
		return 'X';	
	if(scancode == 0x31)
		return 'N';	
	if(scancode == 0x39)
		return ' ';
	if(scancode == 0x02)
		return '1';	
	if(scancode == 0x06)
		return '5';	
	if(scancode == 0x0A)
		return '9';	
	if(scancode == 0x0E)
		return '\b';	
	if(scancode == 0x12)
		return 'E';	
	if(scancode == 0x16)
		return 'U';	
	if(scancode == 0x1A)
		return '[';	
	if(scancode == 0x1E)
		return 'A';
	if(scancode == 0x22)
		return 'G';
	if(scancode == 0x26)
		return 'L';
	if(scancode == 0x2E)
		return 'C';
	if(scancode == 0x32)
		return 'M';
	if(scancode == 0x03)
		return '2';
	if(scancode == 0x07)
		return '6';
	if(scancode == 0x0B)
		return '0';
	if(scancode == 0x13)
		return 'R';
	if(scancode == 0x17)
		return 'I';
	if(scancode == 0x1B)
		return ']';
	if(scancode == 0x1F)
		return 'S';
	if(scancode == 0x23)
		return 'H';
	if(scancode == 0x2F)
		return 'V';
	if(scancode == 0x27)
		return ';';
}
char readKey()
{
	while(true)
	{
	char c = getkbcode();
	if((c >= 'A' && c <= 'Z') || c == '\n' || c == ' ')
		return c;
	}
}
