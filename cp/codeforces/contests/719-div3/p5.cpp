#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll ap(ll n)
{
    return (n * (2 + n - 1)) / 2;
}

ll solve()
{
    int n;
    ll res = 1e15;
    string str;
    cin >> n >> str;
    if (count(str.begin(), str.end(), '*') == 0)
        return 0;
    vector<ll> sufd(n), sufc(n);
    if (str[n - 1] == '*')
        sufc[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        sufc[i] += (str[i] == '*') + sufc[i + 1];
        sufd[i] += sufd[i + 1] + sufc[i + 1];
    }
    ll pred = 0, prec = 0;
    for (int i = 0; i < n; i++)
    {
        pred += prec;
        prec += (str[i] == '*');
        if (str[i] == '*')
        {
            ll l = prec - 1, r = sufc[i] - 1;
            res = min(res, pred + sufd[i] - ap(l) - ap(r));
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