#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};

node* buildtree()
{

	int d;
	cin>>d;

	if(d==-1)
	{
		return NULL;
	}
	node* n=new node(d);
	n->left=buildtree();
	n->right=buildtree();

	return n;
}

void printlevel(node*root,int level)
{

	if(root==NULL)
	{
		return;
	}
	if(level==0)
	{
		cout<<root->data<<",";
	}

	printlevel(root->left,level-1);
	printlevel(root->right,level-1);
}

int main()
{
	node* root=NULL;
	root=buildtree();

	printlevel(root,2);
}