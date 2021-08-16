// https://codeforces.com/contest/1366/problem/E
// Two Arrays

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int min_query(vector<int> &arr, int l, int r)
{
    int mn = 1e9 + 5;
    for (int i = l; i <= r; i++)
        mn = min(mn, arr[i]);
    return mn;
}

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> arr(n + 1), b(m + 1), pos(m + 1), dp(m + 1), pdp(m + 1), col(n + 1);
    map<int, int> id;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        id[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (id[arr[i]] > 0)
            pos[id[arr[i]]] = i;
    if (!is_sorted(pos.begin(), pos.end()))
        return 0;
    for (int i = 1; i <= pos[1]; i++)
        col[i] = 1;
    for (int i = m; i > 0; i--)
    {
        if (pos[i] == 0)
            return 0;
        int l = pos[i];
        while (l > 0 && arr[l] >= b[i])
        {
            col[l] = i;
            l--;
        }
        for (int j = pos[i] + 1; j <= n && col[j] == 0; j++)
            col[j] = i;
    }
    for (int i = 1; i <= n; i++)
        if (col[i] == 0 || arr[i] < b[col[i]])
            return 0;
    dp[0] = pdp[0] = 1;
    for (int i = 1; i <= n;)
    {
        int r = i, c = col[i];
        while (r <= n && col[r] == c)
            r++;
        for (int j = i; j < r; j++)
        {
            if (arr[j] == b[c])
                dp[c] = pdp[c - 1];
            if (c - 1 > 0 && j < pos[c])
                pdp[c - 1] = add(pdp[c - 1], pdp[c - 2]);
            pdp[c] = add(pdp[c], dp[c]);
        }
        pdp[c] = dp[c];
        i = r;
    }
    return pdp[m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}