#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;
    multiset<int> greades;

    if(n > 0)
    {
        for(int i = 0; i < n; ++i)
        {
            int n;
            cin >> n;
            greades.insert(n);
        }
    }
    else
    {
        cout << 0 << "\n";
        return 0;
    }

    int trim = floor(n * 0.15f + 0.5f);
    int avg = 0;

    set<int>::iterator sIter = greades.begin();
    set<int>::iterator eIter = greades.end();

    for(int i = 0; i < trim; ++i)
    {
        sIter++;
        eIter--;
    }
    
    for(set<int>::iterator iter = sIter; iter != eIter; iter++)
        avg += *iter;

    avg = floor(avg / (n - trim * 2.0f) + 0.5f);

    cout << avg << "\n";

    return 0;
}
