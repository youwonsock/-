#include <bits/stdc++.h>

using namespace std;

/*
�迭 arr�� �־����ϴ�. �迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�. �̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�. ��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�. ���� ���,

arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸� [4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
    �迭 arr�� ũ�� : 1,000,000 ������ �ڿ���
    �迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����
*/

/*
* 04/19
* 
* arr�� unique, erase�� ����Ͽ� 1�ٷ� �ذᵵ ����
*/

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int prev = arr[0];

    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] != prev)
        {
            answer.push_back(arr[i]);
            prev = arr[i];
        }
    }

    return answer;
}