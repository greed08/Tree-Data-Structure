#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newnode(int a)
{
 Node *  root=(Node *)malloc(sizeof(Node));
  root->data=a;
  root->left=root->right=NULL;
}
void sum(Node *root)
{
  queue<Node*> q;
int ans=0;int sum1=0;
  if(root)
  {
  q.push(root);
}
  while(!q.empty())
  {
   Node *temp=q.front();
   cout<<temp->data<<",";
    sum1+=temp->data;
    ans=max(ans,sum1);
    q.pop();

    if(temp->left!=NULL)
    q.push(temp->left);

     if(temp->right!=NULL)
    q.push(temp->right);
  }
  cout<<ans<<"\n";
}

int main()
{

  Node *root=newnode(4);
  root->left=newnode(2);
  root->left->left=newnode(-1);
  root->left->right=newnode(3);
  root->right=newnode(-5);
  root->right->left=newnode(6);
  root->right->left=newnode(-2);
  sum(root);

}
