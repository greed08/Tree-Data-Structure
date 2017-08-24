#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *buildtree(Node *root,int a)
{
  if(root==NULL)
  {
    root=(Node *)malloc(sizeof(Node));
    root->data=a;
    root->left=root->right=NULL;
  }
  else if(a<root->data)
  {
    root->left=buildtree(root->left,a);
  }
  else if(a>root->data)
  {
    root->right=buildtree(root->right,a);
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
Node *minVal(Node *node)
{
  Node *current=node;
  while(current->left!=NULL)
  current=current->left;
  return current;
}
Node *deletebst(Node *root,int a)
{
  if(root==NULL)
  return root;
  if(a<root->data)
  root->left=deletebst(root->left,a);
  else if(a>root->data)
  root->right=deletebst(root->right,a);
else
{
 if(root->left==NULL)
  {
    Node *temp=root->right;
    free(root);
    return temp;
  }
  else if(root->right==NULL)
  {
    Node *temp=root->left;
    free(temp);
    return temp;
  }
  Node *temp=minVal(root->right);
  root->data=temp->data;
  root->right=deletebst(root->right,temp->data);
}
return root;
}
int main()
{
  int n;
  cin>>n;int d1;
  int a;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  inorder(root);
  cout<<"\n";
  cout<<"Enter the data to be deleted"<<"\n";
  cin>>d1;
  deletebst(root,d1);
  inorder(root);
}
