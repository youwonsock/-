#include <string>
#include <vector>

using namespace std;

const int INF = 9999;

void FloydWarshall(int n, vector<vector<int>>& adjMat)
{
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;

    vector<vector<int>> adjMat(n+1, vector<int>(n+1, INF));

    for(int i = 1; i <= n; ++i)
        adjMat[i][i] = 0;

    for(int i = 0; i < results.size(); ++i)
        adjMat[results[i][0]][results[i][1]] = 1;
    
    FloydWarshall(n ,adjMat);

    for(int i = 1; i <= n; ++i)
    {
        int cnt = 0;

        for(int j = 1; j <= n; ++j)
        {
            if(i == j)
                continue;

            if(adjMat[i][j] != INF || adjMat[j][i] != INF)
                ++cnt;
        }

        if(cnt == n - 1)
            ++answer;
    }

    return answer;
}