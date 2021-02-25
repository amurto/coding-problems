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
    sort(arr.begin(), arr.end());
    vector<int> res(n + 2);
    res[0] = 1e6;
    if (n & 1)
        res[n + 1] = 1e6;
    int mid = (n + 1) / 2;
    for (int i = mid - 1, j = 0; i >= 0; i--, j += 2)
        res[j + 1] = arr[i];
    for (int i = n - 1, j = 1; i >= mid; i--, j += 2)
        res[j + 1] = arr[i];
    bool pos = false;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            if (res[i - 1] <= res[i] || res[i] >= res[i + 1])
            {
                cout << -1;
                return;
            }
        }
        else
        {
            if (res[i - 1] >= res[i] || res[i] <= res[i + 1])
            {
                cout << -1;
                return;
            }
        }
    }
    for (int j = 1; j <= n; j++)
        cout << res[j] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}