#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<ll> fib;
void init()
{
    fib.pb(1);
    fib.pb(2);
    for (int i = 0; fib.back() <= 1e18; i++)
        fib.pb(fib[fib.size() - 2] + fib[fib.size() - 1]);
}

void solve()
{
    ll n;
    cin >> n;
    int id = upper_bound(fib.begin(), fib.end(), n) - fib.begin();
    id--;
    vector<vector<int>> seq(id + 5);
    n -= fib[id];
    int m = id + 1;
    seq[0].pb(!(id & 1));
    if (id % 2 == 0)
        m++;
    while (n > 0)
    {
        int i = upper_bound(fib.begin(), fib.end(), n) - fib.begin();
        i--;
        n -= fib[i];
        seq[m - 1 - i - 1].pb(!(i & 1));
    }
    vector<int> ops;
    for (int e : seq[0])
        ops.pb(e + 1);
    for (int i = 1, p = 1; i <= m; i++, p ^= 1)
    {
        ops.pb(p + 3);
        for (int e : seq[i])
            ops.pb(e + 1);
    }
    cout << ops.size() << "\n";
    for (int op : ops)
        cout << op << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}