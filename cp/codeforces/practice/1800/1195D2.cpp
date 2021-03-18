// https://codeforces.com/contest/1195/problem/D2
// Submarine in the Rybinsk Sea (hard edition)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353, N = 25;
int ten[N];

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

int len(int x)
{
    int l = 0;
    while (x > 0)
    {
        x /= 10;
        l++;
    }
    return l;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n), cnt(N), ex(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int l = len(arr[i]);
        for (int i = 0; i <= l; i++)
            cnt[i]++;
        ex[l]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        for (int j = 1; x > 0; j++, x /= 10)
        {
            int d = x % 10;
            res = add(res, mul(mul(d, ten[2 * j - 1]), cnt[j]));
            res = add(res, mul(mul(d, ten[2 * j - 2]), add(ex[j - 1], cnt[j - 1])));
            for (int k = 2 * j - 2; k >= j; k--)
                res = add(res, mul(mul(d, ten[k - 1]), 2 * ex[k - j]));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ten[0] = 1;
    for (int i = 1; i < N; i++)
        ten[i] = mul(ten[i - 1], 10);
    cout << solve() << "\n";
    return 0;
}