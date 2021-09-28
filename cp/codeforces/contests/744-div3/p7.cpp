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
    int n, diff;
    cin >> n >> diff;
    int res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int g = __gcd(diff, n);
    int inc = diff / g;
    for (int t = 0; t < g; t++)
    {
        vector<int> seq;
        int z = 0;
        for (int itr = t; itr < n; itr += g)
        {
            seq.pb(arr[itr]);
            if (arr[itr] == 0)
                z++;
        }
        if (z == 0)
            return -1;
        int sz = (int)seq.size();
        queue<int> q;
        for (int i = 0; i < sz; i++)
            if (seq[i] == 0)
                q.push(i);
        int op = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len > 0)
            {
                int cur = q.front();
                q.pop();
                int nxt = (cur + inc) % sz;
                if (seq[nxt] == 1)
                {
                    seq[nxt] = 0;
                    q.push(nxt);
                }
                len--;
            }
            op++;
        }
        res = max(res, op - 1);
    }
    return res;
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