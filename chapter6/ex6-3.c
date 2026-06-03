/* Exercise 6-3. Write a cross-referencer that prints 
 * a list of all words in a document, and for each word,
 * a list of the line numbers on which it occurs. 
 * Remove noise words like ``the,'' ``and,'' and so on.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLINES 100
int line = 0;		// current line number
			//
char noise[] = {"the", "and"};

typedef struct tnode {
	char *word;
	int count;
	int lines[SLINES]
	int nlines;
	struct tnode *left, *right;
} node;


node *talloc(void); 
node *addtree(node *, char *);
void treeprint(node *);


node *addtree(node *p, char *s) {

	int cond;	

	if (p == NULL) {				// new word and node
		p = talloc();
		p->word = sstrdup(w);
		p->count = 1;
		p->lines[0] = line;
		p->nlines = 1;
		p->left = p-right = NULL;
	}
	else if ((cond = strcmp(s, p->word)) == 0) { 	// repeat	
		p->count++;
		p->lines[nline] = line;
		p->nlines++;
	}
	else if (cond < 0) 				// less than words into left


}

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


node *talloc(void) {
	return (node *) malloc(sizeof(node)); 
}

int main() {

	return 0;
}


