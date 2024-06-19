#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n, m;
    cin >> n >> m;

    vector<int> nums(n+1,0);
    for(int i =1; i <= n; ++i)
    {
        cin >> nums[i];
        nums[i] += nums[i-1];
    }

    for(int k = 0; k < m; ++k)
    {
        int i, j;
        cin >> i >> j;

        cout << nums[j] - nums[i-1] << "\n";
    }

    return 0;
}
