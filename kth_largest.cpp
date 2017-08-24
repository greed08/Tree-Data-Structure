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

  }
  else
  {
    if(a<root->data)
    {
      root->left=buildtree(root->left,a);

    }
    else if(a>root->data)
    {
      root->right=buildtree(root->right,a);
    }

  }
  return root;
}
Node *inorder_decre(Node *root,int k,int &c)
{

  if(root==NULL||c>k)
  return NULL ;

    inorder_decre(root->right,k,c);
    c++;
    //cout<<c;
    if(c==k)
     {
      return root;

     }
    inorder_decre(root->left,k,c);


}
int main()
{
  int c=0;
  int n;int a;int k;
  cin>>n;Node * ans;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  cout<<"Enter kth"<<"\n";
  cin>>k;
  ans=inorder_decre(root,k,c);
  cout<<ans->data<<"\n";
}
