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

int levelorderusingqueue(node* root)
{
	queue<node*> q;
	q.push(root);
	while(1)
	{
		node* temp=q.front();
		cout<<temp->data;
		q.pop();

		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}

		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}

	}
}

int main()
{
	node* root=NULL;
	root=buildtree();
	levelorderusingqueue(root);
}