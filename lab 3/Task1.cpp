#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

    public:
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtHead(int data)
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;       
        }

        void display()
        {
            Node *temp = head;

            while(temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }

            cout << "NULL\n";
        }
};

int main()
{
    LinkedList l1;
    l1.insertAtHead(2);
    l1.insertAtHead(4);

    l1.display();

    return 0;
}