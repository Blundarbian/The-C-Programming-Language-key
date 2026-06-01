/* Exercise 6-2. Write a program that reads a C program 
 * and prints in alphabetical order each group of variable 
 * names that are identical in the first 6 characters, 
 * but different somewhere thereafter. Don't count words 
 * within strings and comments. Make 6 a parameter that 
 * can be set from the command line
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int csearch = 6;	// num of character to search defaults to 6

struct tnode {
	char *word;			// points to word 
	int count;			// num of occurences
	struct tnode *left, *right;	// l/r children
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);
char *strdup(char *s);


int main(int argc, char *argv[]) {

	if (argc == 2)			// paramater search length
		csearch = atoi(argv[1]);

	struct tnode *root;
	char word[MAX];

	root = NULL;
	while (getword(word, MAX) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	treeprint(root);

	return 0;
}


struct treenode *addtree(struct tnode *p, char *w) {

	int cond;

	if (p == NULL) {		// new word and node
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		// repeated word

	else if (cond < 0)	// less than words into left subtree
		p->left = addtree(p->left, w);

	else			// greater than words into right subtree
		p->right = addtree(p->right, w);

	return p;
}


// in-order print of tree p
void treeprint(struct tnode *p) {

	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}


// make a tnode
struct tnode *talloc(void) {

	return (struct tnode *) malloc(sizeof(struct tnode));
}


// make duplicate of s
char *strdup(char *s) {
	
	char *p;
	p = (char *) malloc(strlen(s) + 1); 	// +1 for nullterm

	if (p != NULL)
		strcpy(p, s);

	return p;
}
