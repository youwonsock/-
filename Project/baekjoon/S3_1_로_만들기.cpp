#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<int> arr(n+1);

    for(int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i-1] + 1;

        if(i % 2 == 0)
            arr[i] = min(arr[i], arr[i/2] + 1);

        if(i % 3 == 0)
            arr[i] = min(arr[i], arr[i/3] + 1);
    }

    cout << arr[n] << "\n";

    return 0;
}