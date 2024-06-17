
#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void BFS(const vector<vector<int>>& adjList, vector<bool>& visited, int& count)
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (true)
    {
        if (q.empty())
            break;

        int current = q.front(); q.pop();
        ++count;

        for (int i = 0; i < adjList[current].size(); ++i)
        {
            if (!visited[adjList[current][i]])
            {
                q.push(adjList[current][i]);
                visited[adjList[current][i]] = true;
            }
        }
    }

}

int main(void)
{
    fastIo

    int n, m, s, e;
    cin >> n;
    cin >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);
    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> s >> e;

        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    BFS(adjList, visited, count);

    cout << count - 1;

    return 0;
}