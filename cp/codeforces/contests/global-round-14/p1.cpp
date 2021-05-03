#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, x, sum = 0, w = 0, p = 0;
    cin >> n >> x;
    vector<int> arr(n), res;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    if (sum == x)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        w += arr[i];
        if (w == x)
        {
            swap(arr[i], arr[i + 1]);
            break;
        }
    }
    cout << "YES\n";
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