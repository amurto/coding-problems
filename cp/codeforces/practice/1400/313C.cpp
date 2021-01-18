// https://codeforces.com/contest/313/problem/C
// Ilya and Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n), f(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    for (int c = 0, t = 1; t <= n; c++, t <<= 2)
    {
        f[0]++;
        f[t]--;
    }
    for (int i = 1; i < n; i++)
        f[i] += f[i - 1];
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += arr[i] * f[i];
    cout << res << "\n";
    return 0;
}