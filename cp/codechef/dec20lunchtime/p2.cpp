#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    string s, p;
    cin >> s >> p;
    int sz = 0, pz = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            sz++;
        if (p[i] == '0')
            pz++;
        if (sz > pz)
            return false;
    }
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());
    return (s == p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}