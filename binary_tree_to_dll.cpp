#include<bits/stdc++.h>
using namespace  std;
struct Node
{
  int data;
  Node *left,*right;
  Node *next,*prev;
  Node (int key)
  {
    data=key;
    left=right=NULL;
    next=prev=NULL;
  }

};
Node  *builtdll(Node *root)
{
  static Node *pr=NULL;
  if(root)
  {
    builtdll(root->left);
    if(pr)
    {
      pr->next=root;
      root->prev=pr;
      root->next=NULL;
      pr=root;
    }
    else
    {
      root->prev=pr;
      pr=root;}
    builtdll(root->right);
  }
  return root;
}

Node *leftmost(Node *root)
{
  Node *curr=root;
  if(root->left)
  curr=leftmost(root->left);
  return curr;
}
void display(Node *root)
{
  if(root)
  {
    while(root)
    {
      cout<<root->data<<" ";
      root=root->next;
    }
  }
}
int main()
{
  Node *root=new Node(10);
  root->left=new Node(12);
  root->left->left=new Node(25);
  root->left->right=new Node(30);
  root->right=new Node(15);
  root->right->left=new Node(36);
  //inorder(root);
  root=builtdll(root);
  root=leftmost(root);
  display(root);
}
