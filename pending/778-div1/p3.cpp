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

bool solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (n == 1)
        return true;
    multiset<ll> ms;
    for (ll v : arr)
        ms.insert(v);
    // Lambda recursive function
    auto dfs = [&](const auto &self, ll val) -> bool
    {
        if (ms.find(val) != ms.end())
        {
            ms.erase(ms.lower_bound(val));
            return true;
        }
        else if (val == 1)
            return false;
        return self(self, val / 2) && self(self, (val + 1) / 2);
    };
    return dfs(dfs, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}