#include <iostream>
using namespace std;

struct Node
{
    string value;
    Node *next;

    Node(string val)
    {
        value = val;
        next = nullptr;
    }
};

class HashList
{
    int buckets;
    Node **table;    

    public:
        HashList(int b) : buckets(b)
        {
            table = new Node*[buckets];
            for (int i = 0; i < buckets; i++)
            {
                table[i] = nullptr;
            }
        }

        int hash(string val)
        {
            int sum = 0;
            for (int i = 0; i < val.size(); i++)
            {
                sum += int(val[i]);
            }   

            int remainder = sum % buckets;
            return remainder;
        }
        
        void insert(string val)
        {
            int index = hash(val);

            Node* newNode = new Node(val);

            newNode->next = table[index];
            table[index] = newNode;
        }

        void display()
        {
            cout << "Hash Table:\n";
            for (int i = 0; i < buckets; i++)
            {
                cout << "Bucket " << i << ": ";
                Node *temp = table[i];

                if (!temp)
                {
                    cout << "NULL";
                }

                else
                {
                    while (temp != nullptr)
                    {
                        cout << temp->value << "->";
                        temp = temp->next;
                    }
                    cout << "NULL";
                }
                cout << endl;
            }
        }

        void search(string val)
        {
            cout << "Searching '" << val << "': ";
            int index = hash(val);     
            Node *temp = table[index]; 

            while (temp != nullptr)
            {
                if (temp->value == val)
                {
                    cout << "Found\n";    
                    return;     
                }
                temp = temp->next;       
            }

            cout << "Not Found\n";                
        }

};

int main()
{
    HashList list(10);
    list.insert("apple");
    list.insert("mango");
    list.insert("apple");
    list.insert("grapes");
    list.insert("peach");
    list.insert("banana");

    list.display();

    list.search("apple");
    list.search("orange");

    return 0;
}
