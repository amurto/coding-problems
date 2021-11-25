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
    int n;
    cin >> n;
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
    int pins = (int)ids.size();
    ll best_p = 0, best_q = 1;
    for (int t = 1; t <= min(pins, 20); t++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
            cnt[M[i]] += min(t, K[i]);
        sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
             { return cnt[i1] > cnt[i2]; });
        ll p = 0, q = t;
        for (int i = 0; i < t; i++)
            p += cnt[ids[i]];
        if (is_greater(best_p, best_q, p, q))
        {
            res.clear();
            for (int i = 0; i < t; i++)
                res.pb(ids[i]);
            best_p = p, best_q = q;
        }
    }
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