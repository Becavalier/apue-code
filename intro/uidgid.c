#include "apue.h"

/**
 * uid_t getuid(void);
 * gid_t getgid(void);
*/
int main(void) {
	// Get uid and gid of the current user.
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	exit(0);
}
