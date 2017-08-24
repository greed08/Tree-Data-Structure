#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
  int depth;
}Node;
Node *newnode(int key)
{
  Node *node=(Node *)malloc(sizeof(Node));
  node->data=key;
  node->left=node->right;
  return node;
}
int print_depth(Node *root)
{
  if(root==NULL)
  return 1000;

 if(root->left==NULL && root->right==NULL) return 1;
  if(root)
  {
  return min(print_depth(root->left),print_depth(root->right))+1;
  }

}
int main()
{
  int depth=0;
  Node *root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  cout<<print_depth(root);

}
