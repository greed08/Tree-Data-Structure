#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left,*right;
};
Node *newNode(int key)
{
  Node *root=(Node *)malloc(sizeof(Node));
  root->data=key;
  root->left=root->right=NULL;
  return root;
}
void print_nodes(Node *root,int k,int ver)
{
  if(root==NULL)
  return;
  if(ver==k)
  cout<<root->data<<",";
   print_nodes(root->left,k,ver+1);
  print_nodes(root->right,k,ver+1);
}
int main()
{
  int k;
  int ver=0;
 Node *root = newNode(1);
 root->left        = newNode(2);
 root->right       = newNode(3);
 root->left->left  = newNode(4);
 root->left->right = newNode(5);
 root->right->left = newNode(8);
 cin>>k;
 print_nodes(root,k,ver);

}
