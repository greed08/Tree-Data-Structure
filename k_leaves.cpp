#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int a)
{
  Node *root=(Node *)malloc(sizeof(Node));
  root->data=a;
  root->left=root->right=NULL;
  return root;
}
int num_ans(Node *root,int k)
{
  if(root==NULL)
  return 0;
  if(root->left==NULL&&root->right==NULL)
  return 1;
   int k1;
   k1=num_ans(root->left,k)+num_ans(root->right,k);
   if(k1==k)
   {
     cout<<root->data<<",";
   }
  return k1;
}
int main()
{
  int k2;
Node *root = newNode(1);
      root->left        = newNode(2);
      root->right       = newNode(4);
      root->left->left  = newNode(5);
      root->left->right = newNode(6);
      root->left->left->left  = newNode(9);
      root->left->left->right  = newNode(10);
      root->right->right = newNode(8);
      root->right->left  = newNode(7);
      root->right->left->left  = newNode(11);
      root->right->left->right  = newNode(12);

    k2=num_ans(root, 2);
cout<<"Hr"<<k2<<"\n";
      return 0;
}
