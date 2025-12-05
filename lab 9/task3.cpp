#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    int height;
};

class AVL
{
    public:
        Node *newNode(int value)
        {
            Node *node = new Node();

            node->value = value;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;

            return node;
        }

        int max(int a, int b)
        {
            return ((a > b) ? a : b);
        }

        int height(Node *node)
        {
            if (node == nullptr)
            {
                return 0;
            }

            return node->height;
        }

        int getBalance(Node *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            return (height(root->left) - height(root->right));
        }

        Node *rightRotate(Node *y)
        {
            Node *x = y->left;
            Node *T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

                return x;
        }

        Node *leftRotate(Node *x)
        {
            Node *y = x->right;
            Node *T2 = y->left;

            y->left = x;
            x->right = T2;

            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

            return y;
        }

        Node *insert(Node *node, int value)
        {
            if (node == nullptr)
            {
                return newNode(value);
            }

            else if (value < node->value)
            {
                node->left = insert(node->left, value);
            }

            else if (value > node->value)
            {
                node->right = insert(node->right, value);
            }

            else
            {
                return node;
            }

            int balance = getBalance(node);

            node->height = max(height(node->left), height(node->right)) + 1;

            if (balance > 1 && value < node->left->value)
            {
                return rightRotate(node);
            }

            if (balance < -1 && value < node->right->value)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            if (balance > 1 && value > node->left->value)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            if (balance < -1 && value > node->right->value)
            {
                return leftRotate(node);
            }

            return node;
        }

        void preOrder(Node *root)
        {
            if (root != nullptr)
            {
                cout << root->value << endl;
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};

int main()
{
    Node *root = nullptr;
    AVL avl;

    root = avl.insert(root, 10);
    root = avl.insert(root, 5);
    root = avl.insert(root, 15);
    root = avl.insert(root, 3);
    root = avl.insert(root, 7);
    root = avl.insert(root, 12);

    cout << "AVL tree:\n";
    avl.preOrder(root);

    return 0;
}
