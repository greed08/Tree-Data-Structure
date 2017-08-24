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
    {
      root->left=buildtree(root->left,key);

    }
    else
    if(key>root->data)
    {
      root->right=buildtree(root->right,key);
    }
  }
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
Node *lca(Node *root,int n1,int n2)
{
  if(root==NULL)
  return NULL;
  if(root->data>n1&&root->data>n2)
  return lca(root->left,n1,n2);
  else if(root->data<n1&&root->data<n2)
  return lca(root->right,n1,n2);
  return root;
}
int main()
{
  int n;
  cin>>n;int a;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
  root=  buildtree(root,a);
  }
  int n1,n2;
  cin>>n1>>n2;
//  inorder(root);
root=lca(root,n1,n2);
cout<<root->data<<"\n";
}
