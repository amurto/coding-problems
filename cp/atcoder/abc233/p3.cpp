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

// check if x*y > n
bool is_overflow(ll x, ll y, ll n)
{
    if (x == 0 || y == 0)
        return false;
    return x > (n / y);
}

ll solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<vector<ll>> arr(n);
    map<ll, ll> dp;
    dp[1] = 1;
    for (int i = 0; i < n; i++)
    {
        map<ll, ll> tdp;
        int l;
        cin >> l;
        arr[i].resize(l);
        for (int j = 0; j < l; j++)
            cin >> arr[i][j];
        for (auto v : dp)
            for (int j = 0; j < l; j++)
                if (!is_overflow(v.first, arr[i][j], x) && x % (v.first * arr[i][j]) == 0)
                    tdp[v.first * arr[i][j]] += v.second;
        swap(dp, tdp);
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}