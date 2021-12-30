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

int solve()
{
    int n;
    cin >> n;
    ll x;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> x;
    for (int i = 1; i <= n; i++)
        arr[i] -= x;
    vector<int> left(n + 1), dp0(n + 1), dp1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        left[i] = i;
        if (arr[i - 1] + arr[i] >= 0)
        {
            left[i] = i - 1;
            if (i - 2 >= 0 && arr[i - 2] + arr[i - 1] >= 0 && arr[i - 2] + arr[i - 1] + arr[i] >= 0)
                left[i] = max(left[i - 1], left[i - 2]);
        }
    }
    auto cmp = [&](int i1, int i2)
    {
        if (i1 < i2)
            return dp0[i1] + i2 - i1 < dp0[i2];
        return dp0[i1] < dp0[i2] + i1 - i2;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(0);
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = dp1[i - 1];
        while (!pq.empty() && pq.top() < left[i] - 1)
            pq.pop();
        dp1[i] = max(dp1[i], dp0[i - 1] + 1);
        if (!pq.empty())
            dp1[i] = max(dp1[i], dp0[pq.top()] + i - pq.top());
        dp0[i] = dp1[i - 1];
        pq.push(i);
    }
    return dp1[n];
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