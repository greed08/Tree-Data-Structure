#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  int hd;
  Node *left,*right;
   Node(int key)
  {
    data=key;
    hd=INT_MAX;
    left=right=NULL;
    }
};
void bottom_view(Node *root)
{
  if(root==NULL)
  return;
  int hd=0;
  queue<Node *> q;
  root->hd=hd;
  map<int,int> m;
  q.push(root);
  while(!q.empty())
  {

    Node *temp=q.front();
    q.pop();
    hd=temp->hd;
    m[hd]=temp->data;
    if(temp->left)
    {
      temp->left->hd=hd-1;
      q.push(temp->left);
    }
    if(temp->right)
    {
      temp->right->hd=hd+1;
      q.push(temp->right);
    }
  }
  map<int,int> :: iterator it;
  for(it = m.begin();it!=m.end();++it)
  cout<<it->second<<",";

}
int main()
{
  Node *root = new Node(20);
   root->left = new Node(8);
   root->right = new Node(22);
   root->left->left = new Node(5);
   root->left->right = new Node(3);
   root->right->left = new Node(4);
   root->right->right = new Node(25);
   root->left->right->left = new Node(10);
   root->left->right->right = new Node(14);
   bottom_view(root);
}
