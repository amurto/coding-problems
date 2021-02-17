// https://codeforces.com/contest/450/problem/C
// Jzzhu and Chocolate

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > n + m - 2)
        return -1;
    if (n > m)
        swap(n, m);
    if (k < n)
        return max((n / (k + 1)) * m, n * (m / (k + 1)));
    if (k < m)
        return n * (m / (k + 1));
    return n / (k + 2 - m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}