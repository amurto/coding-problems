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
    vector<int> arr(n);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            pq.push({arr[i], i});
    }
    vector<pii> talks;
    while ((int)pq.size() >= 2)
    {
        pii p1 = pq.top();
        pq.pop();
        pii p2 = pq.top();
        pq.pop();
        talks.pb({p1.second, p2.second});
        arr[p1.second]--;
        arr[p2.second]--;
        if (arr[p1.second] > 0)
            pq.push({arr[p1.second], p1.second});
        if (arr[p2.second] > 0)
            pq.push({arr[p2.second], p2.second});
    }
    cout << talks.size() << "\n";
    if (!talks.empty())
        for (pii p : talks)
            cout << p.first + 1 << " " << p.second + 1 << "\n";
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