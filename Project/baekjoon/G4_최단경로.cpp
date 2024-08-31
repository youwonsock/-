#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x7FFFFFFF;

void Dijkstra(vector<vector<pair<int, int>>>& adjList, vector<int>& dist, int start)
{
    priority_queue<pair<int, int>> heap;
    heap.push(make_pair(start, 0));

    while (!heap.empty())
    {
        int current = heap.top().first;
        int cost = heap.top().second; heap.pop();

        for(int i = 0; i < adjList[current].size(); ++i)
        {
            int next = adjList[current][i].first;
            int nextCost = adjList[current][i].second;

            if(dist[next] > cost + nextCost)
            {
                dist[next] = cost + nextCost;
                heap.push(make_pair(next, cost + nextCost));
            }
        }
    }
    
}

int main(void)
{
    fastIo

    int v, e, k;
    cin >> v >> e;
    cin >> k;

    vector<int> dist(v+1, INF);
    dist[k] = 0;
    vector<vector<pair<int, int>>> adjList(v+1, vector<pair<int, int>>());

    for(int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back(make_pair(v, w));
    }

    Dijkstra(adjList, dist, k);

    for(int i = 1; i < v+1; ++i)
    {
        if(dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }

    return 0;
}
