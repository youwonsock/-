#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>>& adjList, vector<bool>& visited)
{
    queue<int> q;
    q.push(1);

    fill(visited.begin(), visited.end(), false);
    visited[1] = true;

    while (q.size() > 0)
    {
        int current = q.front(); q.pop();
        visited[current] = true;

        for(int i = 0; i < adjList[current].size(); ++i)
        {
            if(!visited[adjList[current][i]])
            {
                q.push(adjList[current][i]);
            }
        }
        
    }
    
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = n;
    vector<vector<int>> adjList(n+1);
    vector<bool> visited(n+1);

    for(int i = 0; i < wires.size(); ++i)
    {
        adjList[wires[i][0]].push_back(wires[i][1]);
        adjList[wires[i][1]].push_back(wires[i][0]);
    }

    for(int i = 0; i < wires.size(); ++i)
    {
        adjList[wires[i][0]].erase(find(adjList[wires[i][0]].begin(), adjList[wires[i][0]].end(), wires[i][1]));
        adjList[wires[i][1]].erase(find(adjList[wires[i][1]].begin(), adjList[wires[i][1]].end(), wires[i][0]));
        
        BFS(adjList, visited);
        
        adjList[wires[i][0]].push_back(wires[i][1]);
        adjList[wires[i][1]].push_back(wires[i][0]);
    
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(visited[i])
                ++cnt;
        }

        int left = n-cnt;
        answer =  abs(cnt - left) < answer ? abs(cnt - left) : answer;
    }

    return answer;
}