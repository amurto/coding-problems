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

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    array<int, 2> mx{0, 0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & 1)
        {
            if (mx[1] > arr[i])
                return false;
            mx[1] = max(mx[1], arr[i]);
        }
        else
        {
            if (mx[0] > arr[i])
                return false;
            mx[0] = max(mx[0], arr[i]);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}