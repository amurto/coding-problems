// https://codeforces.com/contest/1416/problem/C
// XOR Inverse

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> l, r;
    for (int i = low; i <= mid; i++)
        l.pb(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        r.pb(arr[i]);
    ll inv = 0;
    for (int e : l)
    {
        int lb = lower_bound(r.begin(), r.end(), e) - r.begin();
        inv += 1ll * lb;
    }
    vector<int> tmp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= high)
        tmp[k++] = arr[j++];
    for (int idx = 0; idx < tmp.size(); idx++)
        arr[low + idx] = tmp[idx];
    return inv;
}

ll count_inversions(vector<int> &arr, int low, int high)
{
    ll inv = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        inv += count_inversions(arr, low, mid);
        inv += count_inversions(arr, mid + 1, high);
        inv += merge(arr, low, mid, high);
    }
    return inv;
}

void solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> tmp = arr;
    ll inv = count_inversions(tmp, 0, n - 1);
    for (int b = 0; b <= 30; b++)
    {
        vector<int> seq = arr;
        for (int i = 0; i < n; i++)
            seq[i] ^= (1 << b);
        ll x_inv = count_inversions(seq, 0, n - 1);
        if (x_inv < inv)
        {
            for (int i = 0; i < n; i++)
                arr[i] ^= (1 << b);
            res |= (1 << b);
            inv = x_inv;
        }
    }
    cout << inv << " " << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}