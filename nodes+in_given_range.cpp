#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *buildtree(Node *root,int key)
{
  if(root==NULL)
  {
    root=(Node *)malloc(sizeof(Node));
    root->data=key;
    root->left=root->right=NULL;

  }
  else
  {
    if(key<root->data)
    root->left=buildtree(root->left,key);
    else if(key>root->data)
    root->right=buildtree(root->right,key);
  }
  return root;
}
void inorder(Node *root)
{
  if(root==NULL)
  return;
  else{
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
  }

}
void print_inrange(Node *root,int k1,int k2)
{
  if(root==NULL)
  return ;
  if(k1<root->data)
  print_inrange(root->left,k1,k2);
  if(k1<=root->data&&k2>=root->data)
  {
    cout<<root->data<<",";
  }
  if(k2>root->data)
  print_inrange(root->right,k1,k2);
}
int main()
{
  int n;
  cin>>n;int a;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  int k1,k2;
  cin>>k1>>k2;
  print_inrange(root,k1,k2);
  //inorder(root);
}
