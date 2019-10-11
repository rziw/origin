#include<iostream>
#include<conio.h>
#include <cstring>
using namespace std;
class Node
{
public:
	char main_root;//main root in each node
	char key[100];//the array which considered as a node during creating node
	Node *left;
	Node *right;
	void setKey(char key)
	{ // key=-1;
		left=NULL; right=NULL;
	};

	void setLeft(Node *aLeft) { left = aLeft; };
	void setRight(Node *aRight) { right = aRight; };
	string Key() { return key; };
	Node* Left() { return left; };

	Node* Right() { return right; };
};

class Tree {
	Node* root;
public:
	Tree();

	Node* Root() { return root; };
	void addTree(Node *leaf,char *inOrder);
	void addNode(char key,char *preOrder,char* inOrder);



};
Tree::Tree() {
	root = NULL;
}
void Tree::addNode(char key,char *preOrder,char *inOrder) {
	// No elements. Add the root
	if ( root == NULL ) {

		Node* n = new Node();
		n->main_root=key;
		n->left=n->right=NULL;

		root = n;
		int pos=0;
		cout<<"everything is OK and the key is : "<<n->main_root<<"\n";
		for(int i=0;i<strlen(inOrder);i++)
		{
			if(preOrder[0]==inOrder[i])
			{
				pos=i;
				cout<<pos<<"\n";
			}
		}

		cout<<inOrder<<"\n";

		root->right=new Node();
		root->left=new Node();

		for(int i=pos+1,j=0;i<=strlen(inOrder);i++,j++)
		{

			root->right->key[j]=inOrder[i];
		}

		for(int i=0,j=0;i<pos;i++,j++)
		{
			root->left->key[j]=inOrder[i];

		}

		cout<<"right leaf:"<<root->right->key<<"\n";


		cout<<"left leaf:"<<root->left->key<<"\n";
	}

	if(root->left->key!=NULL)
	{
		addTree(root->Left(),preOrder);
	}


	if(root->Right()!=NULL)
	{
		addTree(root->Right(),preOrder);
	}
}
void Tree::addTree(Node *leaf,char *preOrder)
{
	if(leaf==NULL) return;
	int position[100];
	int m=0;
	int first;

	cout<<"\n"<<"Sended leaf:"<<leaf->key<<"\n";
	for(int i=0;i<strlen(preOrder);i++)
	{
		for(int j=0;j<strlen(leaf->key);j++)
		{
			//find which comes sooner than other in preOrder to put it as a root in next step
			if (preOrder[i]==leaf->key[j])
			{
				position[m]=j;
				m++;
			}

		}
	}

	//creat a new node
	Node* n = new Node();

	n->left=n->right=NULL;
	int pos=0;
	m=position[0];
	n->main_root=leaf->key[m];
	n->right=new Node();
     n->left=new Node();
	for(int i=m+1,j=0;i<=100;i++,j++)
	{
		n->right->key[j]=leaf->key[i];
	}
	cout<<"Root of this node:"<<n->main_root<<"\n";
	cout<<"\n"<<"newly created right leaf : "<<n->right->key;


	for(int i=0,j=0;i<=m-1;i++,j++)
	{
		n->left->key[j]=leaf->key[i];
	}
	cout<<"\n"<<"newly created left leaf : "<<n->left->key;


	if(strlen(n->left->key)>1)
	{
		addTree(n->left,preOrder);
	}
	if(strlen(n->right->key)>1)
	{
		addTree(n->right,preOrder);
	}
}
int main()
{
	Tree* tree = new Tree();
	char preOrder[100];
	char inOrder[100];
	cout<<"Enter an array as a preOrder array:"<<"\n";
	cin>>preOrder;
	cout<<"Enter an array as an inOrder array:"<<"\n";
	cin>>inOrder;

	tree->addNode(preOrder[0],preOrder,inOrder);
	getch();
}
