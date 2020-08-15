#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node *newnode(int data)
{
	node* n=(struct node*)malloc(sizeof(node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;	
}
node *insert(node *node,int data)
{
	if(node==NULL)
	{
		return newnode(data);
	}
	else
	{
		if(node->data<data)
		{
			node->right=insert(node->right,data);
		}
		else
		{
			node->left=insert(node->left,data);			
		}
		return node;
	}
}
void preorder(node *node)
{
	if(node==NULL)
		return;
	cout<<node->data<<endl;
	preorder(node->left);
	preorder(node->right);
}
void postorder(node *node)
{
	if(node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<endl;
}
void inorder(node *node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}
int search(node* root,int key)
{
if(root!=NULL)
{
	if(root->data==key)
	{
return 1;
	}
	if(root->data>key)
	{
		search(root->left,	key);
	}
	else
	{
		search(root->right,key);
	}
}
else
{
	return 0;
}
}
int height( node* node)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		int lh=height(node->left);
		int rh=height(node->right);
if (lh > rh)  
            return(lh + 1);  
        else return(rh + 1);  
}	}
int main()
{
	node *root=NULL;
	root=insert(root,20);
	insert(root,15);
	insert(root,25);
	insert(root,16);
	insert(root,14);
	insert(root,26);
	insert(root,24);
	cout<<"Preorder display is"<<endl;
	preorder(root);
	cout<<"inorder display is"<<endl;
	inorder(root);	
	cout<<"postorder display is"<<endl;
	postorder(root);
	cout<<"enter the element to be searched"<<endl;
	int s;
	cin>>s;
	if(search(root,s)==1)
	{
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	cout<<"Height is :"<<height(root);
}
