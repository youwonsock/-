#include <iostream>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 9999;

void Dijkstra(int start, vector<vector<int>>& adjMat, vector<int>& distArr, vector<bool>& visited)
{
    visited[start] = true;
    for(int i = 0; i < adjMat[0].size(); ++i)
        distArr[i] = adjMat[start][i];

    for(int i = 0; i < adjMat[0].size(); ++i)
    {
        // find min
        int current = 0;
        int min = INF;
        for(int k = 0; k < adjMat[0].size(); ++k)
        {
            if(distArr[k] < min && visited[k] == false)
            {
                min = distArr[k];
                current = k;
            }
        }
        visited[current] = true;


        for(int j = 0; j < adjMat[0].size(); ++j)
        {
            if(!visited[j])
            {
                if(distArr[current] + adjMat[current][j] < distArr[i])
                    distArr[j] = distArr[current] + adjMat[current][j];
            }
        }
    }

}

int main(void)
{
    fastIo

    int n, e;
    cin >> n >> e;

    vector<bool> visited(n+1, false);
    vector<int> distArr(n+1, INF);
    vector<vector<int>> adjMat(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < n+1; ++i)
        adjMat[i][i] = 0;

    for(int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adjMat[a][b] = c;
        adjMat[b][a] = c;
    }

    int v1, v2;
    vector<int> arr(1, 4);
    cin >> arr[1] >> arr[2];
    arr[3] = n;

    int dist1 = 0;
    for(int i = 0; i < 2; ++i)
    {
        fill(distArr.begin(), distArr.end(), INF);
        fill(visited.begin(), visited.end(), false);
        
        Dijkstra(arr[i], adjMat, distArr, visited);
        dist1 += distArr[arr[i+1]];
    }
    
    int dist2 = 0;
    int temp = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
    for(int i = 0; i < 2; ++i)
    {
        fill(distArr.begin(), distArr.end(), INF);
        fill(visited.begin(), visited.end(), false);
 
        Dijkstra(arr[i], adjMat, distArr, visited);
        dist2 += distArr[arr[i+1]];
    }

    int dist = dist1 > dist2 ? dist2 : dist1;

    if(dist >= INF)
        cout << -1 << '\n';
    else
        cout << dist << '\n';

    return 0;
}
