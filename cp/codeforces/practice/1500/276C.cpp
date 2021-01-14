// https://codeforces.com/contest/276/problem/C
// Little Girl and Maximum Sum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    ll res = 0;
    vector<ll> arr(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    while (q-- > 0)
    {
        cin >> l >> r;
        l--;
        r--;
        f[l]++;
        if (r + 1 < n)
            f[r + 1]--;
    }
    for (int i = 1; i < n; i++)
        f[i] += f[i - 1];
    sort(f.rbegin(), f.rend());
    for (int i = 0; i < n; i++)
        res += arr[i] * f[i];
    cout << res << "\n";
    return 0;
}