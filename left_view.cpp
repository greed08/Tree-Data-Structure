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
void leftView(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int s=q.size();
    bool flag=false;
    Node *ans=NULL;
    for(int i=0;i<s;i++)
    {
      Node *temp=q.front();
      q.pop();
      if(!flag)
      {
        ans=temp;
        flag=true;

      }


      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);

    }
    cout<<ans->data<<",";
    ans=NULL;
    flag=false;
  }
}
int main()
{
      Node *root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);
      root->right->left = newNode(6);
      root->right->right = newNode(7);
      root->right->left->right = newNode(8);
      leftView(root);
}
