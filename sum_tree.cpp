#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
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
int sum1(Node *root)
{
  if(root==NULL)
  return 0;
  else
  return sum1(root->left)+root->data+sum1(root->right);

}
bool is_sumtree(Node *node)
{
int l,r;
if(node==NULL||node->left==NULL&&node->right==NULL)
return true;
l=sum1(node->left);
r=sum1(node->right);
if(node->data==l+r&&is_sumtree(node->left)&&is_sumtree(node->right))
return true;
return false;


}

int main()
{
  Node *root  = newNode(26);
   root->left         = newNode(10);
   root->right        = newNode(3);
   root->left->left   = newNode(4);
   root->left->right  = newNode(6);
   root->right->right = newNode(3);
   /*Node *root=newNode(5);
   root->left=newNode(3);
   root->right=newNode(2);*/
   if(is_sumtree(root))
   cout<<"It is a sum tree"<<"\n";
   else
   cout<<"Not a sum tree"<<"\n";
}
