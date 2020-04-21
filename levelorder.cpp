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

int levelorder(node* root)
{
	int min_level=0;
	int max_level=height(root);

	for(int depth=min_level;depth<max_level;depth++)
	{
		printlevel(root,depth);
		cout<<endl;
	}
} 

int main()
{
	node* root=NULL;
	root=buildtree();

	levelorder(root);
}