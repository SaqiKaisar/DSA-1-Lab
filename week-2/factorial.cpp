#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 0 || n == 1)   // Base case
        return 1;

    return n * factorial(n - 1);  // Recursive case
}

int main()
{
    cout << factorial(5);
}