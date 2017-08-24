#include<bits/stdc++.h>
using namespace std;

int n1,n2;
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
  else
  {
    if(a<root->data)
    root->left=buildtree(root->left,a);
    if(a>root->data)
    root->right=buildtree(root->right,a);
  }
  return root;
}
void inorder1(Node *root,vector<int> &a1)
{
  if(root)
  {
    inorder1(root->left,a1);
    a1.push_back(root->data);
    inorder1(root->right,a1);
  }
}
void inorder2(Node *root,vector<int> &a2)
{
  if(root)
  {
    inorder2(root->left,a2);
    a2.push_back(root->data);
    inorder2(root->right,a2);
  }
}
void find(vector<int> &a1,vector<int> &a2)
{
  int i=0,j=0;
  while(i<n1||j<n2)
  {
  if(a1[i]<a2[j])
  {
    i++;
  }
  else if(a1[i]>a2[j])
  {
    j++;

  }
  else
  {
    cout<<a1[i++]<<",";
    j++;

  }
}
}

int main()
{
  vector<int> ar1;
  vector<int> ar2;
int a1;
int a2;
  cin>>n1;
  Node *root1=NULL,*root2=NULL;
  for(int i=0;i<n1;i++)
  {
    cin>>a1;
    root1=buildtree(root1,a1);
  }
  cin>>n2;
  for(int i=0;i<n2;i++)
  {
    cin>>a2;
    root2=buildtree(root2,a2);

  }
  inorder1(root1,ar1);
  inorder2(root2,ar2);
//  for(int i=0;i<ar1.size();i++)
  //{
    //cout<<ar1[i]<<",";
  //}
 //cout<<"Inorder for first :"<<"\n";
  find(ar1,ar2);
}
