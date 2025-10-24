#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee 
{
    string name;
    int id;
    double salary;
};

void merge(vector<Employee>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Employee> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) 
        { 
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Employee>& arr, int left, int right) 
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() 
{
    vector<Employee> employees = 
    {
        {"Alice", 101, 55000},
        {"Bob", 102, 72000},
        {"Charlie", 103, 48000},
        {"David", 104, 92000},
        {"Eve", 105, 61000},
        {"Frank", 106, 87000},
        {"Grace", 107, 76000},
        {"Hannah", 108, 69000},
        {"Ian", 109, 53000},
        {"Jane", 110, 83000},
        {"Kevin", 111, 50000},
        {"Liam", 112, 95000}
    };

    mergeSort(employees, 0, employees.size() - 1);

    cout << "Top 3 Highest Paid Employees:\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < 3; i++) 
    {
        cout << employees[i].name 
             << " (ID: " << employees[i].id 
             << ") - Salary: $" << employees[i].salary << endl;
    }

    return 0;
}
