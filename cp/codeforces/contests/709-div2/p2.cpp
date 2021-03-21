#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(vector<int> &arr, int n, int m, int c)
{
    if (c >= m)
        return false;
    for (int i = 0; i < n; i++)
        if (arr[i] >= m)
            return false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            int nxt = (arr[i - 1] + c) % m;
            if (arr[i] != nxt)
                return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    vector<int> up, dn;
    for (int i = 1; i < n; i++)
        if (arr[i] >= arr[i - 1])
            up.pb(arr[i] - arr[i - 1]);
        else
            dn.pb(arr[i - 1] - arr[i]);
    sort(up.begin(), up.end());
    sort(dn.begin(), dn.end());
    if (dn.empty())
    {
        (up[0] == up.back()) ? cout << "0\n" : cout << "-1\n";
        return;
    }
    if (dn[0] != dn.back())
    {
        cout << "-1\n";
        return;
    }
    if (up.empty())
    {
        cout << "0\n";
        return;
    }
    if (up[0] != up.back())
    {
        cout << "-1\n";
        return;
    }
    int c = up[0], m = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            m = arr[i - 1] + c - arr[i];
            break;
        }
    }
    if (check(arr, n, m, c))
    {
        cout << m << " " << c << "\n";
        return;
    }
    cout << "-1\n";
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