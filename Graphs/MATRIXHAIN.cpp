#include <iostream>
using namespace std;
int dp[100][100];
int MCM_mem(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], MCM_mem(p, i, k) + MCM_mem(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MCM(int *p, int n)
{
    int i = 1, j = n - 1;
    return MCM_mem(p, i, j);
}
int main()
{
    int arr[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum number of multiplications is " << MCM(arr, n);
}