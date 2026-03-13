#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int n, vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (n == vec[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {1, 3, 7, 5, 2, 6};
    int n;
    cout << "Enter the value you want to search for: ";
    cin >> n;
    cout << "The index of " << n << " is: " << linearSearch(n, vec) << endl;
}
