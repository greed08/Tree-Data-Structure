#include<bits/stdc++.h>
using namespace std;
typedef struct node{
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
    return root;
  }
  else
  {
    if(a<root->data)
    root->left=buildtree(root->left,a);
    if(a>root->data)
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
Node *min_value(Node *root)
{
if(root->left==NULL&&root->right==NULL)
return root;
root=min_value(root->left);
}
int main()
 {
   int n;
   cin>>n;
   int a;
   Node *root=NULL;
   for(int i=0;i<n;i++)
   {
     cin>>a;
     root=buildtree(root,a);
   }
   root=min_value(root);
   cout<<root->data<<"\n";
 }
