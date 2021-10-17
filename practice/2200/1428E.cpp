// https://codeforces.com/contest/1428/problem/E
// Carrots for Rabbits

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

ll sq(ll x)
{
    return x * x;
}

ll calc(ll v, ll c)
{
    ll dv = v / c, rem = v % c;
    return (c - rem) * sq(dv) + rem * sq(dv + 1);
}

ll solve()
{
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<ll> arr(n), cuts(n, 1);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res += calc(arr[i], cuts[i]);
        if (cuts[i] < arr[i])
            pq.push({calc(arr[i], cuts[i]) - calc(arr[i], cuts[i] + 1), i});
    }
    int cur_cuts = n;
    while (cur_cuts < k)
    {
        pii tp = pq.top();
        pq.pop();
        res -= tp.first;
        cuts[tp.second]++;
        if (cuts[tp.second] < arr[tp.second])
            pq.push({calc(arr[tp.second], cuts[tp.second]) - calc(arr[tp.second], cuts[tp.second] + 1), tp.second});
        cur_cuts++;
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