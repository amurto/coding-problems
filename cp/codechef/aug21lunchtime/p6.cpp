#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 105;
int parent[N], cap[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

bool merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return false;

    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

int calc(vector<vector<int>> &dp, string &s1, string &s2, int m, int n, int i, int j)
{
    if (i == m || j == n)
        return 0;
    if (dp[i][j] == -1)
        dp[i][j] = (s1[i] == s2[j]) ? 1 + calc(dp, s1, s2, m, n, i + 1, j + 1) : 0;
    return dp[i][j];
}

int findLCS(string &s1, string &s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int mx = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mx = max(mx, calc(dp, s1, s2, m, n, i, j));
    return mx;
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<pii> edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = findLCS(arr[i], arr[j]);
            // d(i, j);
            // d(dp[i][j]);
            edges.pb({i, j});
        }
    }
    sort(edges.begin(), edges.end(), [&](pii &e1, pii &e2)
         { return dp[e1.first][e1.second] > dp[e2.first][e2.second]; });
    init(n);
    for (pii e : edges)
        if (merge(e.first, e.second))
            res += 1ll * dp[e.first][e.second];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}