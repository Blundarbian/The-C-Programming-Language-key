/* Exercise 8-2. Rewrite fopen and _fillbuf with fields instead 
 * of explicit bit operations. Compare code size and execution speed.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20	// max files one program can open at once

typedef struct _iobuf {
	int cnt; /* characters left */
	char *ptr; /* next character position */
	char *base; /* location of buffer */
	int flag; /* mode of file access */
	int fd; /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ = 01, /* file open for reading */ /* binary 1 */
    _WRITE = 02, /* file open for writing */ /* binary 10 */
    _UNBUF = 03, /* file is unbuffered */ /* binary 11 */
    _EOF = 010, /* EOF has occurred on this file */ /* binary 1000 */
    _ERR = 020, /* error occurred on this file */ /* binary 10000*/
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
	{ 0, (char *) 0, (char *) 0, _READ, 0 },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
	{ 0, (char *) 0, (char *) 0, _WRITE, | _UNBUF, 2 }
};


int _fillbuf(FILE *fp) {

	int bufs;

	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;

	if (fp->flag & _UNBUF) bufs = 1;
	else BUFSIZ;

	if (fp->base == NULL) 		// no buffer found
		if ((fp->base = (char *) malloc(bufs)) == NULL)
			return EOF;	// no buffer

	fp->ptr = fp->base;

	fp->cnt = read(fp->fd, fp->ptr, bufs);

	
	if (--fp->cnt < 0) {
		
		if (fp->cnt == -1) fp->flag |= _EOF;
		else fp->flag |= _ERR;

		fp->cnt = 0;
		return EOF
	}

	return *fp->ptr++;
}
