#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

template <typename T1, typename T2>
bool compare(pair<T1, T2> first, pair<T1, T2> second)
{
    if (first.first > second.first)
        return true;
    else if (first.first < second.first)
        return false;
    else
        return first.second < second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    vector<pair<int, string>> ranking;
    unordered_map<string, vector<pair<int, int>>> hash;

    for (int i = 0; i < genres.size(); ++i)
        hash[genres[i]].push_back(make_pair(plays[i], i));

    for (auto& genre : hash)
    {
        int sum = 0;
        for (auto n : genre.second)
            sum += n.first;
        ranking.push_back(make_pair(sum, genre.first));

        sort(genre.second.begin(), genre.second.end(), compare<int, int>);
    }
    sort(ranking.begin(), ranking.end(), compare<int, string>);

    for (int i = 0; i < ranking.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (j >= hash[ranking[i].second].size())
                break;

            answer.push_back(hash[ranking[i].second][j].second);
        }
    }

    return answer;
}