#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int a)
{
  Node *new_Node=(Node*)malloc(sizeof(Node));
  new_Node->data=a;
  new_Node->left=new_Node->right=NULL;
  return new_Node;
}
Node *buildtree(Node *root,int a)
{
  if(root==NULL)
  return newNode(a);
  else if(a<=root->data)
  {
    root->left=buildtree(root->left,a);
  }
  else
  root->right=buildtree(root->right,a);
  return root;
}
int height(Node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  else
  {
    return 1+max(height(root->left),height(root->right));
  }
}
int main()
{
  int n;int a;int h;
  scanf("%d",&n);
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
 h=height(root);
 cout<<"Height of tree is :"<<h<<"\n";
}
