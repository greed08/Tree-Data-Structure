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
void right_view(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int s=q.size();
    Node *ans=NULL;
    for(int i=0;i<s;i++)
    {
      Node *temp=q.front();
      q.pop();
      ans=temp;
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
    }
    cout<<ans->data<<",";
    ans=NULL;
  }
}
int main()
{
  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  root->right->left->right=new Node(8);
  right_view(root);
}
