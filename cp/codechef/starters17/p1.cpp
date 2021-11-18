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
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        if (b[i - 1] % b[i] > 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int x : b)
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