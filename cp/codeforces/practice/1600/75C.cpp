// https://codeforces.com/contest/75/problem/C
// Modified GCD

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(vector<int> &d)
{
    int low, high;
    cin >> low >> high;
    int idx = upper_bound(d.begin(), d.end(), high) - d.begin() - 1;
    if (idx < 0 || d[idx] < low)
        return -1;
    return d[idx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, q;
    cin >> a >> b >> q;
    int g = __gcd(a, b);
    vector<int> d;
    for (int i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            d.pb(i);
            d.pb(g / i);
        }
    }
    sort(d.begin(), d.end());
    while (q-- > 0)
        cout << query(d) << "\n";
    return 0;
}