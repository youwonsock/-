#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
int fib[41][2];
// fib[n][0]: 0을 출력하는 개수, fib[n][1]: 1을 출력하는 개수
 
int main() {
    int T, n;
    int t, i;   // t: Test case의 횟수, i: fib[][]의 index
    fib[0][0] = 1;  // n = 0일 때 0을 출력하는 개수는 1
    fib[0][1] = 0;  // n = 0일 때 1을 출력하는 개수는 0
    fib[1][0] = 0;  // n = 1일 때 0을 출력하는 개수는 0
    fib[1][1] = 1;  // n = 1일 때 1을 출력하는 개수는 1
 
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