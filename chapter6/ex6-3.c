/* Exercise 6-3. Write a cross-referencer that prints 
 * a list of all words in a document, and for each word,
 * a list of the line numbers on which it occurs. 
 * Remove noise words like ``the,'' ``and,'' and so on.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode {
	char *word;
	int count;
	int *lines;
	int nlines;
	struct tnode *left, *right;
} node;

struct word *nalloc(void); 
void treeprint(node *);

void treeprint(node *p) {

	if (p != NULL) {
		treeprint(p->left);
		
		printf("%s occurs %4d times at lines [", p->word, p->count);
		for (int i = 0; i < p->nlines; i++) 
			printf(" %d", p->lines[i]);
		printf(" ]\n");

		treeprint(p->right);
	}
}

struct tnode *talloc(void) {
	return (node *) malloc(sizeof(node)); 
}


