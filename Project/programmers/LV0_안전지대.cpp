#include <bits/stdc++.h>

using namespace std;

/*
���ڰ� �ִ� ������ ���ڿ� ������ ��, �Ʒ�, ��, �� �밢�� ĭ�� ��� ������������ �з��մϴ�.

���ڴ� 2���� �迭 board�� 1�� ǥ�õǾ� �ְ� board���� ���ڰ� �ż� �� ���� 1��, ���ڰ� ���� ���� 0�� �����մϴ�.
���ڰ� �ż��� ������ ���� board�� �Ű������� �־��� ��, ������ ������ ĭ ���� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
    board�� n * n �迭�Դϴ�.
    1 �� n �� 100
    ���ڴ� 1�� ǥ�õǾ� �ֽ��ϴ�.
    board���� ���ڰ� �ִ� ���� 1�� ���ڰ� ���� ���� 0�� �����մϴ�.
*/

/*
* 04/18 
* 
* 9�� Ž���� ���� �迭�� �����θ� for���� ���� �� ������
* ������ 9���� ���⿡ �׳� for�� ���
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
