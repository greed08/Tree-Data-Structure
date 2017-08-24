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
void spiral_level(Node *root)
{
  if(root==NULL)
  return;
  stack<Node *> s1;
  stack<Node *> s2;
  if(root)
  s1.push(root);
  while(!s1.empty()||!s2.empty())
  {
    while(!s1.empty())
    {
      Node *temp=s1.top();
      s1.pop();
      cout<<temp->data<<",";

      if(temp->right)
      s2.push(temp->right);
      if(temp->left)
      s2.push(temp->left);
    }
    while(!s2.empty())
    {
      Node *temp=s2.top();
        s2.pop();
      cout<<temp->data<<",";

      if(temp->left)
      s1.push(temp->left);
      if(temp->right)
      s1.push(temp->right);
    }
  }
}
int main()
{
  Node *root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(7);
  root->left->right=newNode(6);
  root->right->left=newNode(5);
  root->right->right=newNode(4);
  spiral_level(root);
}
