#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newnode(int key)
{
  Node *node=(Node *)malloc(sizeof(Node));
   node->data=key;
   node->left=node->right=NULL;
   return node;
}
void inorder(Node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
  }
}
void odd_even_level(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);

  int level=1;int sum_odd=0;int sum_even=0;
  while(!q.empty())
  {
    int size=q.size();
    for(int i=0;i<size;i++)
    {
      Node *temp=q.front();
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
      q.pop();
      if(level&1)
      sum_odd+=temp->data;

      else
      sum_even+=temp->data;
    }
    level++;
  }
  cout<<sum_odd-sum_even<<"\n";
}
int main()
{
  Node *root=newnode(10);
  root->left=newnode(20);
  root->right=newnode(30);
  root->left->left=newnode(40);
  root->left->right=newnode(60);
  odd_even_level(root);

}
