#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

inline void Swap(int& a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}

int GCD(int n, int m)
{
    while (true)
    {
        if(n < m)
            Swap(n,m);

        if(n % m == 0)
            return m;
        else
            n = n % m;
    }

    return -1;
}

int LCM(int n, int m)
{
    return n * m / GCD(n,m);
}

int main(void)
{
    fastIo

    int n,m;
    cin >> n >> m;

    cout << GCD(n,m) << "\n";
    cout << LCM(n,m) << "\n";

    return 0;
}