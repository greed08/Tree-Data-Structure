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
void reverse_level(Node *root)
{
  queue<Node *> q;
  stack<Node *> s;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    Node *temp=q.front();
    q.pop();
    s.push(temp);
    if(temp->right)
    q.push(temp->right);
    if(temp->left)
    q.push(temp->left);
  }
  while(!s.empty())
  {
    cout<<s.top()->data<<",";
    s.pop();
  }
}
int main()
{
Node *root = newNode(1);
   root->left        = newNode(2);
   root->right       = newNode(3);
   root->left->left  = newNode(4);
   root->left->right = newNode(5);
   root->right->left  = newNode(6);
   root->right->right = newNode(7);
   reverse_level(root);
}
