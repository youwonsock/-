#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n, m, cardNum;
    cin >> n;
    map<int,int> cardMap;

    for(int i = 0; i < n; ++i)
    {
        cin >> cardNum;
        cardMap[cardNum]++;
    }

    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> cardNum;
        cout << cardMap[cardNum] << " ";
    }

    return 0;
}
