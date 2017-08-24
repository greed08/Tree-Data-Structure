#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *newNode(int a)
{
Node *  root=(Node*)malloc(sizeof(Node));
  root->data=a;
  root->left=root->right=NULL;
  return root;
}
void hori_cal(Node *root,int hori,map<int,vector<pair<int,int> > > &m,int level)
{
  if(root==NULL)
  return;
  m[hori].push_back(make_pair(level,root->data));
  hori_cal(root->left,hori-1,m,level+1);
  hori_cal(root->right,hori+1,m,level+1);

}

int main()
{
 int hori=0;
 map<int,vector<pair<int,int> > > m; //pair contains level of each node
 Node *root=newNode(1);
 root->right=newNode(3);
 root->left=newNode(2);
 root->left->right=newNode(4);
 root->left->right->right=newNode(5);
 root->left->right->right->right=newNode(6);
    //inorder(root);
    //top_view1(root);
    int level=0;

    hori_cal(root,0,m,0);
    map<int,vector<pair<int,int> > > :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
      for(int i=0;i<it->second.size();i++)
      {
        cout<<it->second[i].first<<",";
      }
      cout<<"\n";
    }


}

//Node *set_next(Node *root)
//{
/*  queue<Node *> q;
  if(root)
  q.push(root);
  while(!q.empty())
  {
    int s=q.size();
    Node *prev=NULL;
    for(int i=0;i<s;i++)
    {
      Node *temp=q.front();
      q.pop();
      if(prev)
      {
        prev->nextRight=temp;
        temp->nextRight=NULL;
        prev=temp;
      }
      else
      {
        prev=temp;
        temp->nextRight=NULL;
      }
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
    }
  }
  return root;
}
