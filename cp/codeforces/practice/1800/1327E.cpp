// https://codeforces.com/problemset/problem/1327/E
// Count The Blocks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, MOD = 998244353;
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
void init()
{
    ten[0] = 1;
    for (int i = 1; i < N; i++)
        ten[i] = mul(ten[i - 1], 10);
}

int f(int x)
{
    if (x < 0)
        return 0;
    return ten[x];
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        cout << add(mul(180, f(n - i - 1)), mul(n - i - 1, mul(81, f(n - i - 1)))) << " ";
    cout << "10 ";
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