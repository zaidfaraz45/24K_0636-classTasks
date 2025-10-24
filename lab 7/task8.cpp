#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Order 
{
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(vector<Order>& orders, int low, int high) 
{
    double pivot = orders[high].totalPrice; 
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        if (orders[j].totalPrice < pivot) 
        {
            i++;
            swap(orders[i], orders[j]);
        }
    }

    swap(orders[i + 1], orders[high]);
    return i + 1;
}

void quickSort(vector<Order>& orders, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(orders, low, high);
        quickSort(orders, low, pi - 1);
        quickSort(orders, pi + 1, high);
    }
}

int main() 
{
    vector<Order> orders = 
    {
        {1001, "Alice", 250.75},
        {1002, "Bob", 120.50},
        {1003, "Charlie", 890.00},
        {1004, "David", 560.25},
        {1005, "Eve", 300.00},
        {1006, "Frank", 150.40}
    };

    cout << "Before Sorting (by Total Price):\n";
    cout << "--------------------------------\n";
    for (auto& o : orders)
        cout << o.orderID << " | " << o.customerName 
             << " | $" << o.totalPrice << endl;

    quickSort(orders, 0, orders.size() - 1);

    cout << "\nAfter Sorting (Ascending by Total Price):\n";
    cout << "----------------------------------------\n";
    for (auto& o : orders)
        cout << o.orderID << " | " << o.customerName 
             << " | $" << o.totalPrice << endl;

    return 0;
}
