
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;

    vector<pair<int, int>> times(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> times[i].second;
        cin >> times[i].first;
    }
    sort(times.begin(), times.end());

    int endTime = times[0].first;
    int cnt = 1;
    for(int i = 1; i < n; ++i)
    {
        if(times[i].second >= endTime)
        {
            ++cnt;
            endTime = times[i].first;
        }
    }

    cout << cnt << '\n';

    return 0;
}
