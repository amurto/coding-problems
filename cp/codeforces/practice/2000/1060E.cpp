// https://codeforces.com/contest/1060/problem/E
// Sergey and Subway

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int dep[N], sub[N];

int precompute(int cur, int last, int d)
{
    dep[cur] = d;
    sub[cur] = 1;
    for (int e : g[cur])
        if (e != last)
            sub[cur] += precompute(e, cur, d ^ 1);
    return sub[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precompute(1, 1, 0);
    ll sum = 0;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1ll * sub[i] * (n - sub[i]);
        p += (dep[i] & 1);
    }
    sum += 1ll * p * (n - p);
    sum /= 2;
    cout << sum << "\n";
    return 0;
}