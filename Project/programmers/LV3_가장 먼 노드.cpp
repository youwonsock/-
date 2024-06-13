#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& adjList, vector<int>& dis)
{
    queue<int> q;

    dis[1] = 0;
    q.push(1);

    while (q.size() > 0)
    {
        int current = q.front();
        q.pop();

        for(int i = 0; i < adjList[current].size(); ++i)
        {
            if(dis[adjList[current][i]] == -1)
            {
                dis[adjList[current][i]] = dis[current] + 1;
                q.push(adjList[current][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    
    vector<vector<int>> adjList(n+1);
    vector<int> dis(n+1, -1);
    queue<int> q;

    for(int i = 0; i < edge.size(); ++i)
    {
        adjList[edge[i][0]].push_back(edge[i][1]);
        adjList[edge[i][1]].push_back(edge[i][0]);
    }

    BFS(adjList, dis);

    int max = *max_element(dis.begin(), dis.end());
    for(int i = 0; i < dis.size(); ++i)
    {
        if(max == dis[i])
            ++answer;
    }

    return answer;
}