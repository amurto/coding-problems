#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll N = 1e6 + 5;
vector<ll> seq, ten(18);

int len(ll x)
{
    int cnt = 0;
    while (x > 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void gen(ll cur, ll x)
{
    int l = len(cur), r = len(x + 1);
    if (l + r >= 19)
        return;
    x += 1;
    cur = cur * ten[r] + x;
    seq.pb(cur);
    gen(cur, x);
}

void init()
{
    ten[0] = 1;
    for (int i = 1; i < 18; i++)
        ten[i] = ten[i - 1] * 10;
    for (ll i = 1; i < N; i++)
        gen(i, i);
    seq.pb(1234567891011121314);
    sort(seq.begin(), seq.end());
}

ll solve(ll n)
{
    int ub = upper_bound(seq.begin(), seq.end(), n) - seq.begin();
    ll low = 1, high = 999999998, res = seq[ub];
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        int s = len(mid + 1);
        ll num = mid * ten[s] + mid + 1;
        if (num > n)
        {
            res = min(res, num);
            high = mid - 1;
        }
        else
            low = mid + 1;
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
    for (int tc = 1; tc <= t; tc++)
    {
        ll n;
        cin >> n;
        cout << "Case #" << tc << ": " << solve(n) << "\n";
    }
    return 0;
}