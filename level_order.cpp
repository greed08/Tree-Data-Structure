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
    root=(Node*)malloc(sizeof(Node));
    root->data=a;
    root->left=root->right=NULL;

  }
  else if(a<=root->data)

  {
   root->left=buildtree(root->left,a);


  }
  else if(a>root->data)
  {
    root->right=buildtree(root->right,a);
  }
  return root;
}
void level(Node *root)
{
  queue<Node*> q;

  if(root)
  {
  q.push(root);
}
  while(!q.empty())
  {
   Node *temp=q.front();

    cout<<temp->data<<" ";
    q.pop();

    if(temp->left!=NULL)
    q.push(temp->left);
    else
    if(temp->right!=NULL)
    q.push(temp->right);
  }
}
void inorder(Node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
  }
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
  cout<<"Inorder"<<"\n";
  //inorder(root);
  level(root);
}
