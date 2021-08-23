#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int f(int k)
{
    return (1 << k) - 1;
}

int dfs(int n, int m, int cur, int bit)
{
    if (bit == -1)
        return cur;
    if (((cur ^ n) | f(bit)) >= m + 1)
        return dfs(n, m, cur, bit - 1);
    return dfs(n, m, cur | (1 << bit), bit - 1);
}

int solve()
{
    int n, m;
    cin >> n >> m;
    return dfs(n, m, 0, 30);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}