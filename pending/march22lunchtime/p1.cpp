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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res;
    vector<vector<int>> st(2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st[arr[i] & 1].pb(arr[i]);
    }
    int sz0 = (int)st[0].size(), sz1 = st[1].size();
    if (sz0 == 0)
    {
        if (sz1 & 1)
        {
            cout << "-1\n";
            return;
        }
        res = arr;
    }
    else
    {
        for (int x : st[0])
            res.pb(x);
        for (int x : st[1])
            res.pb(x);
        if (sz1 & 1)
            swap(res[0], res[sz0]);
    }
    ll sum = 0;
    for (int i = 1; i < n; i++)
        sum += (res[i - 1] * 1ll * res[i]);
    if (sum % 2 == 0)
    {
        cout << "-1\n";
        return;
    }
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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