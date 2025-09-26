#include <iostream>
using namespace std;

int sumOfDigits(int num, int sum = 0)
{
    if (num == 0)
    {
        if (sum < 10)   {return sum;}

        else
        {
            return sumOfDigits(sum);
        }
    }

    int digit = num % 10;
    sum += digit;
    return sumOfDigits(num / 10, sum);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = sumOfDigits(num);
    cout << "The sum of its digits is " << sum << "." << endl;

    return 0;
}
