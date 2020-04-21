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

int sumleaf(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL)
	{
		return root->data;
	}

	return sumleaf(root->left)+sumleaf(root->right);
}

int countleafnode(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL)
	{
		return 1;
	}

	return countleafnode(root->left)+countleafnode(root->right);

}

void leafnode(node* root)
{
	if(root==NULL)
	{
		return ;
	}

	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
	}

	 leafnode(root->left);
	 leafnode(root->right);

}

int main()
{
	node* root=NULL;
	root=buildtree();

	//cout<<sumleaf(root);
	leafnode(root);
}