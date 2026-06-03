/* Exercise 6-4. Write a program that prints the 
 * distinct words in its input sorted into decreasing
 * order of frequency of occurrence. Precede each word 
 * by its count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int nodenum = 0;
			
typedef struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
} node;


node *talloc(void); 
node *addtree(node *, char *);

void nodeprint(node *);
char *sstrdup(char *);
int getword(char *, int lim);
int isnoise(char *);
void sortnodes(node *);
void populate(node *p, node *arr, int *);

node *addtree(node *p, char *w) {

	int cond;	

	if (p == NULL) {				// new word and node
		p = talloc();
		p->word = sstrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
		nodenum++;
	}
	else if ((cond = strcmp(w, p->word)) == 0)  	// repeat	
		p->count++;
	else if (cond < 0) 				// less than words into left
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return  p;
}

void nodeprint(node *p) {

	for (int i = 0; i < nodenum; i++) {
		p++;
		printf("%s occurs %4d time(s)\n", p->word, p->count);
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

void sortnodes(node *a) {

	for (int i = 0; i < nodenum; i++) {
		for (int j = 0; j < nodenum - 1; j++) {
			if ((a[j].count) < (a[j + 1].count)) {
				node temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

}

void populate(node *p, node *arr, int *i) {

	if (p != NULL) {
		populate(p->left, arr, i);
		arr[*i] = *p;
		(*i)++;	// breaks incrimenting while indexing 
		populate(p->right, arr, i);
	}
}

int main() {

	node *root;
	root = NULL;
	char word[MAX];

	while (getword(word, MAX) != EOF)
		if (isalpha(word[0]) && isnoise(word))
			root = addtree(root, word);
	
	// create array for the size of nodes in our tree
	node *snodes = (node *) malloc(nodenum * sizeof(node));
	int id = 0; // index for arr of sorted nodes
	populate(root, snodes, &id); // fill arr with nodes from tree
	sortnodes(snodes);	// bubble sort nodes from tree

	for (int i = 0; i < nodenum; i++)
		printf("%s occurs %d times\n", snodes[i].word, snodes[i].count);

	free(snodes);
	snodes = NULL;

	return 0;
}
