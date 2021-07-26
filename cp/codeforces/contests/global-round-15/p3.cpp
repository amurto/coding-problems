#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll get_intersections(vector<int> &arr, int n)
{
    ll res = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (i < arr[i])
            for (int j = i + 1; j < arr[i]; j++)
                res += 1ll * (arr[j] < i || arr[j] > arr[i]);
    return res / 2;
}

ll solve()
{
    int n, k, x, y;
    cin >> n >> k;
    vector<int> arr(2 * n + 1);
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        arr[x] = y;
        arr[y] = x;
    }
    vector<int> tmp;
    for (int i = 1; i <= 2 * n; i++)
        if (arr[i] == 0)
            tmp.pb(i);
    int sz = tmp.size();
    for (int i = 0, j = sz / 2; j < sz; i++, j++)
    {
        arr[tmp[i]] = tmp[j];
        arr[tmp[j]] = tmp[i];
    }
    return get_intersections(arr, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}