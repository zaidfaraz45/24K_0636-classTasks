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

class MusicPlayList
{
    Node *head;
    Node *tail;

    public:
        MusicPlayList()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtHead(string val)
        {
            Node *temp = new Node(val);      

            if (head == NULL)
            {
                head = temp;
                tail = temp;
                temp->next = head;
            }
            else 
            {
                temp->next = head;
                head = temp;
                tail->next = head;
            }
        }

        void insertAtTail(string val)
        {
            Node *temp = new Node(val);

            if (head == NULL) 
            {
                head = temp;
                tail = temp;
                temp->next = head;
            }

            else
            {
                tail->next = temp; 
                temp->next = head; 
                tail = temp;       
            }
        }

        void deleteHead() 
        {
            if (head == NULL) return;

            if (head == tail) 
            { 
                delete head;
                head = tail = NULL;
            }
            else 
            {
                Node* toDelete = head;
                head = head->next;
                tail->next = head;
                delete toDelete;
            }
        }

        void searchPosition(int pos) 
        {
            if (head == NULL || pos < 1) 
            {
                cout << "Invalid position!\n";
                return;
            }

            Node* temp = head;
            int i = 1;

            do 
            {
                if (i == pos) 
                {
                    cout << "Music " << temp->data << " at position " << pos << endl;
                    return;
                }
                temp = temp->next;
                i++;
            } while (temp != head);

            cout << "Invalid position!\n";
        }

        void searchMusic(string title) 
        {
            if (head == NULL) 
            {
                cout << "Playlist empty!\n";
                return;
            }

            Node* temp = head;
            do 
            {
                if (temp->data == title) 
                {
                    cout << title << " found!\n";
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout << title << " not available!\n";
        }

        void display()
        {
            if (head == NULL)
            {
                cout << "Playlist empty!\n";
                return;
            }

            Node *temp = head;

            do
            {
                cout << temp->data << "->";
                temp = temp->next;
            }while (temp != head);

            cout << "(head)";
        }
};

int main()
{   
    MusicPlayList playlist;

    playlist.insertAtHead("Blinding Lights");
    playlist.insertAtTail("Shape of You");
    playlist.insertAtTail("Levitating");
    playlist.insertAtHead("Peaches");
    playlist.insertAtTail("Bad Guy");

    cout << "Playlist:\n";
    playlist.display();

    playlist.searchPosition(1);
    playlist.searchPosition(3);
    playlist.searchPosition(6);

    playlist.searchMusic("Levitating");
    playlist.searchMusic("Happier"); 

    playlist.deleteHead();
    playlist.display();

    playlist.insertAtTail("Stay");
    playlist.insertAtTail("Senorita");

    cout << "\nPlaylist:\n";
    playlist.display();

    return 0;
}
