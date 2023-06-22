#include <bits/stdc++.h>
using namespace std;

struct Node {
	int token;
	struct Node *next;
};
typedef struct Node *Tokens;
typedef char Event;
enum {Exit = 'E', NextCustomer = 'N', Serve = 'S'};

void genNextToken(Tokens *t) {
	static int NextToken = 1;
	Tokens nextTokenNode = (Tokens)malloc(sizeof(struct Node));
	nextTokenNode->token = NextToken++;
	nextTokenNode->next = NULL;

	Tokens *ptr;
	for (ptr = t; *ptr; ptr = &((*ptr)->next))
		;
	*ptr = nextTokenNode;
}
void printTokens(Tokens t) {
	for (; t; t = t->next)
		cout<<t->token<<endl;
}
void serveCustomer(Tokens *t) {
	if (*t == NULL) {
		cout<<"No token to serve"<<endl;
		return;
	}
	Tokens ptr = *t;
	*t = (*t)->next;
	free(ptr);
}
extern void printTokens(Tokens);
extern void genNextToken(Tokens *);
extern void serveCustomer(Tokens *);

int main() {
	Tokens t = NULL;
	Event e;
	do {
		printTokens(t);
		cin>>e;
		if (e == NextCustomer) genNextToken(&t);
		else if (e == Serve) serveCustomer(&t);
	} while (e != Exit);
} 