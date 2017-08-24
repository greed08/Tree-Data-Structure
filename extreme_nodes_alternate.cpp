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
void alternate(Node *root)
{
  queue<Node *> q;
  if(root)
  q.push(root);
  bool flag=false;
  while(!q.empty())
  {
    int nodecount=q.size();
    int n=nodecount;
    while(n--)
    {
      Node *curr=q.front();
      if(curr->left)
      q.push(curr->left);
      if(curr->right)
      q.push(curr->right);
      if(flag&&n==nodecount-1)
      cout<<curr->data<<",";
      else if(!flag&&n==0)
      cout<<curr->data<<",";
    }
    flag=!flag;
  }

}
int main()
{
  Node* root = newNode(1);

   root->left = newNode(2);
   root->right = newNode(3);

   root->left->left  = newNode(4);
   root->left->right = newNode(5);
   root->right->right = newNode(7);

   root->left->left->left  = newNode(8);
   root->left->left->right  = newNode(9);
   root->left->right->left  = newNode(10);
   root->left->right->right  = newNode(11);
   root->right->right->left  = newNode(14);
   root->right->right->right  = newNode(15);

   root->left->left->left->left  = newNode(16);
   root->left->left->left->right  = newNode(17);
   root->right->right->right->right  = newNode(31);
   alternate(root);
}
