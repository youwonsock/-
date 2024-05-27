
#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class User
{
public:
    User(int age, string name) : age(age), name(name) {}

    void Print()
    {
        cout << age << " " << name << "\n";
    }

public:
    int age;
    string name;
};

void Merge(vector<User>& userList, int first, int mid, int last)
{
    vector<User> sorted;

    int firstIDX = first;
    int secondIDX = mid + 1;

    while (firstIDX <= mid && secondIDX <= last)
    {
        if (userList[firstIDX].age <= userList[secondIDX].age)
        {
            sorted.emplace_back(userList[firstIDX].age, userList[firstIDX].name);
            ++firstIDX;
        }
        else
        {
            sorted.emplace_back(userList[secondIDX].age, userList[secondIDX].name);
            ++secondIDX;
        }
    }

    if (firstIDX > mid)
    {
        while (secondIDX <= last)
        {
            sorted.emplace_back(userList[secondIDX].age, userList[secondIDX].name);
            ++secondIDX;
        }
    }
    else
    {
        while (firstIDX <= mid)
        {
            sorted.emplace_back(userList[firstIDX].age, userList[firstIDX].name);
            ++firstIDX;
        }
    }

    for (int i = first, j = 0; i <= last; ++i, ++j)
        userList[i] = sorted[j];
}

void MergeSort(vector<User>& userList, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(userList, first, mid);
        MergeSort(userList, mid + 1, last);
        Merge(userList, first, mid, last);
    }
}

int main(void)
{
    fastIo
        int n, age;
    string name;
    vector<User> userList;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> age >> name;
        userList.emplace_back(age, name);
    }
    MergeSort(userList, 0, userList.size() - 1);

    for (int i = 0; i < n; ++i)
        userList[i].Print();

    return 0;
}