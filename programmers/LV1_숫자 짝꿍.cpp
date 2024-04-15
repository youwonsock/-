#include <bits/stdc++.h>

using namespace std;


string solution(string X, string Y)
{
    vector<int> bucket1(10, 0);
    vector<int> bucket2(10, 0);
    string answer = "";

    for (int i = 0; i < X.size(); ++i)
        ++bucket1[X[i] - 48];
    for (int i = 0; i < Y.size(); ++i)
        ++bucket2[Y[i] - 48];

    for (int i = 9; i >= 0; i--) {
        int num = min(bucket1[i], bucket2[i]);
        for (int j = 0; j < num; j++)
            answer += to_string(i);
    }

    if (answer == "") return "-1";
    else if (answer[0] == '0') return "0";
    else return answer;
}
