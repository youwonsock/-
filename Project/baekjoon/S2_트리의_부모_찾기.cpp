#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define MAX 100001

int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void Dfs(int k) {
    visited[k]=true;

    for(int i=0; i < v[k].size(); ++i) 
    {
        int next = v[k][i];

        if(!visited[next]) 
        {
            arr[next]=k;
            Dfs(next);
        }
    }
}

int main(void)
{
    fastIo

    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) 
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    Dfs(1);

    for(int i = 2; i <= N; ++i) 
        cout << arr[i] << "\n";
    
    return 0;
}
