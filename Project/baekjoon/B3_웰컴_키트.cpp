#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    int sizeArr[6];
    int t, p;
    cin >> n;
    for(int i = 0; i < 6; ++i)
        cin >> sizeArr[i];
    cin >> t >> p;

    int TCount = 0;
    for(int i = 0; i < 6; ++i)
    {
        TCount += sizeArr[i] / t;
        
        if(sizeArr[i] % t != 0)
            ++TCount; 
    }

    cout << TCount << "\n";
    cout << n / p << " " << n % p << "\n";

    return 0;
}
