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
    int n, c;
    cin >> n >> c;
    vector<int> arr(n), pre(c + 1);
    vector<bool> vis(c + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pre[arr[i]]++;
        vis[arr[i]] = true;
    }
    for (int i = 1; i <= c; i++)
        pre[i] += pre[i - 1];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[i] == arr[r])
            r++;
        for (int j = arr[i], t = 1; j <= c; j += arr[i], t++)
            if (!vis[t] && pre[min(c, j + arr[i] - 1)] - pre[j - 1] > 0)
                return false;
        i = r;
    }
    return true;
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