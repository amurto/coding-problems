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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1), pos(n + 1);
    iota(arr.begin(), arr.end(), 0);
    iota(pos.begin(), pos.end(), 0);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (pos[x] == n)
        {
            int y = arr[n - 1];
            swap(arr[pos[x]], arr[pos[y]]);
            swap(pos[x], pos[y]);
        }
        else
        {
            int y = arr[pos[x] + 1];
            swap(arr[pos[x]], arr[pos[y]]);
            swap(pos[x], pos[y]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}