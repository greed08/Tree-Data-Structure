#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node *left,*right,*nextRight;
  Node(int key)
  {
    data=key;
    left=right=NULL;
    nextRight=NULL;
  }
};

Node *set_next(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int s=q.size();
    Node *prev=NULL;
    for(int i=0;i<s;i++)
    {
      Node *temp=q.front();
      q.pop();
      if(prev)
      {
        prev->nextRight=temp;
        temp->nextRight=NULL;
        prev=temp;
      }
      else
      {
        prev=temp;
        temp->nextRight=NULL;
      }
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
    }
  }
  return root;
}

void inorder(Node *root)
{
 if(root)
 {
   inorder(root->left);

   cout<<"address of root :"<<root <<": "<<root->data<<" "<<"next :";
 if(root->nextRight!=NULL)
 cout<<root->nextRight->data<<",";
 else
 cout<<"-1"<<",";
   inorder(root->right);
 }
}
int main()
{
Node *root = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root=set_next(root);
    inorder(root);
}
