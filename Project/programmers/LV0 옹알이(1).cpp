#include <bits/stdc++.h>

using namespace std;

/*
�Ӿ��̴� �¾ �� 6���� �� ��ī�� ������ �ֽ��ϴ�. ��ī�� ���� "aya", "ye", "woo", "ma" �� ���� ������ �ִ� �� ���� ����� ������(�̾� ����) �����ۿ� ���� ���մϴ�. ���ڿ� �迭 babbling�� �Ű������� �־��� ��, �Ӿ����� ��ī�� ������ �� �ִ� �ܾ��� ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
    1 �� babbling�� ���� �� 100
    1 �� babbling[i]�� ���� �� 15
    babbling�� �� ���ڿ����� "aya", "ye", "woo", "ma"�� ���� �ִ� �� ������ �����մϴ�.
    ��, �� ���ڿ��� ������ ��� �κ� ���ڿ� �߿��� "aya", "ye", "woo", "ma"�� �� ������ �����մϴ�.
    ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
*/

/*
* 04/20
* 
*/


int solution(vector<string> babbling) {

    int answer = 0;
    bool flag = true;
    string words[4] = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); ++i)
    {
        flag = true;
        for (int j = 0; j < babbling[i].size();)
        {
            if (babbling[i].substr(j, 3) == "aya")
                j += 3;
            else if (babbling[i].substr(j, 2) == "ye")
                j += 2;
            else if (babbling[i].substr(j, 3) == "woo")
                j += 3;
            else if (babbling[i].substr(j, 2) == "ma")
                j += 2;
            else
            {
                flag = false;
                break;
            }
        }

        if (flag)
            ++answer;
    }

    return answer;
}