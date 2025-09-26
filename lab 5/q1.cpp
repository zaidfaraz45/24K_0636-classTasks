#include <iostream>
#include <random>
using namespace std;

void guessGame(int num)
{
    int guess;

    cout << "Enter your guess(1-100): ";
    cin >> guess;

    if (num == guess)
    {
        cout << "You win!";
        return;
    }

    else
    {
        if (guess > num)
        {
            cout << "You guessed higher! Onto the next player!\n";
        }
        else
        {
            cout << "You guessed lower!Onto the next player!\n";
        }

        cout << endl;
        guessGame(num);
    }
}

int main()
{
    int num;

    srand(time(0));

    num = rand() % 100 + 1;

    guessGame(num);

    return 0;
}
