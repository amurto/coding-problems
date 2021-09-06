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

void solve()
{
    int s, n;
    cin >> s >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> arr;
    for (int i = 1; s > 0; i *= 10)
    {
        int dig = s % 10;
        while (dig > 0)
        {
            pq.push(i);
            dig--;
        }
        s /= 10;
    }
    int sz = (int)pq.size();
    while (sz < n)
    {
        int p = pq.top();
        pq.pop();
        if (p == 1)
            arr.pb(p);
        else
        {
            int num = p, dig = 0;
            while (p > 0)
            {
                dig = p % 10;
                p /= 10;
            }
            if (dig == 1)
                dig = 10;
            p = num / dig;
            sz += dig - 1;
            while (dig > 0)
            {
                pq.push(p);
                dig--;
            }
        }
    }
    while (!pq.empty())
    {
        arr.pb(pq.top());
        pq.pop();
    }
    if (sz > n)
        for (int i = n; i < sz; i++)
            arr[n - 1] += arr[i];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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