#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, k;
    cin >> n;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
            cin >> arr[i];
        deque<int> dq;
        int mx = 0, cur = 0;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] < mx)
            {
                dq.pb(cur);
                cur = 0;
            }
            cur++;
            mx = arr[i];
        }
        dq.pb(cur);
        while ((int)dq.size() > 1)
        {
            int l = dq.front(), r = dq.back();
            if (l < r)
                dq.pop_front();
            else
                dq.pop_back();
            pq.push(1ll * min(l, r));
            sum += (1ll * min(l, r));
        }
        pq.push(dq.front());
    }
    while ((int)pq.size() > 1)
    {
        ll s1 = pq.top();
        pq.pop();
        ll s2 = pq.top();
        pq.pop();
        pq.push(s1 + s2);
        sum += s1;
        sum += s2;
    }
    return sum;
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