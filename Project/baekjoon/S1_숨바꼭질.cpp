#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, k;

void BFS()
{
    queue<pair<int, int>> q;
    bool visited[100001] = {false, };
    visited[n] = true;

    q.push(make_pair(n, 0));

    while (!q.empty())
    {
        pair<int, int> current = q.front(); q.pop();
    
        if(current.first == k)
        {
            cout << current.second;
            break;
        }
        else
        {
            if(current.first + 1 >= 0 && current.first + 1 < 1000001 && !visited[current.first + 1])
            {
                q.push(make_pair(current.first + 1, current.second + 1));
                visited[current.first+1] = true;
            }
            if(current.first - 1 >= 0 &&current.first - 1 < 100001 && !visited[current.first - 1])
            {
                q.push(make_pair(current.first - 1, current.second + 1));
                visited[current.first-1] = true;
            }

            if(current.first * 2 >= 0 && current.first * 2 < 100001 && !visited[current.first * 2])
            {
                q.push(make_pair(current.first * 2, current.second + 1));
                visited[current.first*2] = true;
            }
        }
    }
}


int main(void)
{
    fastIo

    cin >> n >> k;
    BFS();

    return 0;
}