#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
  int height;
}Node;
int height(Node *root)
{
  if(root==NULL)
  return 0;
  else
  return root->height;
}
Node *leftrotate(Node *root)
{
  Node *t1=root->right;
  Node *t2=t1->left;
  t1->left=root;
  root->right=t1;
  root->height=1+max(height(root->left),height(root->right));
  t1->height=1+max(height(root->left),height(root->right));
  return t1;
}
Node *rightrotate(Node *root)
{
  Node *t1=root->left;
  Node *t2=t1->right;
  t1->right=root;
  root->left=t1;
  root->height=1+max(height(root->left),height(root->right));
  t1->height=1+max(height(root->left),height(root->right));
  return t1;
}

int get_marks(Node *root)
{
  if(root==NULL)
  return 0;
  else{
    return height(root->left)-height(root->right);
  }
}
Node *buildtree(Node *root,int key)
{
  int marks;
  if(root==NULL)
  {
  root=(Node *)malloc(sizeof(Node));
  root->data=key;
  root->left=root->right=NULL;
  return root;
  }
  if(key<root->data)
  {
    root->left=buildtree(root->left,key);
  }
  if(key>root->data)
  {
    root->right=buildtree(root->right,key);
  }
  else
  return root;
  root->height=1+max(height(root->left),height(root->right));
  marks=get_marks(root);
  if(marks<-1&&key>root->right->data)
  return leftrotate(root);
  if(marks>1&&key<root->left->data)
  return rightrotate(root);
  if(marks<-1&&key<root->right->data)
  {
    root->right=rightrotate(root->right);
    return leftrotate(root);

  }
  if(marks>1&&key>root->left->data)
  {
    root->left=leftrotate(root->left);
    return rightrotate(root);

  }
return root;

}
void preorder(Node *root)
{
  if(root)
  {
    cout<<root->data<<",";
    preorder(root->left);
    preorder(root->right);
  }
}
int main()
{
  int n;int a;int key1;
  cin>>n;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  cout<<"Enter the key to be inserted"<<"\n";
  cin>>key1;
  root=buildtree(root,key1);
  preorder(root);
}
