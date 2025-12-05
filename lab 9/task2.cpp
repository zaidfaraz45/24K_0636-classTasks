#include <iostream>
using namespace std;

struct Node
{
    int element;
    Node *left;
    Node *right;
    int height;
};

class AVL
{
    public:
        Node *newNode(int element)
        {
            Node *node = new Node();

            node->element = element;
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

        Node *insert(Node *node, int element)
        {
            if (node == nullptr)
            {
                return newNode(element);
            }

            else if (element < node->element)
            {
                node->left = insert(node->left, element);
            }

            else if (element > node->element)
            {
                node->right = insert(node->right, element);
            }

            else
            {
                return node;
            }

            int balance = getBalance(node);

            node->height = max(height(node->left), height(node->right)) + 1;

            if (balance > 1 && element < node->left->element)
            {
                return rightRotate(node);
            }

            if (balance < -1 && element < node->right->element)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            if (balance > 1 && element > node->left->element)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            if (balance < -1 && element > node->right->element)
            {
                return leftRotate(node);
            }

            return node;
        }

        void preOrder(Node *root)
        {
            if (root != nullptr)
            {
                cout << root->element << endl;
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};

int main()
{
    Node *root = nullptr;
    AVL avl;

    root = avl.insert(root, 50);
    root = avl.insert(root, 30);
    root = avl.insert(root, 70);
    root = avl.insert(root, 20);
    root = avl.insert(root, 40);
    root = avl.insert(root, 60);
    root = avl.insert(root, 80);
    root = avl.insert(root, 55);

    cout << "AVL tree:\n";
    avl.preOrder(root);

    return 0;
}
