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

    int subtreeSum(Node* node) 
    {
        if (!node) return 0;
        return node->data + subtreeSum(node->left) + subtreeSum(node->right);
    }

    void printSubtree(Node* node)
    {
        if (!node) 
        {
            return;
        }

        printSubtree(node->left);
        cout << node->data << " ";
        printSubtree(node->right);
    }

    bool findSubtree(Node* node, int target)
    {
        if (!node) 
        {
            return false;
        }

        int sum = subtreeSum(node);
        if (sum == target) 
        {
            cout << "Subtree with sum " << target << ": ";
            printSubtree(node);
            cout << endl;
            return true;
        }

        return findSubtree(node->left, target) || findSubtree(node->right, target);
    }

    public:
        BinaryTree() : root(nullptr) {}

        void insert(int val) 
        {
            root = add(root, val);
        }

        void visualize() 
        {
            cout << "InOrder Visualization: ";
            printSubtree(root);
            cout << endl;
        }

        void findSubtreeWithSum(int target)
        {
            if (!findSubtree(root, target))
                cout << "No subtree with sum " << target << " found!" << endl;
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

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    tree.findSubtreeWithSum(target);

    return 0;
}
