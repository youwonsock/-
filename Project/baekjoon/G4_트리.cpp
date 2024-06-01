#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int NODENUM = 502;

vector<int> adjMat[NODENUM];
bool visited[NODENUM];
bool isTree = true;
int treeCount = 0;

void Dfs(int current, int parent) 
{
    visited[current] = true;

    for(int i = 0; i < adjMat[current].size(); ++i) 
    {
        if(adjMat[current][i] == parent)
            continue;

        int next = adjMat[current][i];

        if(!visited[next])
            Dfs(next, current);
        else
            isTree = false;
    }
}

int main(void)
{
    fastIo

    int cnt = 1;
    while(true)
    {
        int n,m;
        cin >> n >> m;

        if(!n && !m)
            break;

        for(int i = 1; i <= NODENUM; ++i)
        {
            adjMat[i].clear();
            visited[i] = false;
        }
        treeCount = 0;

        for(int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;

            adjMat[a].push_back(b);
            adjMat[b].push_back(a);
        }

        for(int i = 1; i <= n; ++i)
        {
            isTree = true;
            Dfs(i,-1);

            if(isTree)
                ++treeCount;
        }

        switch (treeCount)
        {
        case 0:
            cout << "Case " << cnt << ": No trees.\n";
            break;
        case 1:
            cout << "Case " << cnt << ": There is one tree.\n";
            break;
        default:
            cout << "Case " << cnt << ": A forest of " << treeCount << " trees.\n";
            break;
        }

        ++cnt;
    }


    return 0;
}

