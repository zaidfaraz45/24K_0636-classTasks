#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string val)
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

        void insertAtHead(string val)
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;       

            if (tail == NULL)
            {
                tail = head;
            }
        }

        void insertAtTail(string val)
        {
            Node *temp = new Node(val);

            if (head == NULL) 
            {
                head = temp;
                tail = temp;
            }

            else
            {
                tail->next = temp; 
                tail = temp;       
            }
        }

        void insertAfter(string val, string valIns)
        {
            Node *prev = head;
            Node *temp = new Node(valIns);

            while (prev->data != val)
            {
                prev = prev->next;
            }

            temp->next = prev->next->next;
            prev->next = temp;
        }

        void search(string val)
        {
            Node *temp = head;

            while (temp != tail)
            {
                if (temp->data == val)
                {
                    cout << "Book found!\n";
                    return;
                }

                temp = temp->next;
            }

            cout << "Book not found!\n";
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
    l1.insertAtHead("Data Structures");
    l1.insertAtTail("Operating Systems");
    l1.insertAtTail("Data Structures");
    l1.insertAtTail("Computer Networks");
    l1.insertAtTail("DataBase Systems");

    l1.insertAtHead("Artificial Intelligence");
    l1.insertAtTail("Machine Learning");
    l1.insertAfter("Operating Systems", "Cyber Security");

    l1.search("DataBase Systems");

    l1.display();

    return 0;
}