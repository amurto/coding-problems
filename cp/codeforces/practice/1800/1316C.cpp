// https://codeforces.com/contest/1316/problem/C
// Primitive Primes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> f(n), g(m);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    for (int i = 0; i < m; i++)
        cin >> g[i];
    int i = 0;
    while (i < n && f[i] % p == 0)
        i++;
    int j = 0;
    while (j < m && g[j] % p == 0)
        j++;
    return i + j;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}