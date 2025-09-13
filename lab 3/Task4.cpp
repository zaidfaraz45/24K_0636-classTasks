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

class MusicPLaylist
{
    Node *head;
    Node *tail;

    public:
        MusicPLaylist()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtTail(int data)
        {
            Node *temp = new Node(data);

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

        void sortList()
        {
            if (!head) {return;}
            bool swapped;
            do 
            {
                swapped = false;
                Node* current = head;
                while (current->next != nullptr)
                {
                    if (current->data > current->next->data)
                    {
                        swap(current->data, current->next->data);
                        swapped = true;
                    }
                    current = current->next;
                }
            } while (swapped);
        }

        void concatenate(MusicPLaylist &other)
        {
            if (other.head == nullptr) {return;}
            if (head == nullptr)
            {
                head = other.head;
                tail = other.tail;
            }
            else
            {
                tail->next = other.head;
                other.head->prev = tail;
                tail = other.tail;
            }
            
            other.head = nullptr;
            other.tail = nullptr;
        }

        void findMiddle()
        {
            if (head == nullptr)
            {
                cout << "List is empty\n";
                return;
            }

            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "Middle element: " << slow->data << endl;
        }

        void removeDuplicates()
        {
            Node* current = head;
            while (current != nullptr)
            {
                Node* runner = current->next;
                while (runner != nullptr)
                {
                    if (runner->data == current->data)
                    {
                        Node* toDelete = runner;
                        if (runner->prev)
                        { 
                            runner->prev->next = runner->next;
                        }

                        if (runner->next) 
                        {
                            runner->next->prev = runner->prev;
                        }

                        if (runner == tail)
                        { 
                            tail = runner->prev;
                        }

                        runner = runner->next;
                        delete toDelete;
                    }
                    else
                    {
                        runner = runner->next;
                    }
                }
                current = current->next;
            }
        }

        static MusicPLaylist mergeSorted(MusicPLaylist &l1, MusicPLaylist &l2)
        {
            MusicPLaylist result;
            Node* p1 = l1.head;
            Node* p2 = l2.head;

            while (p1 != nullptr && p2 != nullptr)
            {
                if (p1->data <= p2->data)
                {
                    result.insertAtTail(p1->data);
                    p1 = p1->next;
                }
                else
                {
                    result.insertAtTail(p2->data);
                    p2 = p2->next;
                }
            }

            while (p1 != nullptr)
            {
                result.insertAtTail(p1->data);
                p1 = p1->next;
            }

            while (p2 != nullptr)
            {
                result.insertAtTail(p2->data);
                p2 = p2->next;
            }

            return result;
        }
};


int main()
{
    MusicPLaylist list1;
    list1.insertAtTail(5);
    list1.insertAtTail(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);

    cout << "Actual list 1: ";
    list1.display();

    list1.findMiddle();

    list1.sortList();
    cout << "Sorted list 1: ";
    list1.display();

    MusicPLaylist list2;
    list2.insertAtTail(2);
    list2.insertAtTail(4);
    list2.insertAtTail(6);

    cout << "List 2: ";
    list2.display();

    list2.findMiddle();

    list1.concatenate(list2);
    cout << "Concatenated list 1 and list 2: ";
    list1.display();

    list1.removeDuplicates();
    cout << "After removing duplicates: ";
    list1.display();

    MusicPLaylist merged = MusicPLaylist::mergeSorted(list1, list2);
    cout << "Merged and sorted lists 1 and 2: ";
    merged.display();

    return 0;
}
