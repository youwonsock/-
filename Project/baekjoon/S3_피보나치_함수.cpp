#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
int fib[41][2];
// fib[n][0]: 0�� ����ϴ� ����, fib[n][1]: 1�� ����ϴ� ����
 
int main() {
    int T, n;
    int t, i;   // t: Test case�� Ƚ��, i: fib[][]�� index
    fib[0][0] = 1;  // n = 0�� �� 0�� ����ϴ� ������ 1
    fib[0][1] = 0;  // n = 0�� �� 1�� ����ϴ� ������ 0
    fib[1][0] = 0;  // n = 1�� �� 0�� ����ϴ� ������ 0
    fib[1][1] = 1;  // n = 1�� �� 1�� ����ϴ� ������ 1
 
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d", &n);
        for (i = 2; i <= n; i++) {
            fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
            fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
        }
        printf("%d %d\n", fib[n][0], fib[n][1]);
    }
	return 0;
}