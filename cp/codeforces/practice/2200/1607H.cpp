// https://codeforces.com/contest/1607/problem/H
// Banquet Preparations 2

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<ll> a(n), b(n), m(n), useA(n), useB(n), sum(n), lt(n), rt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> m[i];
        sum[i] = a[i] + b[i] - m[i];
        lt[i] = max(0ll, a[i] - m[i]);
        rt[i] = a[i] - (m[i] - min(b[i], m[i]));
    }
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { 
             if (sum[i1]==sum[i2]) {
                 if (lt[i1]==lt[i2])
                    return rt[i1] < rt[i2];
                return lt[i1] < lt[i2];
             }
             return sum[i1] < sum[i2]; });
    for (int i = 0; i < n;)
    {
        int r = i;
        ll cur_sum = sum[ids[i]];
        while (r < n && cur_sum == sum[ids[r]])
            r++;
        for (int j = i; j < r;)
        {
            ll v = rt[ids[j]];
            int k = j;
            while (k < r && lt[ids[k]] <= v)
            {
                v = min(v, rt[ids[k]]);
                k++;
            }
            while (j < k)
            {
                useA[ids[j]] = a[ids[j]] - v;
                useB[ids[j]] = m[ids[j]] - useA[ids[j]];
                j++;
            }
            ans++;
        }
        i = r;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << useA[i] << " " << useB[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}