#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left,*right;
  Node(int key)
  {
    data=key;
    left=right=NULL;

  }
};
int search(int in[],int val,int s)
{
  int ans;
  for(int i=0;i<=s;i++)
  {
    if(in[i]==val)
   return i;
  }
}
Node  *builttree(int in[],int post[],int low,int high)
{
  int s=high;
  if(low>high)
  return NULL;
  static int preindex=0;
  Node *root=new Node(post[preindex++]);
  if(low==high)
  return root;
  int index=search(in,root->data,s);
  root->right=builttree(in,post,index+1,high);
  root->left=builttree(in,post,low,index-1);

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
 int n;
 cin>>n;
 int in[n];
 int post[n];
 Node *root=NULL;
 for(int i=0;i<n;i++)
 {
   cin>>in[i];
 }
 for(int i=n-1;i>=0;i--)
 {
   cin>>post[i];
 }
root=builttree(in,post,0,n-1);
inorder(root);

}
