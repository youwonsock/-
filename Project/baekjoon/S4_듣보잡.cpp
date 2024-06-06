#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    unordered_map<string, int> hash;
    vector<string> arr;
    int n, m;
    cin >> n >> m;

    string str;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        hash[str] = 1;
    }

    for(int i = 0; i < m; ++i)
    {
        cin >> str;
        
        if(hash[str])
            arr.push_back(str);
    }

    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << "\n";

    return 0;
}