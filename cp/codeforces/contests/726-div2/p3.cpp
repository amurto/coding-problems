#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mn = 1e9 + 7;
    sort(arr.begin(), arr.end());
    if (n == 2)
    {
        cout << arr[0] << " " << arr[1] << "\n";
        return;
    }
    for (int i = 1; i < n; i++)
        mn = min(mn, arr[i] - arr[i - 1]);
    int l = 0, r = 1, cnt = 0, h = n - 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == mn)
        {
            l = i - 1;
            r = i;
        }
    }
    for (int i = r; i < n; i++)
        cout << arr[i] << " ";
    for (int i = 0; i <= l; i++)
        cout << arr[i] << " ";
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