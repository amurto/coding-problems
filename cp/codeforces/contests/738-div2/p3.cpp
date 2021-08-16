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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    if (arr[1] == 1)
    {
        cout << n + 1 << " ";
        for (int j = 1; j <= n; j++)
            cout << j << " ";
        cout << "\n";
        return;
    }
    else if (arr[n] == 0)
    {
        for (int j = 1; j <= n; j++)
            cout << j << " ";
        cout << n + 1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i - 1] == 0 && arr[i] == 1)
        {
            for (int j = 1; j <= i - 1; j++)
                cout << j << " ";
            cout << n + 1 << " ";
            for (int j = i; j <= n; j++)
                cout << j << " ";
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
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