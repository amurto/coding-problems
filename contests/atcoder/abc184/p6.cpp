// Meet in the middle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void pc(vector<ll> &arr, vector<ll> &store, ll sum, ll t, int cur, int limit)
{
    if (sum > t)
        return;
    if (cur == limit)
    {
        store.pb(sum);
        return;
    }
    pc(arr, store, sum, t, cur + 1, limit);
    pc(arr, store, sum + arr[cur], t, cur + 1, limit);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> L, R;
    pc(arr, L, 0, t, 0, n / 2);
    pc(arr, R, 0, t, n / 2, n);
    ll res = 0;
    sort(R.begin(), R.end());
    for (int i = 0; i < L.size(); i++)
    {
        int beg = 0, end = R.size() - 1;
        while (beg < end)
        {
            int mid = beg + (end - beg) / 2;
            if (L[i] + R[mid] > t)
                end = mid - 1;
            else
            {
                res = max(res, L[i] + R[mid]);
                beg = mid + 1;
            }
        }
        if (L[i] + R[beg] <= t)
            res = max(res, L[i] + R[beg]);
    }
    cout << res << "\n";
    return 0;
}