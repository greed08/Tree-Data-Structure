#include<bits/stdc++.h>
using namespace std;
typedef struct node{
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
  else{
    if(key<root->data)
    {
      root->left=buildtree(root->left,key);
    }
    else if(key>root->data)
    {
      root->right=buildtree(root->right,key);
    }

  }
  return root;
}
void inorder_modify(Node *root,int &sum)
{
  if(root)
  {
    inorder_modify(root->right,sum);
    sum+=root->data;
    root->data=sum;
    inorder_modify(root->left,sum);

  }
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
  int n;int a;
  int sum=0;
  cin>>n;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  inorder_modify(root,sum);
  inorder(root);
}
