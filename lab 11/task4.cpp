#include <iostream>
using namespace std;

struct Student 
{
    int roll;
    string name;
    bool isOccupied;

    Student() 
    {
        roll = -1;
        name = "";
        isOccupied = false;
    }
};

class StudentHashTable 
{
    static const int size = 15;
    Student table[size];

    int hashFunction(int roll) 
    {
        return roll % size;
    }

    public:

        void InsertRecord(int roll, string name) 
        {
            int index = hashFunction(roll);
            int attempt = 0;

            while (attempt < size) 
            {
                int newIndex = (index + attempt * attempt) % size;

                if (!table[newIndex].isOccupied) 
                {
                    table[newIndex].roll = roll;
                    table[newIndex].name = name;
                    table[newIndex].isOccupied = true;

                    cout << "Inserted: Roll " << roll << ", Name: " << name  << " at index " << newIndex << endl;
                    return;
                }

                attempt++;
            }

            cout << "ERROR: Hash table is full. Cannot insert record!\n";
        }

        void SearchRecord(int roll) 
        {
            int index = hashFunction(roll);
            int attempt = 0;

            while (attempt < size) 
            {
                int newIndex = (index + attempt * attempt) % size;

                if (table[newIndex].isOccupied && table[newIndex].roll == roll) 
                {
                    cout << "Record Found: " << table[newIndex].name << endl;
                    return;
                }

                if (!table[newIndex].isOccupied) {break;}

                attempt++;
            }

            cout << "Record not found\n";
        }

        void DisplayTable() 
        {
            cout << "\n--- Student Hash Table ---\n";
            for (int i = 0; i < size; i++) 
            {
                if (table[i].isOccupied) {cout << i << ": Roll " << table[i].roll << ", Name " << table[i].name << endl;}
                else {cout << i << ": EMPTY\n";}
            }
            cout << "--------------------------\n";
        }
};

int main() 
{
    StudentHashTable ht;

    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(115, "Sara");
    ht.InsertRecord(130, "John");
    ht.InsertRecord(145, "Aisha");

    cout << endl;

    ht.SearchRecord(115);
    ht.SearchRecord(200);

    cout << endl;

    ht.DisplayTable();

    return 0;
}
