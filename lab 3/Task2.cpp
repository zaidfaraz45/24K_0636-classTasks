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

        void deleteHead()
        {
            if (head == NULL) {return;}

            Node *next = head->next;
            delete head;
            head = next;

            if (head == NULL) {tail = NULL;}
        }

        void searchPosition(int pos)
        {
            if (pos < 1)
            {
                cout << "Invalid position entered!\n";
            }

            Node *temp = head;
            int i = 1;

            while (i != pos && temp != NULL)
            {
                temp = temp->next;
                i++;
            }

            if (temp == NULL)
            {
                cout << "Invalid position entered!\n";
                return;
            }

            cout << "Book " << temp->data << " at position " << pos << endl;
        }

        void searchCompartment(string title)
        {
            Node *temp = head;

            while (temp != NULL)
            {
                if (temp->data == title)
                {
                    cout << title << " book found!\n";
                    return;
                }

                temp = temp->next;
            }

            cout << title << " book not avaialable!" << endl;
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
    l1.insertAtTail("Computer Networks");
    l1.insertAtTail("DataBase Systems");

    l1.insertAtTail("Machine Learning");
    l1.deleteHead();
    l1.searchCompartment("Computer Networks");
    l1.searchPosition(4);

    l1.display();

    return 0;
}
