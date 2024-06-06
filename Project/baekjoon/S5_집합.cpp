#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    set<int> s;
    string str;
    int m, t;
    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        cin >> str;

        if(str == "add")
        {
            cin >> t;
            
            s.insert(t);
        }
        else if(str == "remove")
        {
            cin >> t;

            s.erase(t);
        }
        else if(str == "check")
        {
            cin >> t;

            if(s.find(t) == s.end())
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        }
        else if(str == "toggle")
        {
            cin >> t;

            if(s.find(t) == s.end())
                s.insert(t);
            else
                s.erase(t);
        }
        else if(str == "all")
        {
            for(int i = 1 ; i <= 20; ++i)
                s.insert(i);
        }
        else
            s.clear();
    }

    return 0;
}