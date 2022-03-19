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

const int B = 32;
ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> arr(n), cnt(B);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (ll j = 0; j < B; j++)
            if ((arr[i] >> j) & 1)
                cnt[j]++;
        res += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        vector<ll> tmp = cnt;
        for (ll j = 0; j < B; j++)
            if ((arr[i] >> j) & 1)
                tmp[j] = n - tmp[j];
        ll cur = 0;
        for (ll j = 0; j < B; j++)
            cur += ((1ll << j) * tmp[j]);
        res = max(res, cur);
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