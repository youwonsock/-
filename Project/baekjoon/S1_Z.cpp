#include <iostream>
#include <cmath>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, r, c;
int answer = 0;

void Square(int x, int y, int size)
{
    if(c==x && r==y)
    {
        cout << answer;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y)
    {
        Square(x, y, size / 2);
        Square(x + size / 2, y, size / 2);
        Square(x, y + size / 2, size / 2);
        Square(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        answer += size * size;
    }
}

int main(void)
{
    fastIo

    cin >> n >> r >> c;

    Square(0, 0, pow(2, n));

    return 0;
}


