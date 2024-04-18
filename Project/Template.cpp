#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int prev = arr[0];

    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] != prev)
        {
            answer.push_back(arr[i]);
            prev = arr[i];
        }
    }

    return answer;
}

int main(void) 
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    // Code here
    solution({ {0, 0, 0, 0, 0},{0, 0, 0, 0, 0},{0, 0, 0, 0, 0},{0, 0, 1, 0, 0},{0, 0, 0, 0, 0} });
    
    int a = 0;

    return 0;
}