// https://codeforces.com/contest/581/problem/C
// Developing Skills

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, v, res = 0, rem = 0;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        res += v / 10;
        rem += (100 - v) / 10;
        if (v % 10 > 0)
            pq.push(v % 10);
    }
    while (!pq.empty() && k >= 10 - pq.top())
    {
        int req = 10 - pq.top();
        pq.pop();
        k -= req;
        res++;
    }
    k /= 10;
    res += min(k, rem);
    cout << res << "\n";
    return 0;
}