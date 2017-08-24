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

Node * find_lca(Node *root,int n1,int n2)
{
  if(root==NULL)
  return NULL;
  if(root->data==n1||root->data==n2)
  return root;
  Node *left_lca=find_lca(root->left,n1,n2);
  Node *right_lca=find_lca(root->right,n2,n2);
  if(left_lca&&right_lca)
  return root;
  return (left_lca!=NULL)?left_lca:right_lca;

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
  Node * root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->right->left = newNode(6);
   root->right->right = newNode(7);

  //inorder(root);
cout<<find_lca(root,4,6)->data<<"\n";
}
