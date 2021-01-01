#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;
vector<ll> two(61);
void init()
{
    two[0] = 1;
    for (int i = 1; i <= 60; i++)
        two[i] = (two[i - 1] * 2) % MOD;
}

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<ll> arr(n);
    vector<int> cnt(60);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (ll j = 1, k = 0; j <= arr[i]; j <<= 1, k++)
            if (arr[i] & j)
                cnt[k]++;
    }
    for (int i = 0; i < n; i++)
    {
        ll AND = 0, OR = 0;
        for (ll j = 1, k = 0; j <= arr[i]; j <<= 1, k++)
            if (arr[i] & j)
                AND = add(AND, mul(cnt[k], two[k]));
        for (ll j = 1, k = 0; k < 60; j <<= 1, k++)
            if (arr[i] & j)
                OR = add(OR, mul(n, two[k]));
            else
                OR = add(OR, mul(cnt[k], two[k]));
        res = add(res, mul(AND, OR));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}