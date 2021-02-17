
 #include <iostream>
#include <queue>
using namespace std;
 
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
 
void printinorder(Node *temp)
{
    if (temp == NULL)
        return;
 
    printinorder(temp->left);
    cout << temp->data << " ";
    printinorder(temp->right);
}
 
void printpostorder(Node *temp)
{
    if (temp == NULL)
        return;
    printpostorder(temp->left);
    printpostorder(temp->right);
    cout << temp->data << " ";
}
 
void printpreorder(Node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    printpreorder(temp->left);
    printpreorder(temp->right);
}
 
void insert(Node *temp, int data)
{
    queue<Node *> q;
    q.push(temp);
 
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
 
        if (!temp->left)
        {
            temp->left = new Node(data);
            break;
        }
        else
            q.push(temp->left);
 
        if (!temp->right)
        {
            temp->right = new Node(data);
            break;
        }
        else
            q.push(temp->right);
    }
}
Node *deleteNode(Node *root, int k)
{
    if (root == NULL)
        return root;
    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {
 
        Node *temp2 = root;
        Node *parent = root->right;
        while (parent->left != NULL)
        {
            temp2 = parent;
            parent = parent->left;
        }
        if (temp2 != root)
            temp2->left = parent->right;
        else
            temp2->right = parent->right;
 
        root->data = parent->data;
        delete parent;
        return root;
    }
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
 
    /* 
    Binary Tree (Before Inserting node)
                   5
              3         7
            2   4     6   8 
    */
 
    // INORDER - LEFT ROOT RIGHT
    // PREORDER - ROOT LEFT RIGHT
    // POSTORDER - LEFT RIGHT ROOT
 
    cout << "Inorder traversal before insertion: ";
    printinorder(root);
    cout << "\nPostorder traversal before insertion: ";
    printpostorder(root);
    cout << "\nPreorder traversal before insertion: ";
    printpreorder(root);
 
    cout << "\nEnter data to add in tree ";
    int val;
    cin >> val;
    insert(root, val);
    cout << val << " inserted in tree\n";
 
    /* 
    Binary Tree (After Inserting node)
                   5
              3         7
            2   4     6   8 
         1 
    */
 
    cout << "Inorder traversal after insertion: ";
    printinorder(root);
    cout << "\nPostorder traversal after insertion: ";
    printpostorder(root);
    cout << "\nPreorder traversal after insertion: ";
    printpreorder(root);
 
    cout << "\nEnter data to delete from tree ";
    int val2;
    cin >> val2;
    deleteNode(root, val2);
    cout << val2 << " deleted from tree\n";
 
    cout << "Inorder traversal after deletion: ";
    printinorder(root);
    cout << "\nPostorder traversal after deletion: ";
    printpostorder(root);
    cout << "\nPreorder traversal after deletion: ";
    printpreorder(root);
 
    return 0;
}
