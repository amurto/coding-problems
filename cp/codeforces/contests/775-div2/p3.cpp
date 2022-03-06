#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    map<ll, vector<ll>> mp_r, mp_c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            mp_r[grid[i][j]].pb(i + 1);
            mp_c[grid[i][j]].pb(j + 1);
        }
    }
    for (auto v : mp_r)
    {
        sort(v.second.begin(), v.second.end());
        int sz = (int)v.second.size();
        ll cur = 0, suf = 0;
        for (int i = sz - 1; i >= 0; i--)
        {
            cur += (suf - (v.second[i] * (sz - 1 - i)));
            suf += v.second[i];
        }
        res += cur;
    }
    for (auto v : mp_c)
    {
        sort(v.second.begin(), v.second.end());
        int sz = (int)v.second.size();
        ll cur = 0, suf = 0;
        for (int i = sz - 1; i >= 0; i--)
        {
            cur += (suf - (v.second[i] * (sz - 1 - i)));
            suf += v.second[i];
        }
        res += cur;
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