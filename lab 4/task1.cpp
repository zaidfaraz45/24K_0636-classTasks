#include <iostream>
using namespace std;

int *bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {break;}
    }

    return arr;
}

void displaySorted(int arr[], int size)
{
    cout << "Sorted array: [";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1] << "]\n";
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int size = sizeof(arr) / sizeof(arr[0]);

    int *sortedArr = bubbleSort(arr, size);

    displaySorted(arr, size);

    return 0;
}
