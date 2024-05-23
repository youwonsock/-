#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n,m;
    int result = 0;
    cin >> n >> m;

    vector<int> cards(n);

    for(int i = 0; i < n; ++i)
        cin >> cards[i];

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                int sum = cards[i] + cards[j] + cards[k];
                if( m >= sum && (m - result) > (m - sum))
                    result = sum;
            }
        }
    }

    cout << result;

    return 0;
}