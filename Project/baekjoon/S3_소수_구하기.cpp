#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n,m;
    cin >> n >> m;
    vector<int> arr(m + 1);

    for(int i = 2; i <= m; ++i)
        arr[i] = i;

    for(int i = 2; i <= m; ++i)
    {
        if(arr[i] == 0)
            continue;

        for(int j = i * 2; j <= m; j += i)
            arr[j] = 0;
    }

    for(int i = n; i <= m; ++i)
    {
        if(arr[i] != 0)
            cout << arr[i] << "\n";
    }

    return 0;
}

