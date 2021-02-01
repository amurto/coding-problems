// https://codeforces.com/contest/231/problem/C
// To Add or Not to Add

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bs(vector<ll> &pre, ll k, ll e, int idx)
{
    int l = 0, r = idx;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        ll s = pre[idx] - ((mid > 0) ? pre[mid - 1] : 0);
        int c = idx - mid + 1;
        if (s + k < e * c)
            l = mid + 1;
        else
            r = mid;
    }
    return idx - l + 1;
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n), pre(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1] + arr[i];
    int mx = 1, mn = arr[0];
    for (int i = 1; i < n; i++)
    {
        int c = bs(pre, k, arr[i], i);
        if (c > mx)
        {
            mx = c;
            mn = arr[i];
        }
    }
    cout << mx << " " << mn << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}