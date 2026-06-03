/* Exercise 6-4. Write a program that prints the distinct words 
 * in its input sorted into decreasing order of frequency of 
 * occurrence. Precede each word by its count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct tnode {
	char *word;
	int count;
	struct tnode *left, *right;
} node;


node *talloc(void); 
node *addtree(node *, char *);

void treeprint(node *);
char *sstrdup(char *);
int getword(char *, int lim);
int isnoise(char *);

node *addtree(node *p, char *w) {

	int cond;	

	if (p == NULL) {				// new word and node
		p = talloc();
		p->word = sstrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0) { 	// repeat	
		p->count++;
	}
	else if (cond < 0) 				// less than words into left
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return  p;
}

void treeprint(node *p) {

	if (p != NULL) {
		treeprint(p->left);
		printf("%s occurs %4d time(s) at lines [", p->word, p->count);
		treeprint(p->right);
	}
}

node *talloc(void) {
	return (node *) malloc(sizeof(node)); 
}

char *sstrdup(char *s) {

	char *p;
	p = (char *) malloc(strlen(s) + 1);

	if (p != NULL)
		strcpy(p, s);

	return p;
}

int getword(char *word, int lim) {
	int c;
	char *w = word;

	while (isspace(c = getchar()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getchar())) {
			ungetc(*w, stdin);
			break;
		}
	*w = '\0';
	return word[0];
}

int isnoise(char *w) {
	const char noise[][5] = {{"the"}, {"and"}, {"or"}, {"but"}, {"like"}, {"in"}, {"a"}, {"of"}};
	int cond;
	for (int i = 0; i < 8; i++)
		if ((cond = strcmp(w, noise[i])) == 0)
			return 0;
	return 1;
}

int main() {

	node *root;
	root = NULL;
	char word[MAX];

	while (getword(word, MAX) != EOF)
		if (isalpha(word[0]))
			if (isnoise(word))
				root = addtree(root, word);

	treeprint(root);

	return 0;
}
