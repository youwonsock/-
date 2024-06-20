#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FloydWarshall(vector<vector<int>>& adjMat)
{
    for(int k = 0; k < adjMat.size(); ++k)
    {
        for(int i = 0; i < adjMat.size(); ++i)
        {
            for(int j = 0; j < adjMat.size(); ++j)
            {
                if(adjMat[i][k] && adjMat[k][j])
                    adjMat[i][j] = 1; 
            }
        }   
    }
}

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cin >> adjMat[i][j];
    }

    FloydWarshall(adjMat);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << adjMat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
