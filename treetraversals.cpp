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

void preorderprint(node*root)
{
	if(root==NULL)
	{
		return;
	}

	cout<<root->data<<",";
	preorderprint(root->left);
	preorderprint(root->right);
}

void inorderprint(node* root)
{
	if(root==NULL)
	{
		return;
	}

	inorderprint(root->left);
	cout<<root->data<<",";
	inorderprint(root->right);
}

void postorderprint(node* root)
{
	if(root==NULL)
	{
		return;
	}

	postorderprint(root->left);
	postorderprint(root->right);
	cout<<root->data<<",";

}

int main()
{
	node* root=NULL;
	root=buildtree();
	//preorderprint(root);
	//inorderprint(root);
	//postorderprint(root);
	

}