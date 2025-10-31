#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string productID;
    int quantity;
    Node* left;
    Node* right;

    Node(string id, int qty) : productID(id), quantity(qty), left(nullptr), right(nullptr) {}
};

class ProductBST 
{
    Node* root;

    Node* add(Node* node, string id, int qty) 
    {
        if (!node) return new Node(id, qty);

        if (id < node->productID) 
        {
            node->left = add(node->left, id, qty);
        }

        else if (id > node->productID) 
        {
            node->right = add(node->right, id, qty);
        }

        else 
        {
            node->quantity = qty;
        }

        return node;
    }

    Node* search(Node* node, string id) 
    {
        if (!node)
        {
            return nullptr;
        }
        if (id == node->productID)
        {
            return node;
        }
        if (id < node->productID)
        {
            return search(node->left, id);
        }

        return search(node->right, id);
    }

    void inOrder(Node* node) 
    {
        if (!node)
        {
            return;
        }

        inOrder(node->left);
        cout << node->productID << " : " << node->quantity << "\n";
        inOrder(node->right);
    }

    Node* findMaxQuantity(Node* node, Node* &maxNode) 
    {
        if (!node)
        {
            return nullptr;
        }
        if (!maxNode || node->quantity > maxNode->quantity)
        {
            maxNode = node;
        }

        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
        return maxNode;
    }

    public:
        ProductBST() : root(nullptr) {}

        void insert(string id, int qty) 
        {
            root = add(root, id, qty);
        }

        void searchProduct(string id) 
        {
            Node* result = search(root, id);
            if (result) 
            {
                cout << "Product found: " << result->productID << " - Quantity: " << result->quantity << "\n";
            }

            else 
            {
                cout << "Product not found.\n";
            }
        }

        void visualize() 
        {
            cout << "InOrder Visualization:\n";
            inOrder(root);
            cout << endl;
        }

        void productWithMaxQuantity() 
        {
            Node* maxNode = nullptr;
            findMaxQuantity(root, maxNode);
            if (maxNode) 
            {
                cout << "Product with highest quantity: " << maxNode->productID << " - Quantity: " << maxNode->quantity << "\n";
            }
        }
};

int main() 
{
    ProductBST tree;

    tree.insert("P1001", 50);
    tree.insert("P1002", 30);
    tree.insert("P1003", 70);
    tree.insert("P1004", 40);

    tree.visualize();

    tree.searchProduct("P1002");

    tree.productWithMaxQuantity();

    return 0;
}
