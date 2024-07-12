#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& computers, vector<bool>& visited, int& visitedNum, int start)
{
    queue<int> q;
    q.push(start);

    visited[start] = true;
    ++visitedNum;
    
    while (!q.empty())
    {
        int current = q.front(); q.pop();

        for(int i = 0; i < computers.size(); ++i)
        {
            if(i == current)
                continue;

            if(computers[i][current] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                ++visitedNum;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    int visitedNum = 0;
    vector<bool> visited(n, false);

    while(visitedNum < n)
    {
        int start = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                start = i;
                break;
            }
        }

        BFS(computers, visited, visitedNum, start);
        ++answer;
    }

    return answer;
}