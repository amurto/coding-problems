// https://codeforces.com/contest/1006/problem/F
// Xor-Paths

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

const int N = 20;
vector<ll> g[N][N][2];
ll grid[N][N];
vector<vector<int>> di = {{0, 1}, {0, -1}}, dj = {{1, 0}, {-1, 0}};
void dfs(ll x, int i, int j, int rem, int n, int m, int p)
{
    rem--;
    if (rem == 0)
    {
        g[i][j][p].pb(x);
        return;
    }
    for (int dir = 0; dir < 2; dir++)
    {
        int ni = i + di[p][dir], nj = j + dj[p][dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
            dfs(x ^ grid[i][j], ni, nj, rem, n, m, p);
    }
}

ll solve()
{
    int n, m;
    ll k, res = 0;
    cin >> n >> m >> k;
    int moves = n + m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<int> st = {n, m};
    dfs(0, 0, 0, st[0], n, m, 0);
    dfs(0, n - 1, m - 1, st[1], n, m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map<ll, ll> mp;
            for (ll x : g[i][j][0])
                mp[x ^ grid[i][j]]++;
            for (ll x : g[i][j][1])
                res += mp[x ^ k];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}