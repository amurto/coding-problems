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
    ll res = 0, sum = 0, mn_sum = 0;
    priority_queue<ll> pq;
    cin >> n >> k;
    vector<int> T(n + 1), Y(n + 1);
    T[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> Y[i];
        if (T[i] == 1)
            res = Y[i];
        else
            res += Y[i];
    }
    for (int i = n; k >= 0 && i >= 0; i--)
    {
        int sz = (int)pq.size();
        while (sz > k && !pq.empty())
        {
            mn_sum -= pq.top();
            pq.pop();
            sz--;
        }
        if (T[i] == 1)
        {
            res = max(res, Y[i] + sum - mn_sum);
            k--;
        }
        else
        {
            sum += Y[i];
            if (Y[i] < 0)
            {
                pq.push(Y[i]);
                mn_sum += Y[i];
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}