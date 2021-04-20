#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int high_pow(ll v)
{
    int cnt = 0;
    ll x = v;
    while (x > 0)
    {
        cnt++;
        x >>= 1;
    }
    if (1ll << (cnt - 1) == v)
        return cnt;
    return cnt + 1;
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    int h = high_pow(k);
    if (h > n)
    {
        cout << "-1\n";
        return;
    }
    vector<int> seq;
    int cur = 1, rem = n;
    while (rem > h)
    {
        seq.pb(cur++);
        rem--;
    }
    while (rem > 0)
    {
        int low = 1, high = rem - 1, lim = rem;
        ll mx = 1ll << (rem - 1);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            ll p = 0;
            for (int j = 1; j <= mid; j++)
                p += 1ll << (rem - j - 1);
            if (p >= k)
            {
                lim = min(lim, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        int b = cur + lim - 1;
        for (int j = 1; j < lim; j++)
            k -= 1ll << (rem - j - 1);
        while (b >= cur)
        {
            seq.pb(b--);
            rem--;
        }
        cur += lim;
    }
    for (int e : seq)
        cout << e << " ";
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
        solve();
    return 0;
}