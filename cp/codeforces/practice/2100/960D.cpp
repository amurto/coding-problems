// https://codeforces.com/contest/960/problem/D
// Full Binary Tree Queries

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 61;
ll pos[LGN], l[LGN], r[LGN], len[LGN];

int find_level(ll x)
{
    for (int i = LGN - 1; i >= 0; i--)
        if (x >= l[i] && x <= r[i])
            return i;
    return 0;
}

void rotate(int level, ll k)
{
    k %= len[level];
    pos[level] += k;
    pos[level] %= len[level];
}

ll find_element(int level, ll p)
{
    p -= len[level];
    ll k = len[level] - pos[level];
    p += k;
    p %= len[level];
    return l[level] + p;
}

void solve()
{
    int q, t;
    cin >> q;
    ll x, k;
    for (int i = 0; i < LGN; i++)
    {
        l[i] = 1ll << i;
        r[i] = (1ll << (i + 1)) - 1;
        len[i] = r[i] - l[i] + 1;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t < 3)
        {
            cin >> x >> k;
            int level = find_level(x);
            if (k < 0)
            {
                k = abs(k);
                k %= len[level];
                k = len[level] - k;
            }
            k %= len[level];
            int lim = (t == 2) ? LGN : level + 1;
            for (int j = level; j < lim; j++, k *= 2)
                rotate(j, k);
        }
        else
        {
            cin >> x;
            int level = find_level(x);
            ll v = x - l[level];
            v += pos[level];
            v %= len[level];
            v += l[level];
            vector<ll> st;
            for (int j = level; j >= 0; j--, v /= 2)
                st.pb(find_element(j, v));
            for (ll s : st)
                cout << s << " ";
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}