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
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<ll> arr(n), neg, pos;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            neg.pb(abs(arr[i]));
        else if (arr[i] > 0)
            pos.pb(arr[i]);
    }
    sort(neg.rbegin(), neg.rend());
    sort(pos.rbegin(), pos.rend());
    int sz1 = (int)neg.size(), sz2 = (int)pos.size();
    for (int i = 0; i < sz1; i += k)
        res += neg[i] * 2;
    for (int i = 0; i < sz2; i += k)
        res += pos[i] * 2;
    ll mx_neg = 0, mx_pos = 0;
    if (!neg.empty())
        mx_neg = neg[0];
    if (!pos.empty())
        mx_pos = pos[0];
    res -= max(mx_neg, mx_pos);
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