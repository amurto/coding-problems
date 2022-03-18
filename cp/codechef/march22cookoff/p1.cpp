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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<bool> vis(2 * n + 1);
    int cur = 1;
    for (int i = 0; i < n; i += 2)
    {
        while (vis[cur])
            cur++;
        arr[i] = cur;
        vis[cur] = true;
        if (i + 1 < n)
        {
            arr[i + 1] = 2 * cur;
            vis[2 * cur] = true;
        }
    }
    for (int x : arr)
        cout << x << " ";
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