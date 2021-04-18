// https://codeforces.com/contest/1174/problem/D
// Ehab and the Expected XOR Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, x;
    cin >> n >> x;
    int lim = (1 << n);
    vector<int> pre = {0}, arr;
    vector<bool> vis(1 << 18);
    vis[0] = true;
    for (int i = 1; i < lim; i++)
    {
        if (!vis[x ^ i])
        {
            pre.pb(i);
            vis[i] = true;
        }
    }
    cout << pre.size() - 1 << "\n";
    for (int i = 1; i < pre.size(); i++)
        cout << (pre[i - 1] ^ pre[i]) << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}