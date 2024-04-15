#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards)
{
    vector<int> answer;
    int cnt = 0;
    int cur = 0;

    for (int i = 0; i < cards.size(); ++i)
    {
        cnt = 0;
        cur = cards[i] - 1;

        while (cards[cur] != 0)
        {
            int temp = cur;
            cur = cards[cur] - 1;
            cards[temp] = 0;

            ++cnt;
        }

        answer.push_back(cnt);
    }
    sort(answer.begin(), answer.end());

    return answer[answer.size() - 1] * answer[answer.size() - 2];
}
