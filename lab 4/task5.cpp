#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
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
        if (!swapped) break;
    }
}

int binarySearch(int arr[], int size, int target)
{
    int low = 0, high = size - 1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {return mid;}
        else if (arr[mid] < target) {low = mid + 1;}
        else {high = mid - 1;}
    }
    
    return -1; 
}

int main()
{
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    
    int* arr = new int[size];
    
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    bubbleSort(arr, size);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int target;
    cout << "Enter value to search: ";
    cin >> target;
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1)
        {
            cout << "Element found at index: " << result << endl;
        }
    else
        {
            cout << "Element not found in the array.\n";
        }
    
    delete[] arr;
    return 0;
}
