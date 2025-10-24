#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>     
using namespace std;

long long comparisons = 0;

int choosePivot(vector<int>& arr, int low, int high, const string& method) 
{
    if (method == "first") return low;
    if (method == "middle") return low + (high - low) / 2;
    if (method == "random") return low + rand() % (high - low + 1);
    if (method == "median3") 
    {
        int mid = low + (high - low) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        if ((a > b) != (a > c)) return low;
        else if ((b > a) != (b > c)) return mid;
        else return high;
    }
    return high; 
}

int partition(vector<int>& arr, int low, int high, const string& method) 
{
    int pivotIndex = choosePivot(arr, low, high, method);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        comparisons++;
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, const string& method) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high, method);
        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
    }
}

int main() 
{
    srand(time(0)); 

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    string methods[] = {"first", "random", "middle", "median of three"};

    for (const string& method : methods) 
    {
        vector<int> copy = arr;
        comparisons = 0;
        quickSort(copy, 0, copy.size() - 1, method);

        cout << method << " pivot: ";
        for (int x : copy) cout << x << " ";
        cout << "| Comparisons: " << comparisons << endl;
    }

    return 0;
}
