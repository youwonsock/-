#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool solution(vector<string> phone_book) 
{
    unordered_map<string, int> map;

    for(int i = 0; i < phone_book.size(); ++i)
        map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); ++i)
    {
        for(int j = 0; j < phone_book[i].size() - 1; ++j)
        {
            string sub = phone_book[i].substr(0, j + 1);
        
            if(map[sub])
                return false;
        }
    }

    return true;
}