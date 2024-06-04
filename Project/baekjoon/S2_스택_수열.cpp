#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() 
{
    int n, temp;
    queue<int> q;
    stack<int> s;
    vector<char> ans;
    
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> temp;
        q.push(temp);
    }

    int current = 1;
    while (!q.empty()) 
    {
        if (!s.empty() && s.top() == q.front()) 
        {
            s.pop();
            q.pop();
            ans.push_back('-');
        }
        else if (current <= q.front()) 
        {
            while (current <= q.front()) {
                s.push(current++);
                ans.push_back('+');
            }
        }
        else 
        {
            cout << "NO" << "\n";
            return 0;
        }
    }

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}
