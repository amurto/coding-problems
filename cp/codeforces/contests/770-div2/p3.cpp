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
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k >= 2)
        {
            cout << "NO\n";
            return;
        }
    }
    if (k == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << "\n";
        return;
    }
    int cnt = n * k;
    if (cnt & 1)
    {
        cout << "NO\n";
        return;
    }
    int h = cnt / 2;
    if (h % k != 0)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> arr(n, vector<int>(k));
    for (int i = 0, cur = 1; i < n / 2; i++)
        for (int j = 0; j < k; j++, cur += 2)
            arr[i][j] = cur;
    for (int i = n / 2, cur = 2; i < n; i++)
        for (int j = 0; j < k; j++, cur += 2)
            arr[i][j] = cur;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int x : arr[i])
            cout << x << " ";
        cout << "\n";
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