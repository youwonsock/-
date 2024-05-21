#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<string> arr(n);

    for(int i = 0; i<n; ++i)
        cin >> arr[i];

    sort(arr.begin(),arr.end(),[](string s1, string s2) -> bool 
    { 
        if(s1.length() == s2.length())
            return s1 < s2;
        else
            return s1.length() < s2.length();
    });
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i<arr.size(); ++i)
        cout << arr[i] << '\n';

    return 0;
}