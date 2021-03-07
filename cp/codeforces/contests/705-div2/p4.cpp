#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5, MOD = 1e9 + 7;
map<int, multiset<int>> ms;
map<int, int> st;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int n, q, idx, x;
    cin >> n >> q;
    vector<map<int, int>> mp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (x > 1)
        {
            mp[i][lp[x]]++;
            x /= lp[x];
        }
        for (auto x : mp[i])
            ms[x.first].insert(x.second);
    }
    int res = 1;
    for (auto e : ms)
    {
        if (e.second.size() < n)
            continue;
        int mn = *e.second.begin();
        st[e.first] = mn;
        res = mul(res, power(e.first, mn, MOD));
    }
    while (q-- > 0)
    {
        cin >> idx >> x;
        idx--;
        map<int, int> m;
        while (x > 1)
        {
            m[lp[x]]++;
            x /= lp[x];
        }
        for (auto e : m)
        {
            int old = mp[idx][e.first];
            if (old > 0)
                ms[e.first].erase(ms[e.first].lower_bound(old));
            old += e.second;
            mp[idx][e.first] = old;
            ms[e.first].insert(old);
            int prev = st[e.first];
            int nw = (ms[e.first].size() < n) ? 0 : *ms[e.first].begin();
            res = mul(res, power(e.first, nw - prev, MOD));
            st[e.first] = nw;
        }
        cout << res << "\n";
    }
    return 0;
}