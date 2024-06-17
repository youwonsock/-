#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int t, n;
    int arr[11] = {1, 2, 4, 0};

    for(int i = 3; i < 11; ++i)
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> n;

        cout << arr[n-1] << "\n";
    }

    return 0;
}
