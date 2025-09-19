#include <iostream>
#include <cstdlib>
using namespace std;

int bubbleSort(int arr[], int size)
{
    int comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++; 
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {break;}
    }
    return comparisons;
}

int selectionSort(int arr[], int size)
{
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            comparisons++; 
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
    return comparisons;
}

int insertionSort(int arr[], int size)
{
    int comparisons = 0;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++; 
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
    }
    return comparisons;
}

int shellSort(int arr[], int size)
{
    int comparisons = 0;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= gap)
            {
                comparisons++;
                if (arr[res - gap] > temp)
                {
                    arr[res] = arr[res - gap];
                    res -= gap;
                }
                else
                    break;
            }

            arr[res] = temp;
        }
    }
    return comparisons;
}

void displayArray(int arr[], int size)
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
    const int size = 100;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Unsorted (Bubble Sort): ";
    displayArray(arr, size);

    int comp = bubbleSort(arr, size);
    cout << "Sorted (Bubble Sort): ";
    displayArray(arr, size);
    cout << "Comparisons made: " << comp << "\n\n";

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Unsorted (Selection Sort): ";
    displayArray(arr, size);

    comp = selectionSort(arr, size);
    cout << "Sorted (Selection Sort): ";
    displayArray(arr, size);
    cout << "Comparisons made: " << comp << "\n\n";

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Unsorted (Insertion Sort): ";
    displayArray(arr, size);

    comp = insertionSort(arr, size);
    cout << "Sorted (Insertion Sort): ";
    displayArray(arr, size);
    cout << "Comparisons made: " << comp << "\n\n";

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Unsorted (Shell Sort): ";
    displayArray(arr, size);

    comp = shellSort(arr, size);
    cout << "Sorted (Shell Sort): ";
    displayArray(arr, size);
    cout << "Comparisons made: " << comp << "\n\n";

    return 0;
}
