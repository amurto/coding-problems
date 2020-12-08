// https://codeforces.com/contest/534/problem/C
// Polycarpus' Dice

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, sum = 0;
    cin >> n >> a;
    vector<ll> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll L = max(n - 1, a - d[i]), R = min(sum - d[i], a - 1);
        cout << d[i] - (R - L + 1) << " ";
    }
    return 0;
}