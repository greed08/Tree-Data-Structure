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
void dead_end(Node *root,vector<int> &v)
{
 if(root==NULL)
 return;
  if(root->left==NULL&&root->right==NULL)
  v.push_back(root->data);
  dead_end(root->left,v);
  dead_end(root->right,v);


}

int main()
{
  vector<int> v;
   unordered_set<int> s;
  int c=0;
  int n;int a;int k;
  cin>>n;Node * ans;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    root=buildtree(root,a);
  }
   dead_end(root,v);
   for(int i=0;i<v.size();i++)
 {
    s.insert(v[i]+1);
    s.insert(v[i]-1);
 }

}
