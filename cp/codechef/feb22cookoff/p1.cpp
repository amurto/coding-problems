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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    iota(arr.begin(), arr.end(), 0);
    for (int i = k + 2; i <= n; i += 2)
        swap(arr[i - 1], arr[i]);
    if ((n - k) & 1)
        swap(arr[1], arr[n]);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (arr[i] % i == 0)
            cnt++;
    if (cnt != k)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
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