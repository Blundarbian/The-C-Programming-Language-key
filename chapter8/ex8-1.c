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

	if (argc != 2)
		perror("Usage: file to concat");
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		perror("cat: can't open file");

	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(1, buf, n) != n)
			perror("cat: write to stdout error");
	return 0;
}
