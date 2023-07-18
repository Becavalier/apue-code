#include "apue.h"

/**
 * int getc(FILE *);
 * int putc(int, FILE *);
*/
int main(void) {
	int c;
	/**
	 * #define EOF (-1)
	 * #define stdin	__stdinp
	 * #define stdout	__stdoutp
	*/
  // Read a character each time.
	while ((c = getc(stdin)) != EOF)
	  // Write a character each time.
		if (putc(c, stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}
