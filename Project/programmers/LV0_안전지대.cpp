#include <bits/stdc++.h>

using namespace std;

/*
지뢰가 있는 지역과 지뢰에 인접한 위, 아래, 좌, 우 대각선 칸을 모두 위험지역으로 분류합니다.

지뢰는 2차원 배열 board에 1로 표시되어 있고 board에는 지뢰가 매설 된 지역 1과, 지뢰가 없는 지역 0만 존재합니다.
지뢰가 매설된 지역의 지도 board가 매개변수로 주어질 때, 안전한 지역의 칸 수를 return하도록 solution 함수를 완성해주세요.

제한사항
    board는 n * n 배열입니다.
    1 ≤ n ≤ 100
    지뢰는 1로 표시되어 있습니다.
    board에는 지뢰가 있는 지역 1과 지뢰가 없는 지역 0만 존재합니다.
*/

/*
* 04/18 
* 
* 9방 탐색을 위해 배열을 만들어두면 for문을 줄일 수 있지만
* 어차피 9번만 돌기에 그냥 for문 사용
*/


int solution(vector<vector<int>> board) {
    int answer = 0;
    int mine = 0;
    int size = board.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] == 1)
            {
                ++mine;

                // check near area
                for (int w = i - 1; w <= i + 1; ++w)
                {
                    if (w < 0 || w >= size)
                        continue;

                    for (int x = j - 1; x <= j + 1; ++x)
                    {
                        if (x < 0 || x >= size)
                            continue;

                        if (board[w][x] == 0)
                        {
                            ++mine;
                            board[w][x] = 2;
                        }
                    }
                }
            }
        }
    }

    return size * size - mine;
}
