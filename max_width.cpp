#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left,*right;
  Node (int key)
  {
    data=key;
    left=right=NULL;
  }
};
void max_width(Node *root)
{
  int max_width=0;
  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int count=0;
    int s=q.size();
    for(int i=0;i<s;i++)
    {
      Node *temp=q.front();
      q.pop();
      if(temp)
      count++;
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
    }
    max_width=max(max_width,count);
    count=0;
  }
  return max_width;
}
int main()
{
Node *root = new Node(1);
 root->left        = new Node(2);
 root->right       = new Node(3);
 root->left->left  = new Node(4);
 root->left->right = new Node(5);
 root->right->right = new Node(8);
 root->right->right->left  = new Node(6);
 root->right->right->right  = new Node(7);
max_width(root);
}
