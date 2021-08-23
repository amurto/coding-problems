// https://codeforces.com/contest/863/problem/E
// Turn Off The TV

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
    int n;
    cin >> n;
    vector<pii> arr(n);
    vector<int> pts, ids(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        pts.pb(arr[i].first);
        pts.pb(arr[i].second + 1);
    }
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    int sz = pts.size();
    vector<int> diff(sz), last(sz);
    for (pii p : arr)
    {
        int l = lower_bound(pts.begin(), pts.end(), p.first) - pts.begin();
        int r = lower_bound(pts.begin(), pts.end(), p.second + 1) - pts.begin();
        diff[l]++;
        diff[r]--;
    }

    for (int i = 1; i < sz; i++)
        diff[i] += diff[i - 1];
    int one = -1;
    for (int i = 0; i < sz; i++)
    {
        last[i] = one;
        if (diff[i] == 1)
            one = i;
    }
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(pts.begin(), pts.end(), arr[i].first) - pts.begin();
        int r = lower_bound(pts.begin(), pts.end(), arr[i].second + 1) - pts.begin();
        if (last[r] < l)
            return i + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}