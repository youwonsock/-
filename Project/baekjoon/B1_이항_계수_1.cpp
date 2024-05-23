#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int BinomialCoefficient(int n, int k) {
	int C[100][100];
	int m;
	for (int i = 0; i <= n; i++) 
    {
		m = (i < k) ? i : k;

		for (int j = 0; j <= m; j++) 
        {
			if (j == 0 || j == i) 
                C[i][j] = 1;
			else 
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return C[n][k];
}

int main(void)
{
    fastIo

    int n, k;
    cin >> n >> k;

    cout << BinomialCoefficient(n,k);

    return 0;
}