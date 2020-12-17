// https://codeforces.com/contest/507/problem/C
// Guess Your Way Out!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dfs(ll h, ll n, int dir)
{
    if (h == 0)
        return 0;
    ll vis = 1;
    int req = (n > (1LL << (h - 1)));
    if (req != dir)
        vis += (1LL << h) - 1;
    if (n > (1LL << (h - 1)))
        n -= (1LL << (h - 1));
    vis += dfs(h - 1, n, req ^ 1);
    return vis;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll h, n;
    cin >> h >> n;
    cout << dfs(h, n, 0) << "\n";
    return 0;
}