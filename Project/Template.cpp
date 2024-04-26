#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n, int from, int by, int to, vector<vector<int>>& answer)
{
    if (n == 0)
        return;

    Hanoi(n - 1, from, to, by, answer);

    vector<int> temp = {from, to};
    answer.push_back(temp);

    Hanoi(n - 1, by, from, to, answer);
}

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;

    Hanoi(n, 1,2,3, answer);

    return answer;
}

int main(void) 
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    // Code here
    solution("Programmers");
    
    int a = 0;

    return 0;
}