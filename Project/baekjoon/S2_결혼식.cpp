#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void DFS(const vector<vector<int>>& adjList, vector<bool>& visited, int depth, int current)
{
    visited[current] = true;

    if(depth == 2)
        return;

    for(int i = 0; i < adjList[current].size(); ++i)
        DFS(adjList, visited, depth + 1, adjList[current][i]);
}

int main(void)
{
    fastIo

    int n, m, a, b;
    int count = 0;
    cin >> n;
    cin >> m;

    vector<vector<int>> adjList(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    DFS(adjList, visited, 0, 1);

    for(int i = 0; i < n+1; ++i)
    {
        if(visited[i])
            ++count;
    }

    cout << count-1;

    return 0;
}
