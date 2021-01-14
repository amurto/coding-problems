#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool isdiv(string &q, string &d)
{
    int n = q.length(), m = d.length();
    if (n % m > 0)
        return false;
    for (int i = 0; i < n; i += m)
        for (int j = 0; j < m; j++)
            if (q[i + j] != d[j])
                return false;
    return true;
}
void solve()
{
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    string g = "", temp = "";
    for (int i = 0; i < min(n, m); i++)
    {
        temp.pb(s[i]);
        if (isdiv(s, temp) && isdiv(p, temp))
            g = temp;
    }
    int len = g.length();
    if (len == 0)
    {
        cout << "-1\n";
        return;
    }

    int lcm = ((n * m) / (len * len));
    while (lcm-- > 0)
        cout << g;
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