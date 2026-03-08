#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n == 0)      // Base case
        return 0;

    if(n == 1)      // Base case
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);  // Recursive calls
}

int main()
{
    int n = 6;
    cout << fibonacci(n);
}   