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

const int N = 2e5 + 5;

int cnt[N];
vector<int> g[N];

bool is_greater(ll p1, ll q1, ll p2, ll q2)
{
    return (p1 * q2) <= (p2 * q1);
}
void solve()
{
    int n, mx = 0;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    vector<int> M(n), K(n), ids, res;
    for (int i = 0; i < n; i++)
    {
        cin >> M[i] >> K[i];
        cnt[M[i]] += K[i];
        ids.pb(M[i]);
        g[M[i]].pb(i);
    }
    sort(ids.begin(), ids.end());
    ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return cnt[i1] > cnt[i2]; });
    ll p = 0, q = 1;
    vector<int> st(21);
    for (int i = 0; i < (int)ids.size(); i++)
    {
        int id = ids[i];
        for (int j : g[id])
            st[K[j]]++;
        ll tp = 0, tq = i + 1;
        for (int j = 1; j <= 20; j++)
            tp += (min(j, i + 1) * st[j]);
        if (is_greater(p, q, tp, tq))
        {
            mx = max(mx, i + 1);
            p = tp, q = tq;
        }
    }
    for (int i = 0; i < mx; i++)
        res.pb(ids[i]);
    cout << (int)res.size() << "\n";
    for (int x : res)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}