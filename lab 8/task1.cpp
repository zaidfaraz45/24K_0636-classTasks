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

        void insert(string val) 
        {
            root = add(root, val);  
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

    tree.insert("European Explorer");
    tree.insert("Adventure Tours");
    tree.insert("Relaxation Tours");
    tree.insert("Asian Adventure");

    tree.visualize();

    return 0;
}
