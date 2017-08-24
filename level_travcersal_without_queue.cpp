#include<bits/stdc++.h>
using namespace std;
typedef struct node{
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
int height(Node *root)
{
  if(root==NULL)
  return 0;
  else
  return 1+max(height(root->left),height(root->right));
}
void left_view(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  bool flag=false;
  while(!q.empty())
  {
    int s=q.size();
    int n=s;
    while(n--)
    {
      Node *temp=q.front();
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);

      if(flag&&n==s-1)
      cout<<temp->data<<",";
      
          q.pop();

    }
    flag=!flag;
  }
}
int main()
{
  Node *root=newNode(12);
  root->left=newNode(10);
  root->right=newNode(30);
  root->right->left=newNode(25);
  root->right->right=newNode(40);
  int h=height(root);

  left_view(root);

}
