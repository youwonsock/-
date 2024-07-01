#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 8;

int answer = 0;
bool visited[MAX] = {false,};

void DFS(int cnt, int k, vector<vector<int>>& dungeons)
{
    if(cnt > answer)
        answer = cnt;

    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            DFS(cnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    DFS(0, k, dungeons);

    return answer;
}