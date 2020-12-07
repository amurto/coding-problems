// https://codeforces.com/contest/570/problem/B
// Simple Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    ll n, m, a = 0;
    cin >> n >> m;
    if (n == 1)
        a = 1;
    else if (m == n)
        a = m - 1;
    else if (m == 1)
        a = 2;
    else if (m - 1 >= n - m)
        a = m - 1;
    else
        a = m + 1;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}