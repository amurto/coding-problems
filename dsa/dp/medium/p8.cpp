// https://practice.geeksforgeeks.org/problems/champagne-overflow/0
// Water Overflow

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

float DP[1001][1001];

void FW(float k, int i, int j)
{
    if (k + DP[i][j] > 1)
    {
        k = k - (1 - DP[i][j]);
        DP[i][j] = 1;
        FW(k / 2, i + 1, j);
        FW(k / 2, i + 1, j + 1);
    }
    else
    {
        DP[i][j] += k;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        float k;
        int i, j;
        cin >> k >> i >> j;
        memset(DP, 0, sizeof(DP));
        FW(k, 0, 0);
        cout<<setprecision(6)<<DP[i-1][j-1]<<endl;
    }
    return 0;
}