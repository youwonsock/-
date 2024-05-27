#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool IsVPS(string str)
{
    int i = 0;
    int cnt = 0;

    while(str.length() > i)
    {
        if(str[i++] == '(')
            ++cnt;
        else
            --cnt;

        if(cnt < 0)
            break;
    }

    if(cnt != 0)
        return false;

    return true;
}

int main(void)
{
    fastIo

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        
        if(IsVPS(str))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}
