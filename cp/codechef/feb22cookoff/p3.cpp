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

ll nc2(ll x)
{
    return (x * (x - 1)) / 2;
}

void solve()
{
    int n, m, q;
    cin >> n >> m;
    ll sum = 0;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int u, v;
            cin >> u >> v;
            m++;
        }
        else if (ch == '-')
        {
            int u, v;
            cin >> u >> v;
            m--;
        }
        else
        {
            ll res = sum;
            res -= nc2(n);
            res += (m * 2);
            cout << res << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}