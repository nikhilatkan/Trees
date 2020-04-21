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


bool isBST(node* root,int min,int max)
{
	if(root==NULL)
	{
		return true;
	}

	if(root->data>min && root->data<max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max))
	{
		return true;
	}

	else 
		return false;
}

bool isBSTvalue(node*root)
{
	return isBST(root,INT_MIN,INT_MAX);
}

int main()
{
	node* root=NULL;
	root=buildtree();
	cout<<isBSTvalue(root);

}