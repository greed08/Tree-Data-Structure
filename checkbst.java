class Node
{
  int data;
  Node left,right;
 public  Node(int key)
  {
    data=key;
    left=right=null;

  }
}
public class checkbst
{
  Node root;
  int min_value(Node root)
  {
    Node current=root;
    while(root.left!=null)
    current=root.left;
    return current.data;
  }
  int max_value(Node root)
  {
    Node current=root;
    while(root.right!=null)
    current=root.right;
    return current.data;
  }
  boolean check(Node root)
  {
    if(root==null)
    return true;
    if(root.left!=null&&min_value(root)>root.data)
    return false;
    if(root.right!=null&&max_value(root)<root.data)
    return false;
    if(!check(root.left)&&!check(root.right))
    return false;

    return true;

  }
  void inorder(Node root)
  {
    if(root!=null)
    {
      inorder(root.left);
      System.out.print(root.data +",");
      inorder(root.right);
    }
  }
  public static void main(String args[])
  {
  checkbst tree = new checkbst();
        tree.root = new Node(4);
        tree.root.left = new Node(2);
        tree.root.right = new Node(5);
        tree.root.left.left = new Node(1);
        tree.root.left.right = new Node(3);
        if(tree.check(tree.root))
        System.out.println("BST");
        else
        System.out.println("Not BST");
  }
}
