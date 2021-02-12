// https://www.hackerrank.com/challenges/lazy-sorting/problem
// Lazy Sorting

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll fac(ll x)
{
    if (x == 0)
        return 1;
    return x * 1ll * fac(x - 1);
}

double solve()
{
    int n, v;
    cin >> n;
    vector<int> arr(n), f(101);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    ll num = 1;
    for (int i = 1; i <= 100; i++)
        num *= fac(f[i]);
    return fac(n) * 1.0 / num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12) << solve() << "\n";
    return 0;
}