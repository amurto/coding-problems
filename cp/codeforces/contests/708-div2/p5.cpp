#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 5, inf = 1e9 + 5;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int fac(int x)
{
    map<int, int> mp;
    while (x > 1)
    {
        mp[lp[x]]++;
        x /= lp[x];
    }
    int res = 1;
    for (auto m : mp)
        if (m.second & 1)
            res *= m.first;
    if (res == 1)
        return 0;
    return res;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1), prev(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = fac(arr[i]);
        mp[arr[i]].pb(i);
    }
    for (auto m : mp)
        for (int i = m.second.size() - 1; i > 0; i--)
            prev[m.second[i]] = m.second[i - 1];
    vector<vector<int>> last(n + 1, vector<int>(k + 1)), dp(n + 1, vector<int>(k + 1, inf));
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(prev[i]);
        auto it = --st.end();
        for (int j = 0; *it > 0 && j <= k; j++, it--)
            last[i][j] = *it;
    }
    for (int j = 0; j <= k; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int x = 0; x <= k - j; x++)
                dp[i][x + j] = min(dp[i][x + j], 1 + dp[last[i][j]][x]);
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}