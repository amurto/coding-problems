#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dfs(ll cur, ll a, ll b, ll c)
{
    if ((1ll << cur) > c)
        return a * b;
    if ((c >> cur) & 1)
        return max(dfs(cur + 1, a | (1ll << cur), b, c), dfs(cur + 1, a, b | (1ll << cur), c));
    return dfs(cur + 1, a | (1ll << cur), b | (1ll << cur), c);
}

ll solve()
{
    ll c, a = 0, b = 0;
    cin >> c;
    if (c == 0)
        return 1ll;
    return dfs(0, 0, 0, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}