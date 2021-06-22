// https://codeforces.com/contest/1151/problem/C
// Problem for Nazar

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int B = 60;
const ll MOD = 1e9 + 7;
ll two[B + 1], odd[B + 1], even[B + 1];
ll add(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}

void init()
{
    two[0] = 1;
    for (int i = 1; i <= B; i++)
        two[i] = (1ll << i) + two[i - 1];
    odd[0] = 1;
    for (int i = 1; i <= B; i++)
    {
        if (i & 1)
            odd[i] = odd[i - 1];
        else
            odd[i] = odd[i - 1] + (1ll << i);
    }
    even[0] = 0;
    for (int i = 1; i < +B; i++)
    {
        even[i] = even[i - 1];
        if (i & 1)
            even[i] = even[i - 1] + (1ll << i);
    }
}

ll ap(ll a, ll n)
{
    return mul(n, a + n - 1);
}

ll compute_sum(ll v)
{
    ll sum = 0;
    int id = 0;
    for (int i = 0; two[i] <= v && i <= B; i++)
        if (two[i] <= v)
            id = i;
    ll o = odd[id];
    ll e = even[id];
    if (two[id] < v)
    {
        if (id & 1)
            o += v - two[id];
        else
            e += v - two[id];
    }
    return add(ap(1, o), ap(2, e));
}

int solve()
{
    ll l, r;
    cin >> l >> r;
    ll sum = compute_sum(r);
    if (l > 1)
        sum = add(sum, -compute_sum(l - 1));
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}