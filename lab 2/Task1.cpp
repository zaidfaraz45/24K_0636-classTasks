#include <iostream>
using namespace std;

class Array
{
    private:
        int *data;
        int size;
        int index;

    public:
        Array()
        {
            size = 5;
            data = new int[size];
            index = 0;
        }

        void insert(int push_back)
        {  
            if (index == size)
            {
                int newSize = size * 2;
                int *newData = new int[newSize];

                for (int i = 0; i < size; i++)
                {
                    newData[i] = data[i];
                }

                delete[] data;

                data = newData;
                size = newSize;
            }

            data[index] = push_back;
            index++;
        }

        void display()
        {
            for (int i = 0; i < index; i++)
            {
                cout << data[i] << endl;
            }
        }

        ~Array()
        {
            delete[] data;
        }
};

int main()
{
    Array array1;

    array1.insert(6);
    array1.insert(2);
    array1.insert(3);

    array1.display();

    return 0;
}

