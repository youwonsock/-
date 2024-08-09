
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int m, n;
pair<int, int> arr[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Data
{
    int x = 0;
    int y = 0;

    Data() {};
    Data(int x, int y) : x(x), y(y) {};
};

int BFS(vector<vector<int>>& farm, vector<vector<bool>>& visited, const vector<Data>& ripes)
{
    int day = 0;
    int currentQ = 0;
    queue<Data> q[2];

    for(int i = 0; i < ripes.size(); ++i)
    {
        q[currentQ].push(Data(ripes[i].x, ripes[i].y));
        visited[ripes[i].y][ripes[i].x] = true;
    }

    while (!q[0].empty() || !q[1].empty())
    {
        while (!q[currentQ].empty())
        {
            Data current = q[currentQ].front(); q[currentQ].pop();

            if(farm[current.y][current.x] == -1)
                continue;

            farm[current.y][current.x] = 1;

            int nextQ = (currentQ + 1) % 2;
            for(int i = 0; i < 4; ++i)
            {
                int nextX = current.x + arr[i].first;
                int nextY = current.y + arr[i].second;
                
                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
                {
                    if(visited[nextY][nextX])
                        continue;
                    
                    visited[nextY][nextX] = true;
                    q[nextQ].push(Data(nextX, nextY));
                }
            }
        }

        currentQ = (currentQ + 1) % 2;
        if(!q[currentQ].empty())
            ++day;
    }

    return day;
}

int main(void)
{
    fastIo

    cin >> m >> n;  
    vector<vector<int>> farm(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<Data> ripes;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> farm[i][j];

            if(farm[i][j])
                ripes.push_back(Data(j,i));
        }
    }
    
    int day = BFS(farm, visited, ripes);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(farm[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << day << '\n';

    return 0;
}