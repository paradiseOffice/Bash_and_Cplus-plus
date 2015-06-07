#include <iostream>

using namespace std;

// define an inline function that doubles 
inline long doubleNum (int input)
{
    return input * 2;
}

int main()
{
    cout << "Enter an integer: ";
    int input = 0;
    cin >> input;

    // Call inline function
    cout << "Double is: " << doubleNum(input) << endl;

    return 0;
}
