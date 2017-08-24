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
  temp->left=temp->right;
  return temp;
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
int max_diff(Node *root,int &res)
{
  if(root==NULL)
  return INT_MAX;
  int val;
  if(root->left==NULL&&root->right==NULL)
  return root->data;
  val=min(max_diff(root->left,res),max_diff(root->right,res));
  res=max(res,root->data-val);
return min(val,root->data);


}
int main()
{
  int res=INT_MIN;int min_val;
  Node *root=newNode(8);
  root->left=newNode(3);
  root->right=newNode(10);
  root->left->left=newNode(1);
  root->left->right=newNode(6);
  root->left->right->left=newNode(4);
  root->left->right->right=newNode(7);
  root->right->right=newNode(14);
  root->right->right->left=newNode(13);
  //inorder(root);
min_val=  max_diff(root,res);
  cout<<res<<"\n";
}
