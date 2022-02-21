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
    int n, res = 0;
    cin >> n;
    vector<int> arr(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            if (c[i - 1])
                arr[i - 1] = arr[i];
            else
            {
                arr[i + 1] = arr[i];
                c[i + 1] = 1;
            }
        }
    }
    for (int v : c)
        res += v;
    cout << res << "\n";
    for (int x : arr)
        cout << x << " ";
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