#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int key)
{
  Node *temp=(Node *)malloc(sizeof(Node));
  temp->data=key;
  temp->left=temp->right;
  return temp;
}
int sum(Node *root)
{
  if(root==NULL)
  return 0;
  else
  return sum(root->left)+root->data+sum(root->right);
}
Node *construct_sumtree(Node *root)
{
  int l,r;
  if(root==NULL)
  return NULL;
  if(root->left==NULL&&root->right==NULL)
  root->data=0;
  l=sum(root->left);
  r=sum(root->right);
  root->data=l+r;
  root->left=construct_sumtree(root->left);
  root->right=construct_sumtree(root->right);
  return root;
}
void inorder(Node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
  }
}
int main()
{
  Node *root=newNode(10);
  root->left=newNode(-2);
  root->right=newNode(6);
  root->left->left=newNode(8);
  root->left->right=newNode(-4);
  root->right->left=newNode(7);
  root->right->right=newNode(5);
  root=construct_sumtree(root);
  inorder(root);
}
