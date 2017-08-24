#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newnode(int key)
{
  Node *root=(Node *)malloc(sizeof(Node));
  root->data=key;
  root->left=root->right=NULL;
  return root;
}
int count_nodes(Node *root)
{
  if(root==NULL)
  return 0;
  else
  return count_nodes(root->left)+count_nodes(root->right)+1;
}

bool is_complete_btree(Node *root,int index,int num_nodes)
{
  if(root==NULL)
  return true;
  if(index>=num_nodes)
  return false;
  else
  return is_complete_btree(root->left,index*2+1,num_nodes)&&is_complete_btree(root->right,index*2+2,num_nodes);
}
bool is_heap(Node *root)
{
if(root->left==NULL&&root->right==NULL)
return true;
  if(root->right==NULL)
  {
    return (root->data>=root->left->data);
  }
  else
  {
    if(root->data>=root->left->data&&root->data>=root->right->data)
   return  is_heap(root->left)&&is_heap(root->right);
   else
   return false;
  }
}
int main()
{
Node *root=newnode(97);
root->left=newnode(46);
root->right=newnode(37);
root->left->left=newnode(12);
root->left->right=newnode(3);
root->left->right->left=newnode(2);
root->left->right->right=newnode(4);
root->right->left=newnode(7);
root->right->right=newnode(31);
  int num=count_nodes(root);
  if(is_complete_btree(root,0,num)&&is_heap(root))
  {
    cout<<"binary tree is a heap"<<"\n";

  }
  else
  cout<<"Not a  heap"<<"\n";

}
