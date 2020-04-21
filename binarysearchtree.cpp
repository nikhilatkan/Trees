#include<iostream>
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

node* insert(node*&root,int data)
{
	if(root==NULL)
	{
		node* n=new node(data);
		root=n;
	}

	else if(data<=root->data)
	{
		root->left=insert(root->left,data);

	}

	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}

	return root;
}


node* buildtree(node* &root)
{
	int data;
	cin>>data;

	while(data!=-1)
	{
		insert(root,data);
		cin>>data;
	}
	return root;
}

void print(node*root)
{
	if(root==NULL)
	{
		return;
	}

	
	print(root->left);
	cout<<root->data<<",";
	print(root->right);

}

int findmin(node* root)
{
	node* current= root;

	while(current->left!=NULL)
	{
		current=current->left;
	}

	return current->data;
}

int findmax(node* root)
{
	node* current= root;

	while(current->right!=NULL)
	{
		current=current->right;
	}

	return current->data;
}




int main()
{
	node*root=NULL;
	root=buildtree(root);
	 cout<<findmin(root)<<endl;
	 cout<<findmax(root);
	
	//print(root);

}