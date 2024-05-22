#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool BinarySearch(vector<int>& arr, int start, int end, int key)
{
    int mid = 0;

    while(true)
    {
        mid = (start + end) / 2;

        if(arr[mid] > key)
            end = mid - 1;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            return true;

        if (start > end)
            break;
    }

    return false;
}

int main(void)
{
    fastIo
    int n,m;
    cin >> n;
    vector<int> A(n);

    for(int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());

    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int key;
        cin >> key;

        if(BinarySearch(A, 0, n-1, key))
            cout << "1" << "\n";
        else
            cout << "0" << "\n";
    }

    return 0;
}