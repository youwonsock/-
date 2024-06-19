#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<vector<int>> adjList(1001);
vector<bool> visited(1001, false);
vector<int> visitOrder;

void DFS(int start)
{
    visited[start] = true;
    visitOrder.push_back(start);

    for(int i = 0; i < adjList[start].size(); ++i)
    {
        if(!visited[adjList[start][i]])
            DFS(adjList[start][i]);
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    visitOrder.push_back(start);

    while (q.size() > 0)
    {
        int next = q.front(); q.pop();

        for(int i = 0; i < adjList[next].size(); ++i)
        {
            if(!visited[adjList[next][i]])
            {
                q.push(adjList[next][i]);
                visited[adjList[next][i]] = true;
                visitOrder.push_back(adjList[next][i]);
            }
        }
    }
}

int main(void)
{
    fastIo

    int n, m, startV;
    int u, v;
    cin >> n >> m >> startV;

    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < adjList.size(); ++i)
        sort(adjList[i].begin(), adjList[i].end()); 

    DFS(startV);
    for(int i = 0; i < visitOrder.size(); ++i)
        cout << visitOrder[i] << " ";
    cout << "\n";
    visitOrder.clear();
    fill(visited.begin(), visited.end(), false);

    BFS(startV);
    for(int i = 0; i < visitOrder.size(); ++i)
        cout << visitOrder[i] << " ";
    cout << "\n";

    return 0;
}
