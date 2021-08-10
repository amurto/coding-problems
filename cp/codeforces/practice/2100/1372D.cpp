// https://codeforces.com/contest/1372/problem/D
// Omkar and Circle

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<vector<ll>> pre(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
        return arr[0];
    pre[0][0] += arr[0];
    for (int i = 1, p = 1; i < n; i++, p ^= 1)
    {
        pre[i] = pre[i - 1];
        pre[i][p] += arr[i];
    }
    ll res = pre[n - 1][0];
    for (int i = 0, p = 0; i < n - 1; i++, p ^= 1)
        res = max(res, pre[i][p] + pre[n - 1][p ^ 1] - pre[i][p ^ 1]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}