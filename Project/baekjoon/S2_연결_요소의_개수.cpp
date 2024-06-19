#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void BFS(const vector<vector<int>>& adjList, vector<bool>& visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (q.size() > 0)
    {
        int next = q.front(); q.pop();

        for(int i = 0; i < adjList[next].size(); ++i)
        {
            if(!visited[adjList[next][i]])
            {
                q.push(adjList[next][i]);
                visited[adjList[next][i]] = true;
            }
        }
    }
}

int main(void)
{
    fastIo

    int n, m;
    int u, v;

    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    vector<bool> visited(n+1, false);
    
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(visited[i])
            continue;

        BFS(adjList, visited, i);
        ++cnt;
    }

    cout << cnt << "\n";

    return 0;
}
