#if !defined(__cplusplus)
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>
#if defined(__cplusplus)
extern "C" 
#endif

#include "terminal.h"


void kernel_main()
{
	terminal_initialize();
	terminal_writestring("!#:");
	terminal_readline();

}
