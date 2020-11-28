#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve(ll num)
{
    vector<vector<ll>> F(40);
    for (ll i = 2; i * i <= num; i++)
    {
        int idx = 0;
        while (num % i == 0)
        {
            num /= i;
            F[idx].pb(i);
            idx++;
        }
    }
    if (num > 1)
        F[0].pb(num);
    vector<ll> res;
    for (int i = 0; i < 40; i++)
    {
        ll cur = 1;
        for (int j = 0; j < F[i].size(); j++)
            cur *= F[i][j];
        if (cur > 1)
            res.pb(cur);
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (ll r : res)
        cout << r << " ";
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
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}