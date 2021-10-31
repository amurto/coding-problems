// https://codeforces.com/contest/1384/problem/B2
// Koa and the Beach (Hard Version)

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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> arr(n + 1), dis1(n + 1, -1), dis2(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        if (arr[i] > l)
            return false;
    dis1[0] = 0;
    dis2[0] = k;
    for (int i = 1; i <= n; i++)
    {
        if (dis1[i - 1] >= 0 && arr[i] + dis1[i - 1] + 1 <= l)
            dis1[i] = dis1[i - 1] + 1;
        if (dis1[i] >= 0 && arr[i] + k <= l)
        {
            dis1[i] = 0;
            dis2[i] = k;
        }
        else
        {
            if (dis2[i - 1] >= 0)
                dis2[i] = min(dis2[i - 1] - 1, l - arr[i]);
            if (dis2[i] >= 0)
                dis1[i] = 0;
            if (dis2[i] == 0)
                dis2[i] = -1;
        }
    }
    return dis1[n] >= 0 || dis2[n] >= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}