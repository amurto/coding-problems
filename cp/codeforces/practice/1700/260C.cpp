// https://codeforces.com/contest/260/problem/C
// Balls and Boxes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, x;
    cin >> n >> x;
    x--;
    ll mn = INT_MAX;
    vector<ll> arr(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    vector<ll> mns;
    for (int i = 0; i < n; i++)
        if (arr[i] == mn)
            mns.pb(i);
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(mns.begin(), mns.end(), i) - mns.begin() - 1;
        if (idx < 0)
            p[i] = mns.back();
        else
            p[i] = mns[idx];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != mn || (arr[i] == mn && p[x] != i))
            continue;
        ll d = 0;
        if (x >= i)
            d = x - i;
        else
            d = n - (i - x);
        for (int j = 0; j < n; j++)
            arr[j] -= mn;
        for (int j = i + 1; j <= i + d; j++)
            arr[j % n]--;
        arr[i] = mn * 1ll * n + d;
        break;
    }
    for (ll e : arr)
        cout << e << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}