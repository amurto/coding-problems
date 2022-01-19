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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> seq = arr;
    sort(arr.begin(), arr.end());
    map<int, int> pos;
    for (int i = n - 1; i >= 0; i--)
        pos[seq[i]] = i;
    vector<pii> pts;
    for (int i = 0; i < n; i++)
    {
        if (pos[arr[i]] < i)
            pts.pb({pos[arr[i]], i});
        else
            pts.pb({i, pos[arr[i]]});
        pos[arr[i]]++;
    }
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n;)
    {
        int itr = i, l = pts[i].first, r = pts[i].second;
        while (itr < n && pts[itr].first <= r)
        {
            r = max(r, pts[itr].second);
            itr++;
        }
        int mn = 1e9 + 7, mx = 0;
        for (int j = l; j <= r; j++)
        {
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
        }
        res += abs(mx - mn);
        i = itr;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}