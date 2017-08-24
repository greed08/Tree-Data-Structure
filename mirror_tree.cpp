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
Node *mirror(Node *root)
{
  if(root==NULL)
  return root ;
  if(root->left==NULL&&root->right==NULL)
  return root;
  Node *l=mirror(root->left);
  Node *r=mirror(root->right);
 swap(*l,*r);
  return root;
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
int main()
{
  Node *root=new Node(1);
  root->left=new Node(3);
  root->right=new Node(2);
  root->left->left=new Node(7);
  root->left->right=new Node(6);
  root->right->left=new Node(5);
  root->right->right=new Node(4);
  root->right->right->left=new Node(9);
  root->right->right->right=new Node(8);

  //mirror(root->right);
  mirror(root);
  //mirror(root->left);

  inorder(root);
}
