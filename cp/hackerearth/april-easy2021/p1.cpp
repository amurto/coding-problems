#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int cnt(int n, int k)
{
    int res = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        res += n & ((1ll << k) - 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c, d;
    cin >> n;
    while (n-- > 0)
    {
        int res = 0;
        cin >> a >> b >> c >> d;
        for (int k = 0; k < 31; k++)
        {
            int l1 = cnt(b+1, k) - cnt(a, k);
            int l2 = cnt(d+1, k) - cnt(c, k);
            int r1 = b - a + 1 - l1;
            int r2 = d - c + 1 - l2;
            res = add(res, mul(mul(l1, r2), 1 << k));
            res = add(res, mul(mul(l2, r1), 1 << k));
        }
        cout << res << "\n";
    }
    return 0;
}