#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void InsertionSort(vector<int>& arr)
{
    int temp = 0;

    for (int i = 1; i < arr.size(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    InsertionSort(arr);

    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < i + 1; ++j)
            sum += arr[j];
    }

    cout << sum;

    return 0;
}