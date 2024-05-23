#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n, m, idx;
    cin >> n >> m;
    vector<int> arr(n);
    idx = m-1;

    for(int i = 0; i < n; ++i)
        arr[i] = i+1;

    cout << "<" << m;
    arr.erase(remove(arr.begin(),arr.end(), m), arr.end());

    while (arr.size() > 0)
    {
        idx = (idx + m-1) % arr.size();
        cout << ", "<< arr[idx];
        arr.erase(remove(arr.begin(),arr.end(), arr[idx]), arr.end());
    }
    
    cout << ">";

    return 0;
}
