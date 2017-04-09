#include<iostream>
#include<queue>
//#include<stdlib.h>

using namespace std;

struct Bst{
	int data;
	Bst* left;
	Bst* right;
};

int height(Bst* root)
{
	int hl,hr,max;
	if(root==NULL)
		return -1;
	hl=height(root->left);
	hr=height(root->right);
	max=((hl>=hr)?hl:hr)+1;
	return max;
}

Bst* create(int data)
{
	Bst* temp=new Bst();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

Bst* rotateright(Bst* root)
{
	Bst* newroot=root->left;
	root->left=newroot->right;
	newroot->right=root;
	
	return newroot;
}

Bst* rotateleft(Bst* root)
{
	Bst* newroot=root->right;
	root->right=newroot->left;
	newroot->left=root;
	
	return newroot;
}

Bst* avlinsert(Bst* root,int data)
{
	if(root==NULL)
	{
		root=create(data);
	}
	else if(data<=root->data)
	{
		root->left=avlinsert(root->left,data);
	}
	else
	{
		root->right=avlinsert(root->right,data);
	}
	int balance;
	balance=height(root->left)-height(root->right);
	//cout<<balance<<"\n";
	if(balance>1)
	{
		if(height(root->left->left)>=height(root->left->right))
			return rotateright(root);
		else
			{
				root->left=rotateleft(root->left);
                return rotateright(root);
            }
	}
	if(balance<-1)
	{
		if(height(root->right->right)>=height(root->right->left))
			return rotateleft(root);
		else
			{
				root->right=rotateright(root->right);
                return rotateleft(root);
            }
	}
	return root;
}

void leveltraverse(Bst* root)
{
	queue<Bst*> q;
	Bst* current;
	if(root==NULL)
		return;
	q.push(root);
	while(!q.empty())
	{
		current=q.front();
		cout<<"\t"<<current->data;
		if(current->left!=NULL)
			{
				q.push(current->left);
				//cout<<"\n";
			}
		if(current->right!=NULL)
			{
				q.push(current->right);
				//cout<<"\n";
			}
		q.pop();
		
	}
}

Bst* Delete(Bst* root,int data)
{
	Bst* temp;
	int mindata;
	if(root==NULL)
		return NULL;
	if(data<root->data)
		root->left=Delete(root->left,data);
	else if(data>root->data)
		root->right=Delete(root->right,data);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			temp=root;
			free(temp);
			root=NULL;
		}
		if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			free(temp);
		}
		if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			mindata=min(root->right);
			root->data=mindata;
			root->right=Delete(root->right,mindata);
		}
	}
	if(root==NULL)
		return NULL;
	int balance;
	balance=height(root->left)-height(root->right);
	//cout<<balance<<"\n";
	if(balance>1)
	{
		if(height(root->left->left)>=height(root->left->right))
			return rotateright(root);
		else
			{
				root->left=rotateleft(root->left);
                return rotateright(root);
            }
	}
	if(balance<-1)
	{
		if(height(root->right->right)>=height(root->right->left))
			return rotateleft(root);
		else
			{
				root->right=rotateright(root->right);
                return rotateleft(root);
            }
	}
	return root;
}

int main()
{
	Bst* root=NULL;
	root=avlinsert(root,10);
	root=avlinsert(root,5);
	root=avlinsert(root,15);
	root=avlinsert(root,-10);
	root=avlinsert(root,-5);
	//root=avlinsert(root,25);
	//root=avlinsert(root,28);
	leveltraverse(root);
}