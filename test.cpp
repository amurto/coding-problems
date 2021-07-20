#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int add(int x, int y, int MOD)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y, int MOD)
{
    return (x * 1ll * y) % MOD;
}

void solve()
{
    int a, b, p;
    ll x;
    cin >> a >> p;
    vector<int> seq;
    int e = 1;
    vector<bool> vis(p);
    vector<int> nxt(p);
    for (int i = 0; i < p; i++)
        nxt[i] = mul(i, a, p);
    // for (int i = 1; i <= p; i++)
    // {
    //     e = nxt[e];
    //     cout << e << " ";
    // }

    for (int i = 1; i < p; i++)
        cout << a << " x " << i << " -> " << mul(a, i, p) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}