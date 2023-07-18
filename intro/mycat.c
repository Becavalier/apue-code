#include "apue.h"

#define BUFFSIZE 4096

/**
 * Unbuffered IO methods:
 * ssize_t read(int, void *, size_t);
 * ssize_t write(int __fd, const void * __buf, size_t __nbyte);
*/
int main(void) {
	int n;
	char buf[BUFFSIZE];

  // Read from standard input (file descriptor: 0).
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	  // Write to standard output (file descriptor: 1).
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
