#include <iostream>
using namespace std;

struct Node 
{
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
    Node* root;

    Node* add(Node* node, string val) 
    {
        if (!node)
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

    void inOrder(Node* node) 
    {
        if (!node) return;
        inOrder(node->left);
        cout << node->data << "\n";
        inOrder(node->right);
    }

    int countNodes(Node* node)
    {
        if (!node)
        {
            return 0;
        }
        
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node* node)
    {
        if (!node)
        {
            return 0;
        }

        if (!node->left && !node->right)
        {
            return 1;
        }
        
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int treeHeight(Node* node)
    {
        if (!node)
        {
            return -1;
        }

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    public:
        BinaryTree() : root(nullptr) {}

        void insert(string val) 
        {
            root = add(root, val);
        }

        void visualize() 
        {
            cout << "InOrder Visualization:\n";
            inOrder(root);
            cout << endl;
        }

        void displayProperties()
        {
            cout << "Total nodes: " << countNodes(root) << endl;
            cout << "Leaf nodes: " << countLeaves(root) << endl;
            cout << "Height of tree: " << treeHeight(root) << endl;
        }
};

int main() 
{
    BinaryTree tree;

    tree.insert("European Explorer");
    tree.insert("Adventure Tours");
    tree.insert("Relaxation Tours");
    tree.insert("Asian Adventure");

    tree.visualize();

    tree.displayProperties();

    return 0;
}
