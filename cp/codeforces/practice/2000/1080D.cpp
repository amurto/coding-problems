// https://codeforces.com/contest/1080/problem/D
// Olya and magical square

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int mx = 31;
ll pw[mx + 1];
void init()
{
    ll pre = 0, cur = 1;
    pw[0] = 0;
    for (int i = 1; i <= mx; i++)
    {
        pre += cur;
        pw[i] = pre;
        cur <<= 2;
    }
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    if (n >= 32)
    {
        cout << "YES " << n - 1 << "\n";
        return;
    }
    ll i, p = 1, sum = 0;
    for (i = n; sum < k && p <= k && k > 0 && i > 0; i--)
    {
        ll tmp = p * 2 + 1;
        k -= p;
        sum += (tmp - 2) * pw[i - 1];
        p = tmp;
    }
    k -= sum;
    if (k <= 0)
        cout << "YES " << i << "\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}