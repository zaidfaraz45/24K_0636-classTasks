#include <iostream>
using namespace std;

class EmployeeHashTable
{
    static const int SIZE = 50;
    string table[SIZE];

    public:

        EmployeeHashTable()
        {
            for (int i = 0; i < SIZE; i++)
                table[i] = "";
        }

        int primaryHash(string name)
        {
            int sum = 0;
            for (char c : name)
            {
                sum += int(c);
            }

            return sum % SIZE;  
        }

        int secondaryHash(string name)
        {
            int sum = 0;
            for (char c : name)
            {
                sum += int(c);
            }

            return 7 - (sum % 7);
        }

        void Add_Employee(string name)
        {
            int h1 = primaryHash(name);
            int h2 = secondaryHash(name);

            int index = h1;

            for (int i = 0; i < SIZE; i++)
            {
                index = (h1 + i * h2) % SIZE;

                if (table[index] == "")
                {
                    table[index] = name;
                    cout << "Inserted \"" << name << "\" at index " << index << endl;
                    return;
                }
            }

            cout << "ERROR: Hash Table Full! Cannot insert \"" << name << "\"\n";
        }

        void Search_Employee(string name)
        {
            int h1 = primaryHash(name);
            int h2 = secondaryHash(name);

            int index;

            for (int i = 0; i < SIZE; i++)
            {
                index = (h1 + i * h2) % SIZE;

                if (table[index] == name)
                {
                    cout << "Employee \"" << name << "\" found at index " << index << endl;
                    return;
                }

                if (table[index] == "")
                    break;  
            }

            cout << "Employee not found in the directory." << endl;
        }

        void Display_Table()
        {
            cout << "\n---- EMPLOYEE DIRECTORY ----\n";
            for (int i = 0; i < SIZE; i++)
            {
                cout << i << ": ";
                if (table[i] == "")
                    cout << "EMPTY";
                else
                    cout << table[i];
                cout << endl;
            }
            cout << "----------------------------\n";
        }
};

int main()
{
    EmployeeHashTable ht;

    ht.Add_Employee("Zainab");
    ht.Add_Employee("Ayesha");
    ht.Add_Employee("Hassan");
    ht.Add_Employee("Ali");
    ht.Add_Employee("John Doe");
    ht.Add_Employee("Fatima");

    cout << endl;

    ht.Search_Employee("Hassan");
    ht.Search_Employee("Saad");

    cout << endl;

    ht.Display_Table();

    return 0;
}
