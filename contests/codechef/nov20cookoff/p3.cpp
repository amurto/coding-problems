#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll res = 100000000000;

void hw(ll merge, vector<ll> arr)
{
    if (merge == 0)
    {
        ll sum = 0;
        for (ll val : arr)
            sum += val;
        res = min(res, sum);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            vector<ll> farr;
            farr.pb(arr[i] * arr[j]);
            for (int k = 0; k < arr.size(); k++)
                if (k != i && k != j)
                    farr.pb(arr[k]);
            hw(merge - 1, farr);
        }
    }
}

ll solve()
{
    ll k, x;
    cin >> k >> x;

    // get factors
    vector<ll> fact;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            fact.pb(i);
        }
    }
    if (x > 1)
        fact.pb(x);

    if (fact.size() <= k)
    {
        ll sum = 0;
        for (ll val : fact)
            sum += val;
        sum += k - fact.size();
        return sum;
    }
    hw(fact.size() - k, fact);
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
    {
        res = 100000000000;
        cout << solve() << "\n";
    }
    return 0;
}
