// https://codeforces.com/contest/238/problem/C
// World Eater Brothers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 3005;
vector<pii> g[N];

int dfs(int cur, int last)
{
    int cnt = 0;
    for (pii e : g[cur])
        if (e.first != last)
            cnt += e.second + dfs(e.first, cur);
    return cnt;
}

int traverse(int p1, int p2, int cur, int last, int d)
{
    int mx = 0;
    if (p2 >= p1)
        p1 = p2 = 0;
    if (d > 0)
        mx = max(mx, p1 - p2);
    for (pii e : g[cur])
        if (e.first != last)
            mx = max(mx, traverse(p1 + (e.second == 1), p2 + (e.second == 0), e.first, cur, d + 1));
    return mx;
}

int solve()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].pb({b, 0});
        g[b].pb({a, 1});
    }
    int mn = n - 1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = dfs(i, i);
        mn = min(mn, min(cnt, cnt - traverse(0, 0, i, i, 0)));
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}