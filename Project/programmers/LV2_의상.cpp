#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hash;

    for(int i = 0; i < clothes.size(); ++i)
        hash[clothes[i][1]] += 1;
    
    for(auto n : hash)
        answer *= (n.second + 1);

    return answer - 1;
}