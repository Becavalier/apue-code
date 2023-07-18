#include "apue.h"

/**
 * pid_t getpid(void);
*/
int main(void) {
	// Print process id.
	printf("hello world from process ID %ld\n", (long) getpid());
	exit(0);
}
