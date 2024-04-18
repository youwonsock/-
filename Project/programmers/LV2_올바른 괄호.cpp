#include <bits/stdc++.h>

using namespace std;

/*
��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���

"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, �ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
    ���ڿ� s�� ���� : 100,000 ������ �ڿ���
    ���ڿ� s�� '(' �Ǵ� ')' �θ� �̷���� �ֽ��ϴ�.
*/

/*
* ������ �̿��ϰų�
* ���� üũ�ϴ� ������� �ذᰡ��
*/
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