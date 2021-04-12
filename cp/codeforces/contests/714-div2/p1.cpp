#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 2 && k > 0)
    {
        cout << "-1\n";
        return;
    }
    if (k >= (n + 1) / 2)
    {
        cout << "-1\n";
        return;
    }
    int l = 2, r = n;
    vector<bool> vis(n + 1);
    vis[1] = true;
    vector<int> arr;
    arr.pb(1);
    while (k > 0)
    {
        vis[r] = vis[l] = true;
        arr.pb(r--);
        arr.pb(l++);
        k--;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            arr.pb(i);
    for (int a : arr)
        cout << a << " ";
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