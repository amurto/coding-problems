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

int query(vector<int> &arr)
{
    int k = arr.size(), ans;
    cout << "? " << k << " ";
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> res(n + 1), arr;
    res[1] = 1;
    arr.pb(1);
    for (int i = 2; i <= n; i++)
    {
        int k = arr.size();
        res[i] = k + 1;
        int low = 1, high = k, id = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            vector<int> tmp;
            for (int j = k - mid; j < k; j++)
                tmp.pb(arr[j]);
            tmp.pb(i);
            int v = query(tmp);
            if (v == 2)
            {
                id = max(id, k - mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (id >= 0)
            res[i] = res[arr[id]];
        else
            arr.pb(i);
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
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