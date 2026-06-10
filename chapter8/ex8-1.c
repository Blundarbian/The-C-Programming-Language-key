/* Exercise 8-1. Rewrite the program cat from Chapter 7 using read, 
 * write, open, and close instead of their standard library 
 * equivalents. Perform experiments to determine the relative 
 * speeds of the two versions
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	int f1, n;
	char buf[BUFSIZ];

	if (argc != 2) {
		fprintf(stderr, "Usage: file to concat\n");
		return 1;
	}

	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
		fprintf(stderr, "cat: can't open %s file\n", argv[1]);
		return 2;
	}

	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(1, buf, n) != n) {
			fprintf(stderr, "cat: error writing to stdout\n");
			return 3;
		}
	close(f1);

	return 0;
}
