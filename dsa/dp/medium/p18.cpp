// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
// Minimum number of jumps

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MNJ(int *a, int *DP, int cur, int n)
{
    if (cur >= n)
        return 0;
    if (a[cur] == 0)
        return -2;
    if (DP[cur] == -1)
    {
        for (int i = cur + 1; i <= min(cur + a[cur], n); i++)
        {
            int temp = MNJ(a, DP, i, n);
            if (temp == -2)
                DP[cur] = (DP[cur] == -1) ? -2 : DP[cur];
            else
                DP[cur] = (DP[cur] == -1 || DP[cur] == -2) ? 1 + temp : min(DP[cur], 1 + temp);
        }
    }
    return DP[cur];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n], DP[n];
        memset(DP, -1, sizeof(DP));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = MNJ(a, DP, 0, n - 1);
        if (ans == -2)
            ans++;
        cout << ans << endl;
    }
    return 0;
}