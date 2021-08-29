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

int invert(int x)
{
    if (x == 1)
        return -1;
    return 1;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> pre(n + 1);
    map<int, vector<int>> ids;
    for (int i = 1; i <= n; i++)
    {
        int cur = 1;
        if (str[i - 1] == '-')
            cur = -1;
        if (i % 2 == 0)
            cur = invert(cur);
        pre[i] = pre[i - 1] + cur;
        ids[pre[i]].pb(i);
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int sum = pre[r] - pre[l - 1];
        if (sum == 0)
            cout << 0 << "\n";
        else
        {
            vector<int> del;
            if (abs(sum) % 2 == 0)
                del.pb(l++);
            sum = pre[r] - pre[l - 1];
            int req = pre[l - 1] + sum - sum / 2;
            del.pb(ids[req][lower_bound(ids[req].begin(), ids[req].end(), l) - ids[req].begin()]);
            cout << del.size() << "\n";
            for (int dd : del)
                cout << dd << " ";
            cout << "\n";
        }
    }
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