#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    queue<int> q;
    int n;
    cin >> n;


    for(int i = 1; i <= n; ++i)
        q.push(i);
    
    while(q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << "\n";

    return 0;
}
