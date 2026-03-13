#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int n, vector<int> vec)
{
    int l = 0, h = vec.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (vec[mid] == n)
        {
            return mid;
        }
        else if (vec[mid] > n)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {1, 3, 5, 7, 9, 11};
    int n;
    cout << "Enter the value you want to search for: ";
    cin >> n;
    cout << "The index of " << n << " is: " << binarySearch(n, vec) << endl;
}
