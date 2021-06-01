#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

string solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    string tmp;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int b = 0; b < m; b++)
            if (tmp[b] == '1')
                arr[i] |= (1ll << b);
    }
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    shuffle(ids.begin(), ids.end(), rng);
    string res(m, '0');
    int mx = 0;
    for (int i = 0; i < min(n, 50); i++)
    {
        int id = ids[i];
        vector<int> bits;
        for (int b = 0; b < m; b++)
            if ((arr[id] >> b) & 1ll)
                bits.pb(b);
        int sz = bits.size();
        vector<int> f(1 << sz);
        for (int i = 0; i < n; i++)
        {
            int v = 0;
            for (int b = 0; b < sz; b++)
                if ((arr[i] >> bits[b]) & 1ll)
                    v |= (1 << b);
            f[v]++;
        }
        for (int b = 0; b < sz; b++)
            for (int mask = (1 << sz) - 1; mask >= 0; mask--)
                if (!((mask >> b) & 1))
                    f[mask] += f[mask ^ (1 << b)];
        for (int mask = 0; mask < (1 << sz); mask++)
        {
            if (2 * f[mask] >= n && __builtin_popcount(mask) > mx)
            {
                mx = __builtin_popcount(mask);
                res = string(m, '0');
                for (int b = 0; b < sz; b++)
                    if ((mask >> b) & 1)
                        res[bits[b]] = '1';
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
    cout << solve() << "\n";
    return 0;
}