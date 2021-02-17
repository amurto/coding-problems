#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<int> &arr, vector<int> &d, int l, int r, int dep)
{
    if (l > r)
        return;
    int mx = l;
    for (int i = l; i <= r; i++)
        if (arr[i] > arr[mx])
            mx = i;
    d[mx] = dep;
    dfs(arr, d, l, mx - 1, dep + 1);
    dfs(arr, d, mx + 1, r, dep + 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(arr, d, 0, n - 1, 0);
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
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