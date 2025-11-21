#include <iostream>
using namespace std;

class Hash
{
    static const int size = 100;
    int table[size];

public:

    Hash()
    {
        for (int i = 0; i < size; i++) {table[i] = -1;}
    }

    int hashFunction(int val)
    {
        return val % size;
    }

    void insert(int val)
    {
        int index = hashFunction(val);
        int start = index;

        while (table[index] != -1 && table[index] != -2)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                cout << "Hash Table FULL! Cannot insert!\n";
                return;
            }
        }

        table[index] = val;
    }

    bool search(int val)
    {
        int index = hashFunction(val);
        int start = index;

        while (table[index] != -1)
        {
            if (table[index] == val) {return true;}

            index = (index + 1) % size;
            
            if (index == start) {break;}
        }
        return false;
    }

    void remove(int val)
    {
        int index = hashFunction(val);
        int start = index;

        while (table[index] != -1)
        {
            if (table[index] == val)
            {
                table[index] = -2;  
                return;
            }

            index = (index + 1) % size;
            if (index == start) {break;}
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] >= 0)
            {
                cout << table[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Hash h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);

    h.display();  

    cout << "Remove 4\n";
    h.remove(4);
    h.display();  

    if (h.search(5))
    {
        cout << "5 found\n";
    }
    else
    {
        cout << "5 not found\n";
    }

    if (h.search(6))
    {    
        cout << "6 found\n";
    }

    else
    {
        cout << "6 not found\n";
    }

    return 0;
}
