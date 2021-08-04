#ifdef amurto
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
    int q, t;
    ll x, d = 0;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t < 3)
        {
            cin >> x;
            if (t == 1)
                pq.push(x - d);
            else
                d += x;
        }
        else
        {
            cout << pq.top() + d << "\n";
            pq.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}