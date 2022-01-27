#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    int req = (n - k + 1) / 2 + k;
    vector<int> arr(n), freq(n + 1), pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + freq[i];
    for (int i = 1; i <= n; i++)
    {
        int low = i, high = n, res = n + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pre[mid] - pre[i - 1] >= req)
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (res <= n && res - i + 1 < r - l + 1)
        {
            l = i;
            r = res;
        }
    }
    vector<pii> pts;
    int cnt = 0;
    for (int i = 0; k > 1 && i < n; i++)
    {
        if (arr[i] < l || arr[i] > r)
            arr[i] = -1;
        else
            arr[i] = 1;
        cnt += arr[i];
        if (cnt > 0)
        {
            cnt = 0;
            if (pts.empty())
                pts.pb({0, i});
            else
                pts.pb({pts.back().second + 1, i});
            k--;
        }
    }
    if (pts.empty())
        pts.pb({0, n - 1});
    else
        pts.pb({pts.back().second + 1, n - 1});
    cout << l << " " << r << "\n";
    for (pii pt : pts)
        cout << pt.first + 1 << " " << pt.second + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}