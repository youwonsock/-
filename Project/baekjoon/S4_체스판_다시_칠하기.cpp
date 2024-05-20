#include <bits/stdc++.h>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int CompareWB(std::vector<string>& board, int x, int y);
int CompareBW(std::vector<string>& board, int x, int y);

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    int less;
    int answer = 9999;
    cin >> n >> m;

    std::vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i <= n - 8; ++i)
    {
        for (int j = 0; j <= m - 8; ++j)
        {
            less = min(CompareBW(board, j, i), CompareWB(board, j, i));
            answer = min(answer, less);
        }
    }

    cout << answer;
    return 0;
}

int CompareWB(std::vector<string>& board, int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i + y][j + x] != WB[i][j])
                ++count;
        }
    }

    return count;
}

int CompareBW(std::vector<string>& board, int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i + y][j + x] != BW[i][j])
                ++count;
        }
    }

    return count;
}