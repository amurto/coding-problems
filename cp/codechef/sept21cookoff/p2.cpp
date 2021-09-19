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

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n > 4)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        x[i] = dx[i] * arr[i];
        y[i] = dy[i] * arr[i];
    }
    for (int i = 0; i < n; i++)
        cout << x[i] << " " << y[i] << "\n";
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