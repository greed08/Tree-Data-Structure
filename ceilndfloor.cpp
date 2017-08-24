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
void floorndceil(Node *root,Node* &floor1,Node* &ceil1,int a)
{
  cout<<floor1;
  if(root==NULL)
  return;
  else if(root->data==a)
  {
    floor1=root;
    ceil1=root;
    cout<<"Equal mil gaya"<<"\n";
  }
  else if(a<root->data)
  {
    ceil1=root;
    cout<<"Chota hai"<<"\n";
    floorndceil(root->left,floor1,ceil1,a);
  }
  else if(a>root->data)
  {
    floor1=root;
    cout<<"bada hai"<<"\n";
    floorndceil(root->right,floor1,ceil1,a);
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
  int n;int a;int h;int a1;
  scanf("%d",&n);
  Node *root=NULL;
  int n1;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
  inorder(root);
  cout<<"\n";
  cin>>n1;
  cout<<"Enter the numbers whose floor and ceil is to be calculated"<<"\n";
  for(int i=0;i<n1;i++)
  {
    cin>>a1;
    Node *floor1=NULL; Node *ceil1=NULL;
    floorndceil(root,floor1,ceil1,a1);
    cout<<"Floor of "<<a1<<" is :"<<(floor1?floor1->data:-1)<<"\n";
    cout<<"Ceil of "<<a1<<" is :"<<(ceil1?ceil1->data:-1)<<"\n";
  }

}
