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
    int n, k, cur = 1;
    cin >> n >> k;
    vector<int> arr(n), ord(n);
    iota(ord.begin(), ord.end(), 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(ord.begin(), ord.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    for (int i = 1; i < n; i++)
        if (ord[i] != ord[i - 1] + 1)
            cur++;
    return cur <= k;
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