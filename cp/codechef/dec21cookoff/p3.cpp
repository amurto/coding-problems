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

ll ap(ll a, ll n)
{
    return (n * (a * 2 + n - 1)) / 2;
}

ll solve()
{
    string str;
    cin >> str;
    int n = (int)str.length(), val = 0, cl = 0;
    ll res = 1e18;
    vector<int> arr(n);
    vector<ll> suf;
    suf.pb(0ll);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            val++;
        else
            val--;
        arr[i] = val;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ')')
        {
            suf.pb(1ll * i + suf.back());
            cl++;
        }
        int op = 0;
        if (i - 1 >= 0)
            op = arr[i - 1];
        int req = op + 1;
        if (req <= cl)
        {
            ll sum = suf[cl] - suf[cl - req];
            sum -= ap(i, req);
            res = min(res, sum);
        }
    }
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