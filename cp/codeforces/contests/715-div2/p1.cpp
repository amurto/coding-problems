#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), p(2), res;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[arr[i] % 2]++;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            res.pb(arr[i]);
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 1)
            res.pb(arr[i]);
    if (p[1] > p[0])
        reverse(res.begin(), res.end());
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