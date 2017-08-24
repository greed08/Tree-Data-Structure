#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left,*right;
}Node;
  int n;
Node *newNode(int key)
{
  Node *temp=(Node *)malloc(sizeof(Node));
  temp->data=key;
  temp->left=temp->right=NULL;
  return temp;
}
int search_in(int in[],int val)
{
  for(int i=0;i<n;i++)
  if(in[i]==val){
  return i;

}
}
Node *tree_build(int in[],vector<int> &pre,int low,int high)
{

 if(low>high)
 return NULL;
Node * root=newNode(pre.back());
  pre.pop_back();
 int index=search_in(in,root->data);

 if(low==high)
 return root;
 root->left=tree_build(in,pre,low,index-1);
 root->right=tree_build(in,pre,index+1,high);

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
int main()
{

  cin>>n;
  int in[n];int a;
  vector<int> pre;
  Node *root;
  for(int i=0;i<n;i++)
  {
    cin>>in[i];
  }
  for(int i=0;i<n;i++)
  {
    cin>>a;
    pre.push_back(a);
  }
  reverse(pre.end(),pre.begin());
  root=tree_build(in,pre,0,n-1);
  inorder(root);
}
