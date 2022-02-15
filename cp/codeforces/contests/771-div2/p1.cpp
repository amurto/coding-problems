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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mn = -1;
    for (int i = 0; mn == -1 && i < n; i++)
        if (i + 1 != arr[i])
            mn = i + 1;
    if (mn != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mn)
            {
                reverse(arr.begin() + mn - 1, arr.begin() + i + 1);
                break;
            }
        }
    }
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