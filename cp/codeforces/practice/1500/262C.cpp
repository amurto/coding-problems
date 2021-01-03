// https://codeforces.com/contest/262/problem/C
// Maxim and Discounts

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, x, mn = INT_MAX, n, res = 0, cur = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        mn = min(mn, x);
    }
    priority_queue<int> pq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty())
    {
        res += pq.top();
        pq.pop();
        cur++;
        if (cur == mn)
        {
            if (!pq.empty())
                pq.pop();
            if (!pq.empty())
                pq.pop();
            cur = 0;
        }
    }
    cout << res << "\n";
    return 0;
}