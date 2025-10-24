#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Product 
{
    string name;
    double price;
    string description;
    string availability;
};

int partition(vector<Product>& products, int low, int high)
{
    double pivot = products[high].price; 
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (products[j].price < pivot)
        {
            i++;
            swap(products[i], products[j]);
        }
    }

    swap(products[i + 1], products[high]);
    return i + 1;
}

void quickSort(vector<Product>& products, int low, int high)
{
    if (low < high)
    {
        int pi = partition(products, low, high);
        quickSort(products, low, pi - 1);
        quickSort(products, pi + 1, high);
    }
}

int main()
{
    vector<Product> products(3);

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter product name: ";
        cin >> ws;
        getline(cin, products[i].name);

        cout << "Enter product price: ";
        cin >> products[i].price;
        cin.ignore();

        cout << "Enter product description: ";
        getline(cin, products[i].description);

        cout << "Enter product availability: ";
        getline(cin, products[i].availability);

        cout << endl;
    }

    quickSort(products, 0, products.size() - 1);

    cout << "\nProducts sorted by price:\n";
    for (const auto& p : products)
    {
        cout << "Name: " << p.name << endl;
        cout << "Price: " << p.price << endl;
        cout << "Description: " << p.description << endl;
        cout << "Availability: " << p.availability << endl;
        cout << "----------------------\n";
    }

    return 0;
}
