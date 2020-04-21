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

int height(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	return 1+ max(lh,rh);
}


int main()
{
	node* root=NULL;
	root=buildtree();

	cout<<height(root);

}