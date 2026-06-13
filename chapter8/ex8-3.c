/* Exercise 8-3. Design and write _flushbuf, fflush, and fclose
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef NULL
#undef NULL
#undef stdin
#undef stdout
#endif

#define NULL 0
#define EOF (-1)
#define OPEN_MAX 20	// max files one program can open at once

typedef struct _iobuf {
	int cnt; /* characters left */
	char *ptr; /* next character position */
	char *base; /* location of buffer */
	int flag; /* mode of file access */
	int fd; /* file descriptor */
} myFile;

extern myFile _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])

enum _flags {
    _READ = 01, /* file open for reading */ /* binary 1 */
    _WRITE = 02, /* file open for writing */ /* binary 10 */
    _UNBUF = 03, /* file is unbuffered */ /* binary 11 */
    _EOF = 010, /* EOF has occurred on this file */ /* binary 1000 */
    _ERR = 020, /* error occurred on this file */ /* binary 10000*/
};

int _fillbuf(myFile *);
int _flushbuf(int, myFile *);
int mflush(myFile *);
int ffclose(myFile *);
myFile *ffopen(char *, char *);


#define PERMS 0666
myFile *ffopen(char *name, char *mode) {
	int fd;
	myFile *fp;
	char c = mode[0];

	if (c != 'r' && c != 'w' && c != 'a')
		return NULL;

	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;				// free slot
	
	if (fp >= _iob + OPEN_MAX)			// no free 
		return NULL;


	if (c == 'w')
		fd = creat(name, PERMS);
	else if (c == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	
	if (fd == -1) return NULL;			// unable to access
	

	fp->flag = _WRITE;
	if (c == 'r') fp->flag = _READ;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;

	return fp;
}



int mflush(myFile *file) {
	int ret = 0;
	myFile *fp;

	if (file == NULL) {
		for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
			if ((fp->flag & _WRITE) == 0 && mflush(fp) == -1)
				ret = -1;
	} else {
		if ((file->flag & _WRITE) == 0)
			return -1;
		_flushbuf(EOF, file);
		
		if (file->flag & _ERR)
			ret = -1;
	}
	return ret;
}


int ffclose(myFile *fp) {

	int fd;
	
	if (fp == NULL)
		return -1;

	fd = fp->fd;
	mflush(fp);

	fp->cnt = 0;
	fp->ptr = NULL;

	if (fp->base != NULL)
		free(fp->base);

	fp->base = NULL;
	fp->flag = 0;
	fp->fd = -1;

	return close(fd);
}


int main() {

	int c;
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}


myFile _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
	{ 0, (char *) 0, (char *) 0, _READ, 0 },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
};


int _flushbuf(int c, myFile *fp) {

	int num, bufs;
	unsigned char uc = c;

	if ((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
		return EOF;

	// no buffer
	if (fp->base == NULL && ((fp->flag & _UNBUF) == 0)) {
		fp->base = malloc(BUFSIZ);
		if (fp->base == NULL)
			fp->flag |= _UNBUF;
		else {
			fp->ptr = fp->base;
			fp->cnt = BUFSIZ - 1;
		}
	}

	if (fp->flag & _UNBUF) { 	// write 
		fp->ptr = fp->base = NULL;
		fp->cnt = 0;

		if (c == EOF)
			return EOF;

		num = write(fp->fd, &uc, 1);
		bufs = 1;
	}

	else {		
		bufs = (int) (fp->ptr - fp->base);
		num = write(fp->fd, fp->base, bufs);

		fp->ptr = fp->base;
		fp->cnt = BUFSIZ - 1;
	}

	if (num == bufs)
		return c;

	fp->flag |= _ERR;
	return EOF;
}


int _fillbuf(myFile *fp) {

	int bufs;

	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;

	if (fp->flag & _UNBUF) bufs = 1;
	else BUFSIZ;

	if (fp->base == NULL) { 		// no buffer found
		fp->base = (char *) malloc(bufs);
		if (fp->base == NULL) 
			return EOF;	// no buffer
	}

	fp->ptr = fp->base;

	fp->cnt = read(fp->fd, fp->ptr, bufs);

	
	if (--fp->cnt < 0) {
		
		if (fp->cnt == -1) fp->flag |= _EOF;
		else fp->flag |= _ERR;

		fp->cnt = 0;
		return EOF;
	}

	return (unsigned char) *fp->ptr++;
}
