#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include <stdlib.h>
#include <termios.h>
//#include <term.h> // para el uso del CImg

class ListenKey
{
	public:
	void init_keyboard();
	void close_keyboard();
	int kbhit();
	int readch();
};