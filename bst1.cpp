#include<iostream>
//#include<stdlib.h>
#include<queue>
using namespace std;
#include<climits>

struct Bst{
	int data;
	Bst* left;
	Bst* right;
};

Bst* create(int data)
{
	Bst* temp=new Bst();
	temp->data=data;
	return temp;
}

Bst* insert(Bst* root,int data)
{
	if(root==NULL)
	{
		root=create(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

int search(Bst* root,int data)
{
	if(root==NULL)
		return 0;
	else if(root->data==data)
		return 1;
	else if(data<root->data)
		return search(root->left,data);
	else
	    return search(root->right,data);
}

int min(Bst* root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}

int max(Bst* root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root->data;
}


int height(Bst* root)
{
	int hl,hr,max;
	if(root==NULL)
		return -1;
	hl=height(root->left);
	hr=height(root->right);
	max=((hl>=hr)?hl:hr)+1;
	return max;
	/*if(root==NULL)
		return -1;
	else if(root->left==NULL && root->right==NULL)       //wrong
		return max;
	else if(root->left!=NULL)
		{
			h1++;
			return height(root->left);
		}
	else if(root->right!=NULL)
		{
			h2++;
		    return height(root->right);
		}
	max=((h1>h2)?h1:h2)+1;*/
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
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);
		q.pop();
		cout<<"\n";
	}
}

void preorder(Bst* root)
{
	if(root==NULL)
		return;
	cout<<"  "<<root->data;
	preorder(root->left);
	preorder(root->right);
}

void inorder(Bst* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<"  "<<root->data;
	inorder(root->right);
}

void postorder(Bst* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<"  "<<root->data;
}

bool issubtreeless(Bst* root,int value)
{
	if(root==NULL)
		return true;
	if(root->data<=value&&issubtreeless(root->left,value)&&issubtreeless(root->right,value))
		return true;
	else 
		return false;
}

bool issubtreegreat(Bst* root,int value)
{
	if(root==NULL)
		return true;
	if(root->data>value&&issubtreegreat(root->left,value)&&issubtreegreat(root->right,value))
		return true;
	else 
		return false;
}

bool checkBT1(Bst* root)
{
	if(root==NULL)
		return true;
	if(issubtreeless(root->left,root->data)&&issubtreegreat(root->right,root->data)&&checkBT1(root->left)&&checkBT1(root->right))
		return true;
	else 
		return false;
	
}

bool checkBT2(Bst* root,int min,int max)
{
	if(root==NULL)
		true;
	if(root->data>min&&root->data<max)
		{
			if(checkBT2(root->left,min,root->data)&&checkBT2(root->right,root->data,max))
			return true;
		    else
			return false;
	    }
}

bool checkBT3(Bst* root)
{
	if(root==NULL)
		return true;
	if(root->data>=max(root->left)&&root->data<min(root->right))
	{
		if(checkBT3(root->left)&&checkBT3(root->right))
			return true;
	}
	else
		return false;

}

int d=INT_MIN;


bool checkBT4(Bst* root)
{
	bool val1,val2;
	if(root==NULL)
		return true;
	val1=checkBT4(root->left);
	if(d>root->data)
		return false;
	//else return true;
	d=root->data;
	val2=checkBT4(root->right);
	if(val1&&val2)
		return true;
	else
		return false;

	
}

bool checkBT5(Bst* root,int min,int max)
{
	if(root==NULL)
		return true;
	if(root->data<=min||root->data>max)
		return false;
	//else return true;
	return (checkBT5(root->left,min,root->data)&&checkBT5(root->right,root->data,max));
}

Bst* Delete(Bst* root,int data)
{
	int mindata;
	Bst* temp;
	if(root==NULL)
		return NULL;
	else if(root->data==data)
	{
		if(root->left==NULL&& root->right==NULL)
			{
				delete(root);
				root=NULL;
				//return root;
			}
		else if(root->left==NULL)
                {
                	temp=root;
                	root=root->right;
                	delete(temp);
                	//return root;
                }
	    else if(root->right==NULL)
	    	    {
	    	    	temp=root;
	    	    	root=root->left;
	    	    	delete(temp);
	    	    	//return root;
	    	    }
	    else
	    	{
	    		mindata=min(root->right);
	    		root->right=Delete(root->right,mindata);
                root->data=mindata;
	        }
	}

	else if(data>root->data)
		
			root->right=Delete(root->right,data);
		
	else if(data<root->data)
		
			root->left=Delete(root->left,data);
	  
	return root;
}

int main()
{
	Bst* root=NULL;
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,20);
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,21);
	root=insert(root,28);
	root=Delete(root,20);

	//cout<<search(root,5);
	//cout<<search(root,25);
	//cout<<search(root,10);
	//cout<<search(root,18);
	//cout<<"\n"<<min(root);
	//cout<<"\n"<<max(root);
	//cout<<"\n"<<height(root);
	leveltraverse(root);
	//preorder(root);
	//bool res=checkBT(root,INT_MIN,INT_MAX);
	//delete(root,10);
	cout<<"\n"<<checkBT4(root)<<"\n";
}