// https://codeforces.com/contest/462/problem/C
// Appleman and Toastman

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
    ll res = 0;
    vector<ll> arr(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    f[n - 1] = n;
    for (int i = n - 2, j = n; i >= 0; i--, j--)
        f[i] = j;
    for (int i = 0; i < n; i++)
        res += arr[i] * f[i];
    cout << res << "\n";
    return 0;
}