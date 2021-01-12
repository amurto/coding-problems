// https://codeforces.com/contest/812/problem/C
// Sagheer and Nubian Market

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll possible(vector<ll> &arr, int k, int n, ll s)
{
    vector<ll> bs(n);
    for (int i = 0; i < n; i++)
        bs[i] = arr[i] + k * (i + 1);
    sort(bs.begin(), bs.end());
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += bs[i];
        if (sum > s)
            return -1;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 0, cost = 0;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        ll p = possible(arr, mid, n, s);
        if (p >= 0)
        {
            res = mid;
            cost = p;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << res << " " << cost << "\n";
    return 0;
}