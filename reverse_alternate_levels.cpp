#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  char data;
  struct node *left,*right;
}Node;
Node *newNode(int key)
{
 Node *temp=(Node *)malloc(sizeof(Node));
 temp->data=key;
 temp->left=temp->right=NULL;
 return temp;
}
void store_alternate(Node *root,vector<char> &ch,int level)
{
  if(root)
  {
    store_alternate(root->left,ch,level+1);
    if(level&1)
    {
      ch.push_back(root->data);
    }
    store_alternate(root->right,ch,level+1);
  }
}
void modify(Node *root,vector<char> &ch,int level)
{
  if(root)
  {
    modify(root->left,ch,level+1);
    if(level&1)
    {
      root->data=ch.back();
      ch.pop_back();
    }
    modify(root->right,ch,level+1);
  }
}
void inorder(Node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
  }
}
int main()
{
   vector<char> ch;
    Node *root=newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
    store_alternate(root,ch,0);
  //  reverse(ch.end(),ch.begin());
  modify(root,ch,0);
  inorder(root);


}
