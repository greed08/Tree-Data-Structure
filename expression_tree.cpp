#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  char data;
  struct node *left,*right;
}Node;
bool isoperator(char op)
{
  if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^')
  return true;
  else
  return false;
}
void inorder(Node *root)
{
  if(root)
  {
    inorder(root->right);
    cout<<root->data;
    inorder(root->left);
  }
}
void preorder(Node *root)
{
  if(root)
  {
    cout<<root->data;
    preorder(root->right);

    preorder(root->left);
  }
}
void postder(Node *root)
{
  if(root)
  {

    preorder(root->left);

    preorder(root->right);
      cout<<root->data<<",";
  }
}
Node *buildtree(string ex)
{
  stack<Node *> s;
  Node *t1,*t2,*t3;
  for(int i=0;i<ex.size();i++)
  {
    if(!isoperator(ex[i]))
    {
    t1  =(Node *)malloc(sizeof(Node));
      t1->data=ex[i];
      t1->left=t1->right=NULL;
      s.push(t1);

    }
    else
    {
      t1=(Node *)malloc(sizeof(Node));
      t1->data=ex[i];
      t2=s.top();
      s.pop();
      t3=s.top();
      s.pop();
      t1->left=t2;
      t1->right=t3;
      s.push(t1);

    }

  }
  t1=s.top();
  s.pop();
  return t1;
}
int main()
{
  string ex;
  Node *root;
  cout<<"Enter the expression"<<"\n";
  cin>>ex;
  root=buildtree(ex);
  cout<<"Infix Expression"<<"\n";
  inorder(root);
  cout<<"\n";
  cout<<"Prefix pression"<<"\n";
  preorder(root);

}
