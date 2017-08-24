#include<bits/stdc++.h>
using namespace std;
typedef struct node{
  int data;
  struct node *left,*right;
}Node;
Node *newnode(int a)
{
  Node *root=(Node *)malloc(sizeof(Node));
  root->data=a;
  root->left=root->right=NULL;
  return root;
}
bool path_sum_hai(Node *root,int sum)
{
  if(root==NULL)
  return (sum==0);
  bool ans=0;
  int subsum=sum-root->data;
  cout<<"Sum is :"<<"\n";
  cout<<subsum<<"\n";
  if(subsum==0&&root->left==NULL&&root->right==NULL)
  return 1;
  if(root->left)
  ans=ans||path_sum_hai(root->left,subsum);
  if(root->right)
ans=ans||  path_sum_hai(root->right,subsum);
return ans;
}
/* Driver program to test above functions*/
int main()
{

  int sum = 21;

  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);

  if(path_sum_hai(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);

}
