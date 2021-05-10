// https://codeforces.com/contest/1416/problem/C
// XOR Inverse

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
// set LGN to 60 for long long
const int N = 3e5 + 5, LGN = 30;
int t[N * LGN][2], cnt[N * LGN], mask = 1;
vector<int> ids[N * LGN];

void init()
{
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
}

void insert(int x, int v, int bit, int id)
{
    if (bit == -1)
    {
        cnt[v]++;
        ids[v].pb(id);
        return;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] == 0)
        t[v][child] = ++mask;
    insert(x, t[v][child], bit - 1, id);
    // keep running sum
    cnt[v]++;
    ids[v].pb(id);
}

void dfs(vector<vector<ll>> &dp, int v, int bit)
{
    if (bit == -1)
        return;
    for (int j = 0; j < 2; j++)
        if (t[v][j] > 0)
            dfs(dp, t[v][j], bit - 1);
    if (t[v][0] > 0 && t[v][1] > 0)
    {
        for (int i : ids[t[v][0]])
        {
            int lb = lower_bound(ids[t[v][1]].begin(), ids[t[v][1]].end(), i) - ids[t[v][1]].begin();
            dp[bit][0] += 1ll * lb;
        }
        for (int i : ids[t[v][1]])
        {
            int lb = lower_bound(ids[t[v][0]].begin(), ids[t[v][0]].end(), i) - ids[t[v][0]].begin();
            dp[bit][1] += 1ll * lb;
        }
    }
}

void solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        insert(arr[i], 1, LGN, i);
    }
    vector<vector<ll>> dp(LGN + 1, vector<ll>(2));
    dfs(dp, 1, LGN);
    ll inv = 0;
    for (int i = LGN; i >= 0; i--)
    {
        if (dp[i][0] > dp[i][1])
        {
            inv += dp[i][1];
            res |= (1 << i);
        }
        else
            inv += dp[i][0];
    }
    cout << inv << " " << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}