// https://codeforces.com/contest/631/problem/D
// Messenger

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, char> ch;
#define pb push_back

int eq(vector<int> &z, ch c1, ch c2, int v)
{
    if (v == 0)
        return c1.second == c2.second && c1.first <= c2.first;
    return c1.first == c2.first && c1.second == c2.second;
}

vector<int> z_function(vector<ch> s, int k)
{
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && eq(z, s[z[i]], s[i + z[i]], z[i]))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<ch> compress(vector<ch> arr, int n)
{
    vector<ch> tmp;
    for (int i = 0; i < n;)
    {
        char cur = arr[i].second;
        ll sum = 0;
        while (i < n && cur == arr[i].second)
        {
            sum += arr[i].first;
            i++;
        }
        tmp.pb({sum, cur});
    }
    return tmp;
}

ll solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<ch> t(n), s(m);
    for (int i = 0; i < n; i++)
        cin >> t[i].first >> t[i].second >> t[i].second;
    for (int i = 0; i < m; i++)
        cin >> s[i].first >> s[i].second >> s[i].second;
    t = compress(t, n);
    s = compress(s, m);
    n = t.size();
    m = s.size();
    if (m == 1)
    {
        for (ch c : t)
            if (c.second == s[0].second && c.first >= s[0].first)
                res += c.first - s[0].first + 1;
        return res;
    }
    vector<ch> tmp;
    for (int i = 0; i < m - 1; i++)
        tmp.pb(s[i]);
    tmp.pb({char('z' + 1), 1});
    for (ch c : t)
        tmp.pb(c);
    vector<int> z = z_function(tmp, m);
    int sz = z.size();
    for (int i = m, j = 0; i < sz; i++, j++)
        res += (z[i] == m - 1 && j + z[i] < n && t[j + z[i]].second == s[m - 1].second && t[j + z[i]].first >= s[m - 1].first);
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