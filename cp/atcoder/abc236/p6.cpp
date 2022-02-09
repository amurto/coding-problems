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
    int n;
    cin >> n;
    ll res = 0;
    int sz = 1 << n, cnt = 1;
    vector<int> ids(sz - 1);
    vector<ll> c(sz);
    for (int i = 1; i < sz; i++)
        cin >> c[i];
    iota(ids.begin(), ids.end(), 1);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return c[i1] < c[i2]; });
    vector<bool> vis(sz);
    vis[0] = true;

    for (int i = 0; cnt < sz && i < (int)ids.size(); i++)
    {
        if (!vis[ids[i]])
        {
            vector<bool> tmp = vis;
            tmp[ids[i]] = true;
            for (int j = 0; j < sz; j++)
                if (vis[j])
                    tmp[j ^ ids[i]] = true;
            swap(vis, tmp);
            int t = 0;
            for (bool v : vis)
                t += v;
            cnt = t;
            res += c[ids[i]];
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