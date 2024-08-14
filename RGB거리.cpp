#include <iostream>
#include <algorithm>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int arr[1001][3];
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for(int i = 1; i < n; ++i)
    {
        arr[i][0] += min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] += min(arr[i-1][0], arr[i-1][1]);
    }

    cout << min({arr[n-1][0], arr[n-1][1], arr[n-1][2]});

    return 0;
}