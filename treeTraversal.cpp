#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node* makeTree(Node* root,int a[],int n)
{
	root -> data = *a;
	root -> left = NULL;
	root -> right = NULL;
	for(int i=1;i<n;i++)
	{
		Node* node = root;
		Node* newNode = (Node*)malloc(sizeof(struct Node));
		while(node != NULL)
		{
			if(*(a + i) < node -> data)
			{
				if(node -> left == NULL)
				{
					newNode -> data = *(a+i);
					newNode -> left = NULL;
					newNode -> right = NULL;
					node -> left = newNode;
					break;
				}
				else
					node = node -> left;
			}
			else
			{
				if(node -> right == NULL)
				{
					newNode -> data = *(a+i);
					newNode -> left = NULL;
					newNode -> right = NULL;
					node -> right = newNode;
					break;
				}
				else
					node = node -> right;
			}
		}
	}
	return root;
}

void printInOrderTree(Node* root)
{
	if(root == NULL)
		return;
	printInOrderTree(root -> left);
	cout<<root->data<<" ";
	printInOrderTree(root -> right);	
}

void printPreOrderTree(Node* root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";	
	printPreOrderTree(root -> left);
	printPreOrderTree(root -> right);	
}

void printPostOrderTree(Node* root)
{
	if(root == NULL)
		return;
	printPostOrderTree(root -> left);
	printPostOrderTree(root -> right);
	cout<<root->data<<" ";	
}

int main()
{
	Node* root = (Node*)malloc(sizeof(struct Node));
	int n,i,arr[1000];
	cout<<"Enter number of nodes : ";
	cin>>n;
	cout<<"\nEnter the nodes : ";
	for(i=0;i<n;i++)
		cin>>*(arr + i);
		
	root = makeTree(root,arr,n);
	
	cout<<"\nINORDER TRAVERSAL : ";
	printInOrderTree(root);
	cout<<"\nPREORDER TRAVERSAL : ";
	printPreOrderTree(root);
	cout<<"\nPOSTORDER TRAVERSAL : ";
	printPostOrderTree(root);
	
	return 0;
}
