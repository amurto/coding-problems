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
    int n;
    cin >> n;
    vector<int> pts, res(n + 1);
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        arr[i].second += arr[i].first;
        pts.pb(arr[i].first);
        pts.pb(arr[i].second);
    }
    sort(arr.begin(), arr.end());
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0, sz = (int)pts.size();
    for (int i = 0; i < sz; i++)
    {
        while (!pq.empty() && pq.top() == pts[i])
            pq.pop();
        int nxt = pts[i] + 1;
        if (i < sz - 1)
            nxt = pts[i + 1];
        while (cur < n && arr[cur].first == pts[i])
        {
            pq.push(arr[cur].second);
            cur++;
        }
        int sz = (int)pq.size();
        if (sz > 0)
            res[sz] += nxt - pts[i];
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}