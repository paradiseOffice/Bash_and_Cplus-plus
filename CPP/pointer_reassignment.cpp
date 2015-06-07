#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int* pInteger = &age;
    cout << "pInteger points to age now" << endl;

    cout << "pInteger = " << hex << pInteger << endl;

    int dogsAge = 9;
    pInteger = &dogsAge;
    cout << "pInteger points to dogsAge now" << endl;

    cout << "pInteger = " << hex << pInteger << endl;

    return 0;
}

