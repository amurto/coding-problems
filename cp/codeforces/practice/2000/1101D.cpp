// https://codeforces.com/contest/1101/problem/D
// GCD Counting

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
// O(n)
vector<int> g[N], lp(N + 1), pr;
int arr[N];

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

int calc(int &res, int cur, int last, int v)
{
    while (arr[cur] % v == 0)
        arr[cur] /= v;
    vector<int> seq;
    seq.pb(0);
    seq.pb(0);
    for (int e : g[cur])
        if (e != last && arr[e] % v == 0)
            seq.pb(calc(res, e, cur, v));
    sort(seq.rbegin(), seq.rend());
    res = max(res, 1 + seq[0] + seq[1]);
    return seq[0] + 1;
}

int dfs(int cur, int last)
{
    int res = 0;
    while (arr[cur] > 1)
    {
        int d = lp[arr[cur]];
        calc(res, cur, last, d);
    }
    for (int e : g[cur])
        if (e != last)
            res = max(res, dfs(e, cur));
    return res;
}

int solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    return dfs(1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}