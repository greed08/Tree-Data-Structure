#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newnode(int key)
{
  Node *node=(Node *)malloc(sizeof(Node));
  node->data=key;
  node->left=node->right=NULL;
  return node;
}
void inorder(Node *root,vector<int> &vp)
{
  if(root)
  {
    inorder(root->left,vp);
    vp.push_back(root->data);
    inorder(root->right,vp);
  }
}
void build_bst(Node *root,vector<int> &vp,int &i)
{


  if(root)
  {
    build_bst(root->left,vp,i);

    root->data=vp[i];
    (i)++;
    build_bst(root->right,vp,i);
  }


}
void inorder_bst(Node *root)
{
  if(root)
  {
    inorder_bst(root->left);
    cout<<root->data<<",";
    inorder_bst(root->right);
  }
}
int main()
{
  vector<int> vp;int i=0;
  Node *root=newnode(10);
  root->left=newnode(30);
  root->right=newnode(15);
  root->left->left=newnode(20);
  root->right->right=newnode(5);
  inorder(root,vp);
  sort(vp.begin(),vp.end());
  build_bst(root,vp,i);
  inorder_bst(root);

}
