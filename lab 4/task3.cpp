#include <iostream>
using namespace std;

int *shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }

            arr[res] = temp;
        }
    }

    return arr;
}

int* inputArr(int& size)
{
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter array index " << i + 1 << ": ";
        cin >> arr[i];
    }

    return arr; 
}

void displayArr(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1] << "]\n";
}

int main()
{
    int size;
    int* arr = inputArr(size);  

    cout << "Unsorted array: ";
    displayArr(arr, size);

    shellSort(arr, size);       

    cout << "Sorted array: ";
    displayArr(arr, size);

    delete[] arr; 
    return 0;
}
