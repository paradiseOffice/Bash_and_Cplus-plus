#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void displayNums(vector<int>& DynArray)
{
    for_each (DynArray.begin(), DynArray.end(), \
       [](int Element) { cout << Element << " "; } ); // lambda
    cout << endl;
}

int main()
{
    vector<int> MyNumbers;
    MyNumbers.push_back(501);
    MyNumbers.push_back(-1);
    MyNumbers.push_back(25);
    MyNumbers.push_back(-35);

    displayNums(MyNumbers);

    cout << "Sorting them in descending order" << endl;

    sort (MyNumbers.begin(), MyNumbers.end(), \
      [](int num1, int num2) { return (num2 > num1); } );
    displayNums(MyNumbers);

    return 0;
}

