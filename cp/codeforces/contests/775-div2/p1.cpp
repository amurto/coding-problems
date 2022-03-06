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

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mn0 = n - 1, mx0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            mn0 = min(mn0, i);
            mx0 = max(mx0, i);
        }
    }
    if (mn0 == n - 1)
        return 0;
    return mx0 - mn0 + 2;
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