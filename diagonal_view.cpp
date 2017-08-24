#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int key)
{
  Node *temp=(Node *)malloc(sizeof(Node));
  temp->data=key;
  temp->left=temp->right=NULL;
  return temp;
}
void print_diagonal(Node *root,int hori,map<int,vector<int> > &m)
{
  if(root==NULL)
  return;
  m[hori].push_back(root->data);
  print_diagonal(root->left,hori+1,m);
  print_diagonal(root->right,hori,m);

}
int main()
{

  int hori=0;
  Node *root=newNode(8);
  root->left=newNode(3);
  root->right=newNode(10);
  root->left->left=newNode(1);
  root->left->right=newNode(6);
  root->left->right->left=newNode(4);
  root->left->right->right=newNode(7);
  root->right->right=newNode(14);
  root->right->right->left=newNode(13);
    map<int, vector< int > > m;
  print_diagonal(root,hori,m);
  map<int,vector<int> > :: iterator it;
  for(it=m.begin();it!=m.end();it++)
  {
    for(int i=0;i<it->second.size();i++)
    cout<<it->second[i]<<",";
    cout<<"\n";
  }


}
