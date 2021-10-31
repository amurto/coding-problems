// https://codeforces.com/contest/1474/problem/D
// Cleaning

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

bool solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n + 2), pre(n + 2), suf(n + 2), pmn(n + 2), smn(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = arr[i] - pre[i - 1];
        pmn[i] = min(pmn[i - 1], pre[i]);
    }
    for (int i = n; i > 0; i--)
    {
        suf[i] = arr[i] - suf[i + 1];
        smn[i] = min(smn[i + 1], suf[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        if (pmn[i - 2] >= 0 && smn[i + 1] >= 0)
        {
            if (pre[i - 1] >= 0 && pre[i - 1] == suf[i])
                return true;
            if (arr[i] - pre[i - 2] >= 0 && arr[i] - pre[i - 2] == arr[i - 1] - suf[i + 1])
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}