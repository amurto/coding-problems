// https://codeforces.com/contest/822/problem/C
// Hacker, pack your bags!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
const ll inf = 3e9;
vector<vector<pair<int, ll>>> pre(N);
vector<vector<ll>> MIN(N);

ll bs(int req, int start)
{
    if (pre[req].empty())
        return inf;
    int l = 0, r = pre[req].size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (start <= pre[req][mid].first)
            r = mid;
        else
            l = mid + 1;
    }
    if (pre[req][l].first >= start)
        l--;
    if (l < 0)
        return inf;
    return MIN[req][l];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    ll res = inf;
    cin >> n >> x;
    vector<int> L(n), R(n);
    vector<ll> C(n);
    for (int i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i] >> C[i];
        pre[R[i] - L[i] + 1].pb({R[i], C[i]});
    }
    for (int i = 1; i < N; i++)
    {
        if (pre[i].empty())
            continue;
        sort(pre[i].begin(), pre[i].end());
        int mn = INT_MAX;
        for (pair<int, int> p : pre[i])
        {
            mn = min(mn, p.second);
            MIN[i].pb(mn);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int req = x - (R[i] - L[i] + 1);
        if (req <= 0)
            continue;
        res = min(res, C[i] + bs(req, L[i]));
    }
    res >= inf ? cout << "-1\n" : cout << res << "\n";
    return 0;
}