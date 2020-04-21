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

node*LCA(node* root,int n1,int n2)
{
	if(root==NULL)
	{
		return NULL;
	}

	if(root->data>n1 && root->data>n2)
	{
		return LCA(root->left,n1,n2);
	}

	if(root->data<n1 && root->data<n2)
	{
		return LCA(root->right,n1,n2);
	}

	return root;
}

int main()
{
	node* root=NULL;
	root=buildtree();

	cout<<LCA(root,7,8)->data;
}

/*Testcase1: The BST in above test case will look like
          5
     /        \ 
    4           6
 /     \      /       \
3     N   N        7
/    \                 /     \ 
N    N            N      8
Here, the LCA of 7 and 8 is 7.
Testcase 2: For the given above test case the BST will be
                    2
                /        \
              1          3
Here, the LCA of 1 and 3 will be 2
*/