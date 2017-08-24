#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;

};
Node *newnode(int key)
{
  Node *temp=(Node *)malloc(sizeof(Node));
  temp->data=key;
  temp->left=temp->right=NULL;
  return temp;
}
void print_tree(Node *root)
{
if(root)
{
  print_tree(root->left);
  cout<<root->data<<",";
  print_tree(root->right);
}
}
void leaf_at_same_level(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int s=q.size();
    for(int i=0;i<s;i++)
    {
      Node *curr=q.front();

      if(curr->left)
      q.push(curr->left);
      if(curr->right)
      q.push(curr->right);
      if(flag==false)
      {
      if(curr->left==NULL&&curr->right==NULL)
      {
        flag=true;

      }
    }
      q.pop();
    }
    cout<<"\n";
  }
}
int main()
{
  Node *root=newnode(1);
  root->left=newnode(2);
  root->left->left=newnode(3);
  root->left->right=newnode(4);
  root->left->left->left=newnode(5);
  root->right=newnode(6);
  root->right->left=newnode(7);
  root->right->right=newnode(8);
  root->right->right->left=newnode(9);
  //print_tree(root);
  leaf_at_same_level(root);

}
