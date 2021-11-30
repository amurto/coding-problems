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
    int n, w;
    ll res = 0;
    cin >> n >> w;
    vector<int> a(n), b(n), ids(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return a[i1] > a[i2]; });
    for (int i = 0; w > 0 && i < n; i++)
    {
        int id = ids[i];
        int mn = min(w, b[id]);
        w -= mn;
        res += 1ll * mn * a[id];
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