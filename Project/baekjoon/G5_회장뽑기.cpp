#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 9999;

void Floyd(vector<vector<int>>& adjMat)
{
    for(int k = 1; k < adjMat.size(); ++k)
    {
        for(int i = 1; i < adjMat.size(); ++i)
        {
            for(int j = 1; j < adjMat.size(); ++j)
            {
                if(adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }    
        }
    }
}

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<vector<int>> adjMat(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < n+1; ++i)
        adjMat[i][i] = 0;

    int u, v;
    while(true)
    {
        cin >> u >> v;

        if(u == -1 && v == -1)
            break;

        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    int min = INF;
    Floyd(adjMat);

    // find min value
    for(int i = 1; i < n+1; ++i)
    {
        int lineMax = 0;

        for(int j = 1; j < n+1; ++j)
        {
            if(adjMat[i][j] > lineMax)
                lineMax = adjMat[i][j];
        }  
        
        min = lineMax < min ? lineMax : min;
    }

    // get candidate idx
    vector<int> candidates;
    bool flag = false;
    for(int i = 1; i < n+1; ++i)
    {
        flag = false;

        for(int j = 1; j < n+1; ++j)
        {
            if(adjMat[i][j] > min)
                flag = true;
        }   

        if(!flag)
            candidates.push_back(i);
    }

    //print
    cout << min << " " << candidates.size() << "\n";
    for(int i = 0; i < candidates.size(); ++i)
        cout << candidates[i] << " ";

    return 0;
}
