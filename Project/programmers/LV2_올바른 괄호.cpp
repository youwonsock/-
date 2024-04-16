#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int rightNum = 0;

    stack<char> bucket;
    for (int i = 0; i < s.size(); ++i)
        bucket.push(s[i]);

    while (!bucket.empty())
    {
        if (bucket.top() == ')')
            ++rightNum;
        else
        {
            --rightNum;

            if (rightNum < 0)
                return false;
        }

        bucket.pop();
    }

    if (rightNum != 0)
        answer = false;

    return answer;
}