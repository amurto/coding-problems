#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mul(int x, int y, int MOD)
{
    return (x * 1ll * y) % MOD;
}

void solve()
{
    int n, rem = 0;
    cin >> n;
    vector<int> seq;
    int p = 1;
    for (int i = 1; i < n; i++)
    {
        if (__gcd(i, n) == 1)
        {
            seq.pb(i);
            p = mul(p, i, n);
        }
    }
    if (p > 1)
        rem = p;
    cout << seq.size() - (rem > 0) << "\n";
    for (int e : seq)
        if (e != rem)
            cout << e << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}