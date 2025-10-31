#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
    Node* root;

    Node* add(Node* node, int val) 
    {
        if (node == nullptr)
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = add(node->left, val);
        }
        else
        {
            node->right = add(node->right, val);
        }

        return node;
    }

    bool checkFull(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }

        if ((node->left != nullptr && node->right == nullptr) || (node->right != nullptr && node->left == nullptr))
        {
            return false;
        }

        return checkFull(node->left) && checkFull(node->right);
    }

    void inOrder(Node* node) 
    {
        if (node == nullptr)        
        {
            return;
        }

        inOrder(node->left);
        cout << node->data << " \n";
        inOrder(node->right);
    }

    public:
        BinaryTree() : root(nullptr) {}

        void insert(int val) 
        {
            root = add(root, val);  
        }

        void fullBinary()
        {
            if (checkFull(root))
            {
                cout << "Full binary tree!\n";
                return;
            }

            cout << "Not a full binary tree!\n";
        }

        void visualize() 
        {
            cout << "inOrder Visuallization:\n";
            inOrder(root);
            cout << endl;
        }
};

int main() 
{
    BinaryTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    tree.visualize();
    tree.fullBinary();

    return 0;
}
