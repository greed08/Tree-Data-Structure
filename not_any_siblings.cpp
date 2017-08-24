#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  char data;
  struct node *left,*right;
}Node;
Node *newNode(char key)
{
  Node *temp=(Node *)malloc(sizeof(Node));
  temp->data=key+48;
  temp->left=temp->right=NULL;
  return temp;
}
void print_nodes_withnosiblings(Node *root)
{
  if(root)
  {
    print_nodes_withnosiblings(root->left);
    if((root->left!=NULL&&root->right==NULL))
    cout<<root->left->data<<",";
    if(root->right!=NULL&&root->left==NULL)
    cout<<root->right->data<<",";
    print_nodes_withnosiblings(root->right);
  }
}
int main()
{
  // Let us create binary tree given in the above example
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);;
  print_nodes_withnosiblings(root);
}
