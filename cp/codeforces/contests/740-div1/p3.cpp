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

void rev(vector<int> &res, vector<int> &arr, int len, int n)
{
    res.pb(len);
    for (int i = 1, j = len; i <= j; i++, j--)
        swap(arr[i], arr[j]);
}

int get_pos(vector<int> &arr, int req, int n)
{
    for (int i = 1; i <= n; i++)
        if (arr[i] == req)
            return i;
    return n;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), res;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != arr[i] % 2)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int cur = n - 1; cur > 1; cur -= 2)
    {
        vector<int> ids = {cur, cur + 1}, pos(2);
        for (int j = 0; j < 2; j++)
            pos[j] = get_pos(arr, ids[j], n);
        if (ids[0] == pos[0] && ids[1] == pos[1])
            continue;
        if (pos[1] > 1)
            rev(res, arr, pos[1], n);
        pos[1] = 1;
        pos[0] = get_pos(arr, ids[0], n);
        if (pos[0] != 2)
        {
            rev(res, arr, pos[0] - 1, n);
            pos[1] = pos[0] - 1;
            rev(res, arr, pos[0] + 1, n);
            rev(res, arr, 3, n);
        }
        rev(res, arr, ids[1], n);
    }
    if (!is_sorted(arr.begin(), arr.end()))
    {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    if (!res.empty())
    {
        for (int r : res)
            cout << r << " ";
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