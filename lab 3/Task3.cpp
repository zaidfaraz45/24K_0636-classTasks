#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
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

        void insertAtTail(int comp)
        {
            Node *temp = new Node(comp);

            if (head == NULL) 
            {
                head = temp;
                tail = temp;
            }

            else
            {
                tail->next = temp; 
                temp->prev = tail;
                tail = temp;       
            }
        }

        void deleteHead()
        {
            if (head == nullptr) {return;}

            Node* toDelete = head;
            head = head->next;   

            if (head != nullptr)
            {
                head->prev = nullptr; 
            }
            else
            {
                tail = nullptr;
            }

            delete toDelete;
        }


        void searchCompartment(int comp)
        {
            Node *temp = head;

            while (temp != NULL)
            {
                if (temp->data == comp)
                {
                    cout << "Comparment number " << comp << " found!\n";
                    return;
                }

                temp = temp->next;
            }

            cout << " Compartment number " << comp << " not in the train!" << endl;
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
    LinkedList train;
    
    train.insertAtTail(34);
    train.insertAtTail(46);
    train.insertAtTail(54);

    train.deleteHead();
    train.searchCompartment(54);

    return 0;
}