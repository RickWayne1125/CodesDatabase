#include<iostream>
using namespace std;

typedef struct BNode {

	char data;
	struct BNode* lc, * rc;
}BNode, * BST;

void cr_BST(BST& T){ 
	char ch;
	cin >> ch;
	if (ch == '#')	 T = NULL;
	else {
		T = new BNode;
		T->data = ch;
		cr_BST(T->lc);
		cr_BST(T->rc);
	}
}

int find(BST T){
	int ans = 0;
	if (T == NULL)	return 0;
	if (T->lc == NULL && T->rc == NULL)
		ans++;
	else ans += find(T->lc) + find(T->rc);
	return ans;
}

void LRD(BST T) {
	if (T != NULL) {
		LRD(T->lc);
		cout << T->data;
		LRD(T->rc);
	}
	
}

int main(){
	BST T;
	cr_BST(T);
	LRD(T);
	cout << endl;
	cout << find(T);
	delete T;
	return 0;
}