#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class id
{
public:
    int i = 0, v = 0;
    id() {}
    id(int i, int v) : i(i), v(v) {}
    bool operator<(const id &other) const
    {
        return v < other.v;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    int k[n + 1], a[n + 1][2], b[n + 1][2], last[n + 1][2], s[n + 1][2];
    k[0] = a[0][0] = b[0][0] = a[0][1] = b[0][1] = 0;
    for (int i = 1; i <= n; i++)
        cin >> k[i] >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
    vector<multiset<id>> st(2);
    st[0].insert(id(0, 0));
    st[1].insert(id(0, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            st[j].insert(id(i, k[i]));
            while (!st[j].empty() && st[j].begin()->v < a[i][j])
            {
                id idx = *st[j].begin();
                st[j].erase(st[j].begin());
                last[idx.i][j] = i - 1;
            }
            while (!st[j].empty() && st[j].rbegin()->v > b[i][j])
            {
                id idx = *st[j].rbegin();
                st[j].erase(--st[j].end());
                last[idx.i][j] = i - 1;
            }
        }
    }
    for (int j = 0; j < 2; j++)
    {
        while (!st[j].empty())
        {
            id idx = *st[j].begin();
            st[j].erase(st[j].begin());
            last[idx.i][j] = n;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, -1)), u(n + 1, vector<int>(2, -1));
    if (last[0][1] >= 0)
        dp[0][0] = last[0][0];
    if (last[0][0] >= 0)
        dp[0][1] = last[0][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // change jth side
            if (dp[i - 1][!j] >= i)
            {
                u[i][j] = j;
                dp[i][j] = last[i][j];
            }
            if (last[i][!j] >= i && dp[i - 1][j] > dp[i][j])
            {
                u[i][j] = !j;
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][0] < n && dp[n][1] < n)
    {
        cout << "No\n";
        return;
    }
    int p = 0;
    if (dp[n][p] < n)
        p ^= 1;
    int cur = n;
    vector<int> seq;
    while (cur != 0)
    {
        seq.pb(u[cur][p]);
        if (u[cur][p] == p)
            p ^= 1;
        cur--;
    }
    reverse(seq.begin(), seq.end());
    cout << "Yes\n";
    for (int i : seq)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}