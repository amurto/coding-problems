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
    int mid = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= arr[mid])
            mid = i;
    vector<vector<int>> op;
    vector<int> u(2);
    int par = arr[mid] % 2;
    u[par] = arr[mid];
    u[par ^ 1] = arr[mid] + 1;
    for (int i = mid - 1, p = par ^ 1; i >= 0; i--, p ^= 1)
    {
        vector<int> tmp(4);
        tmp[0] = mid + 1;
        tmp[1] = i + 1;
        tmp[2] = arr[mid];
        tmp[3] = u[p];
        arr[i] = u[p];
        op.pb(tmp);
    }
    for (int i = mid + 1, p = par ^ 1; i < n; i++, p ^= 1)
    {
        vector<int> tmp(4);
        tmp[0] = mid + 1;
        tmp[1] = i + 1;
        tmp[2] = arr[mid];
        tmp[3] = u[p];
        arr[i] = u[p];
        op.pb(tmp);
    }
    cout << op.size() << "\n";
    for (vector<int> o : op)
    {
        for (int e : o)
            cout << e << " ";
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