#include <iostream>
using namespace std;

struct Node
{
    string word;
    Node *next;

    Node(string w)
    {
        word = w;
        next = nullptr;
    }
};

class Dictionary
{
    Node *table[100]; 

    public:
        Dictionary()
        {
            for (int i = 0; i < 100; i++)
                table[i] = nullptr;
        }

        void Add_Record(string word)
        {
            int key = hashFunction(word);

            Node *newNode = new Node(word);

            newNode->next = table[key];
            table[key] = newNode;

            cout << "Word \"" << word << "\" added at index " << key << ".\n";
        }

        int hashFunction(string word)
        {
            int sum = 0;
            for (char c : word)
                sum += int(c);

            return sum % 100;
        }

        void Word_Search(string word)
        {
            int key = hashFunction(word);
            Node *temp = table[key];

            while (temp != nullptr)
            {
                if (temp->word == word)
                {
                    cout << "Word \"" << word << "\" FOUND at index " << key << ".\n";
                    return;
                }
                temp = temp->next;
            }

            cout << "ERROR: Word \"" << word << "\" NOT FOUND in dictionary.\n";
        }

        void Print_Dictionary()
        {
            cout << "\n====== DICTIONARY CONTENTS ======\n";

            for (int i = 0; i < 100; i++)
            {
                cout << "Bucket " << i << ": ";

                Node *temp = table[i];
                if (!temp)
                {
                    cout << "NULL\n";
                    continue;
                }

                while (temp != nullptr)
                {
                    cout << temp->word << " -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }

            cout << "=================================\n";
        }
};

int main()
{
    Dictionary dict;

    dict.Add_Record("apple");
    dict.Add_Record("banana");
    dict.Add_Record("grape");
    dict.Add_Record("apple");   
    dict.Add_Record("kiwi");

    cout << endl;

    dict.Word_Search("banana");
    dict.Word_Search("cherry"); 

    cout << endl;

    dict.Print_Dictionary();

    return 0;
}
