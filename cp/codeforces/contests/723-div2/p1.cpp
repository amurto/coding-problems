#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, p = 1;
    cin >> n;
    vector<int> arr(2 * n), res(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 2 * n - 1, j = 0; i >= n; i--, j += 2)
        res[j] = arr[i];
    for (int i = n - 1, j = 1; i >= 0; i--, j += 2)
        res[j] = arr[i];
    for (int a : res)
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