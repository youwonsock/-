#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m;
pair<int, int> arr[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Data
{
    int x = 0;
    int y = 0;
    int dis = 0;

    Data() {};
    Data(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

void BFS(vector<vector<int>>& map, vector<vector<bool>> visited, int x, int y)
{
    queue<Data> q;
    q.push(Data(x,y,0));

    visited[y][x] = true;

    while (!q.empty())
    {
        Data current = q.front(); q.pop();

        if(map[current.y][current.x] == 0)
            continue;

        map[current.y][current.x] = current.dis;

        for(int i = 0; i < 4; ++i)
        {
            int nextX = current.x + arr[i].first;
            int nextY = current.y + arr[i].second;
            
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
            {
                if(visited[nextY][nextX])
                    continue;
                
                visited[nextY][nextX] = true;
                q.push(Data(nextX, nextY, current.dis+1));
            }
        }
    }
    
}

int main(void)
{
    fastIo
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int, int> goalIDX;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
                map[i][j] = -1;
            else if(map[i][j] == 2)
            {
                goalIDX.first = i;
                goalIDX.second = j;
            }

        }    
    }

    BFS(map, visited, goalIDX.second, goalIDX.first);

    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << map[i][j] << ' ';
        }    
        cout << '\n';
    }

    return 0;
}