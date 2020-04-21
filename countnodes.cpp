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

int countnodes(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	int ans=1+countnodes(root->left)+countnodes(root->right);

	return ans;
}

int main()
{
	node* root=NULL;
	root=buildtree();

	cout<<countnodes(root);

}