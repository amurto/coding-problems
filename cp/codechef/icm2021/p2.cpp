#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool valid(vector<int> &arr)
{
    if (arr.empty())
        return true;
    return is_sorted(arr.begin(), arr.end());
}

void solve()
{
    int n, last = 0, mx = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= arr[mx])
            mx = i;
    }
    vector<int> a, b;
    for (int i = 0; i <= mx; i++)
        a.pb(arr[i]);
    for (int i = mx + 1; i < n; i++)
        b.pb(arr[i]);
    if (valid(a) && valid(b))
    {
        cout << "YES\n";
        (mx == n - 1) ? cout << "0\n" : cout << "1\n";
        return;
    }
    cout << "NO\n";
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