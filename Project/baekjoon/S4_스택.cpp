#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Stack
{
public:
    Stack()
    {
        arr = new int[stackSize];
    }

    void Commend(string cmd)
    {
        if(cmd == "push")
            Push();
        else if(cmd == "pop")
            Pop();
        else if(cmd == "size")
            Size();
        else if(cmd == "empty")
            Empty();
        else if(cmd == "top")
            Top();
    }

private:
    void Push()
    {
        int n;
        cin >> n;

        if(stackSize - ++top == 0)
        {
            stackSize *= 2;
            int* temp = new int[stackSize];

            memcpy(temp, arr, (stackSize/2) * sizeof(int));

            delete[] arr;
            arr = temp;
        }

        arr[top] = n;
    }

    void Pop()
    {
        if(top < 0)
        {
            cout << -1 << "\n";
            return;
        }

        cout << arr[top--] << "\n";
    }

    void Size()
    {
        cout << top + 1 << "\n";
    }

    void Empty()
    {
        if(top == -1)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    void Top()
    {
        if(top == -1)
            cout << -1 << "\n";
        else
            cout << arr[top] << "\n";
    }

private:
    int* arr;

    int stackSize = 5;
    int top = -1;
};

int main(void)
{
    fastIo

    int n;
    cin >> n;
    Stack stack;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        stack.Commend(str);
    }

    return 0;
}
