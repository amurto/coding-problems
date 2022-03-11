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
    ll res = 1e18;
    vector<int> arr(n + 1), seq;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i] / i] = max(mp[arr[i] / i], i);
        seq.pb(arr[i] / i);
    }
    sort(seq.begin(), seq.end());
    for (int i = 1; i < (int)seq.size(); i++)
        if (seq[i - 1] == seq[i])
            return 0;
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    int sz = (int)seq.size();
    vector<int> tmp(sz);
    for (int i = 0; i < sz; i++)
        tmp[i] = mp[seq[i]];
    for (int i = 1; i < sz; i++)
        for (int j = 0; j < i; j++)
            res = min(res, 1ll * (seq[i] - seq[j]) * 1ll * tmp[i] * 1ll * tmp[j]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}