#include <iostream>
using namespace std;

struct Record
{
    string student;
    int rollNum;
};

struct Node
{
    Record record;
    Node *left;
    Node *right;
    int height;
};

class AVL
{
    public:
        Node *newNode(Record record)
        {
            Node *node = new Node();

            node->record = record;
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

        Node *insert(Node *node, Record record)
        {
            if (node == nullptr)
            {
                return newNode(record);
            }

            else if (record.rollNum < node->record.rollNum)
            {
                node->left = insert(node->left, record);
            }

            else if (record.rollNum > node->record.rollNum)
            {
                node->right = insert(node->right, record);
            }

            else
            {
                return node;
            }

            int balance = getBalance(node);

            node->height = max(height(node->left), height(node->right)) + 1;

            if (balance > 1 && record.rollNum < node->left->record.rollNum)
            {
                return rightRotate(node);
            }

            if (balance < -1 && record.rollNum < node->right->record.rollNum)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            if (balance > 1 && record.rollNum > node->left->record.rollNum)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            if (balance < -1 && record.rollNum > node->right->record.rollNum)
            {
                return leftRotate(node);
            }

            return node;
        }

        void preOrder(Node *root)
        {
            if (root != nullptr)
            {
                cout << root->record.rollNum << endl;
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};

int main()
{
    Node *root = nullptr;
    AVL avl;

    root = avl.insert(root, {"Student 1", 10});
    root = avl.insert(root, {"Student 2", 20});
    root = avl.insert(root, {"Student 3", 30});
    root = avl.insert(root, {"Student 4", 40});
    root = avl.insert(root, {"Student 5", 50});
    root = avl.insert(root, {"Student 6", 15});

    cout << "height: " << avl.height(root) << endl;

    cout << "AVL tree:\n";
    avl.preOrder(root);

    return 0;
}
