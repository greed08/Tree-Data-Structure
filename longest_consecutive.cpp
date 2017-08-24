#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int a)
{
Node *  root=(Node*)malloc(sizeof(Node));
  root->data=a;
  root->left=root->right=NULL;
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
void largest_conse(Node *root,int val,int &res,int currlength)
{

  if(root==NULL)
  return ;
  if(root->data==val)
  currlength++;
  else
  currlength=1;
  res=max(currlength,res);
  largest_conse(root->left,root->data+1,res,currlength);
  largest_conse(root->right,root->data+1,res,currlength);

}
int main()
{
   int res=0;
    Node* root = newNode(6);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->right = newNode(10);
    root->right->right->right = newNode(11);
    //inorder(root);
    largest_conse(root,root->data,res,1);
    cout<<res<<"\n";

}
