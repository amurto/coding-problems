#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll N = 1e6;

// O(n)
vector<ll> lp(N + 1), pr;
void linear_sieve()
{
    for (ll i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

bool pos(ll m, vector<ll> &arr, ll k)
{
    ll sum = 0;
    for (ll a : arr)
        sum += (a % m);
    return sum <= k;
}

int solve()
{
    int n;
    ll mn = 1e6, res = 0, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        res = __gcd(res, arr[i]);
    }
    for (int i = 0; i < pr.size() && pr[i] <= mn; i++)
    {
        ll q = mn / pr[i];
        ll d = pr[i] * q;
        if (pos(d, arr, k))
            res = max(res, d);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}