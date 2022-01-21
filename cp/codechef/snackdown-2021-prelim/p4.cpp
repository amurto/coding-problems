#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(vector<string> &grid, vector<int> &arr, int n)
{
    int req = (n + 1) / 2;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= min(n - 1, i + req); j++)
            if (grid[arr[i]][arr[j]] == '0')
                return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int req = (n + 1) / 2, h = n / 2, mid = -1;
    vector<string> grid(n);
    vector<int> arr(n), tw(n), gw(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '1')
                tw[i]++;
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++)
        if (tw[i] >= req)
            arr1.pb(i);
        else if (n - tw[i] - 1 >= req)
            arr2.pb(i);
        else
            mid = i;
    int sz1 = arr1.size(), sz2 = arr2.size();
    auto cmp = [&](int &i1, int &i2)
    {
        return gw[i1] > gw[i2];
    };
    if (((n & 1) && mid == -1) || sz1 != h || sz2 != h)
    {
        cout << "-1\n";
        return;
    }
    arr[n / 2] = mid;
    for (int x : arr1)
        for (int y : arr1)
            if (grid[x][y] == '1')
                gw[x]++;
    for (int x : arr2)
        for (int y : arr2)
            if (grid[x][y] == '1')
                gw[x]++;
    sort(arr1.begin(), arr1.end(), cmp);
    sort(arr2.begin(), arr2.end(), cmp);
    for (int i = 0; i < h; i++)
        arr[i] = arr1[i];
    for (int i = req, j = 0; i < n; i++, j++)
        arr[i] = arr2[j];
    if (!check(grid, arr, n))
    {
        cout << "-1\n";
        return;
    }
    for (int x : arr)
        cout << x + 1 << " ";
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