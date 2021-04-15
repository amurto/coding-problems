// https://codeforces.com/contest/1354/problem/D
// Multiset

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bs(vector<int> &arr, vector<int> &upd, int x)
{
    int cnt = 0;
    for (int a : arr)
        cnt += (a <= x);
    for (int u : upd)
    {
        if (u > 0)
            cnt += (u <= x);
        else
            cnt -= (abs(u) <= cnt);
    }
    return cnt;
}

int solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), upd(q);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < q; i++)
        cin >> upd[i];
    int l = 1, r = n, mn = 1e9;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (bs(arr, upd, mid) > 0)
        {
            mn = min(mn, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return (mn < 1e9) ? mn : 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}