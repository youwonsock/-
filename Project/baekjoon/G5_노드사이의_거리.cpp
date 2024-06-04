#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int SIZE = 1003;

vector< pair<int, int> > adjMat[SIZE];
bool isVisited[SIZE];

void BFS(int start, int end)
{
    queue<pair<int ,int>> q;
    q.push(make_pair(start, 0));

    fill(isVisited, isVisited+SIZE ,false);
    isVisited[start] = true;

    while (true)
    {
        pair<int, int> current = q.front(); q.pop();
        isVisited[current.first] = true; 

        if(current.first == end)
        {
            cout << current.second << "\n";
            break;
        }

        for(int i = 0; i < adjMat[current.first].size(); ++i)
        {
            if(!isVisited[adjMat[current.first][i].first])
                q.push(make_pair(adjMat[current.first][i].first, current.second + adjMat[current.first][i].second));
        }
    }
}

int main(void)
{
    fastIo

    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n-1; ++i)
    {
        int a,b,dis;
        cin >> a >> b >> dis;

        adjMat[a].push_back(make_pair(b,dis));
        adjMat[b].push_back(make_pair(a,dis));
    }

    for(int i = 0; i < m; ++i)
    {
        int s, e;
        cin >> s >> e;

        BFS(s,e);
    }

    return 0;
}
