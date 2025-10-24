#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, vector<string>& names, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1), r(n2);
    vector<string> lname(n1), rname(n2);

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i];
        lname[i] = names[left + i];
    }

    for (int j = 0; j < n2; j++)
    {   
        r[j] = arr[mid + 1 + j];
        rname[j] = names[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (l[i] <= r[j]) 
        {
            arr[k] = l[i];
            names[k] = lname[i];
            i++;
        }
        else 
        {
            arr[k] = r[j];
            names[k] = rname[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = l[i];
        names[k] = lname[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = r[j];
        names[k] = rname[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, vector<string>& names, int left, int right)
{    
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, names, left, mid);
    mergeSort(arr, names, mid + 1, right);
    merge(arr, names, left, mid, right);
}

int main()
{
    string runners[10];
    int finish[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter runner name " << i + 1 << ": ";
        cin >> runners[i];

        cout << "Enter finish time " << i + 1 << ": ";
        cin >> finish[i];

        cout << endl;
    }

    vector<int> Finish;
    vector<string> Runners;

    for (int i = 0; i < 10; i++)
    {
        Finish.push_back(finish[i]);
        Runners.push_back(runners[i]);
    }

    mergeSort(Finish, Runners, 0, 9);

    cout << "Fastest runners:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Runners[i] << " " << Finish[i] << endl;
    }

    return 0;
}
