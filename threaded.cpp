#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
  bool isthread;
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
  else if(a<root->data)
  {
    root->left=buildtree(root->left,a);
  }
  else
  root->right=buildtree(root->right,a);
  return root;
}
void queue_inorder(Node *root,queue<Node *> &q)
{
  if(root)
  {
    queue_inorder(root->left,q);
    q.push(root);
    queue_inorder(root->right,q);
  }
}
void createThreaded(Node *root,queue<Node *> &q)
{
  if(root==NULL)
  return;
  if(root->left)
  {
cout<<"hererer"<<",";
  createThreaded(root->left,q);

}

  q.pop();

  if(root->right)
  createThreaded(root->right,q);
  else
  {
    root->right=q.front();
    root->isthread=true;
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
queue<Node *> q;
   //createThread(root,q);
   queue_inorder(root,q);
  createThreaded(root,q);
/*  while(!q.empty())
  {
    cout<<q.front()->data<<",";
    q.pop();
  }*/

}
