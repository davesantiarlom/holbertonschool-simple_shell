#include "shell.h"

/**
* handle - A function to handle Ctr + C signal.
* @signals: The signal to handle.
* Return: Nothing.
*/

void handle(int signals){
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 4);
}
