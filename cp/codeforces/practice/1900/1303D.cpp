// https://codeforces.com/contest/1303/problem/D
// Fill The Bag

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int m;
    ll n, res = 0;
    cin >> n >> m;
    vector<ll> arr(m), cnt(61);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        ll x = arr[i], c = 0;
        while (x > 0)
        {
            x >>= 1;
            c++;
        }
        cnt[c - 1]++;
    }
    for (int cur = 0; n > 0; cur++, n >>= 1)
    {
        if ((n & 1) == 0)
            continue;
        ll req = 1ll << cur;
        for (int i = cur; i >= 0; i--)
        {
            ll v = 1ll << i;
            ll u = min(req / v, cnt[i]);
            req -= u * v;
        }
        if (req == 0)
        {
            req = 1ll << cur;
            for (int i = cur; i >= 0; i--)
            {
                ll v = 1ll << i;
                ll u = min(req / v, cnt[i]);
                cnt[i] -= u;
                req -= u * v;
            }
        }
        else
        {
            int i = cur + 1;
            while (i < 61 && cnt[i] == 0)
                i++;
            if (i == 61)
                return -1;
            else
            {
                res += i - cur;
                cnt[i]--;
                for (int j = i - 1; j >= cur; j--)
                    cnt[j]++;
            }
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