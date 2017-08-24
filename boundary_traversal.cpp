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
  temp->left=temp->right=NULL;
  return temp;

}
void printleaves(Node *root)
{
  if(root)
  {
    printleaves(root->left);
    if(!(root->left)&&!(root->right))\
    cout<<root->data<<",";
    printleaves(root->right);
  }
}
void printleft(Node *root)
{
  if(root)
  {
    if(root->left)
    {
      cout<<root->data<<",";
      printleft(root->left);
    }
    else if(root->right)
    {
      cout<<root->data<<",";
      printleft(root->right);
    }
  }
}
void printright(Node *root)
{
  if(root)
  {
    if(root->right)
    {
      printright(root->right);
      cout<<root->data<<",";

    }
    else if(root->left)
    {
      printright(root->left);
      cout<<root->data<<",";
    }
  }
}
int main()
{
Node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    if(root)
    {
      cout<<root->data<<",";
      printleft(root->left);
      printleaves(root->left);
      printleaves(root->right);
      printright(root->right);
    }
}
