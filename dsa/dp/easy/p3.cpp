// https://practice.geeksforgeeks.org/problems/stickler-theif/0
// Stickler Thief

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// DP with O(n) space
int maxMoney(int *a, int *DP, int n)
{
    if (n < 0)
        return 0;
    if (DP[n] < 0)
        DP[n] = max(maxMoney(a, DP, n - 1), a[n] + maxMoney(a, DP, n - 2));
    return DP[n];
}

// 4 variable technique
int maxMoneyNoSpace(int a[], int n)
{
    int inc_cur = a[0], ex_cur = 0;
    int inc_prev = inc_cur;
    int ex_prev = ex_cur;
    for (int i = 1; i < n; i++)
    {
        ex_cur = max(inc_prev, ex_prev);
        inc_cur = ex_prev + a[i];
        ex_prev = ex_cur;
        inc_prev = inc_cur;
    }
    return max(inc_cur, ex_cur);
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
        // memset(DP, -1, sizeof(DP));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // cout<<maxMoney(a, DP, n-1)<<endl;
        cout << maxMoneyNoSpace(a, n) << endl;
    }
    return 0;
}