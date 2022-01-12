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

const int N = 2e5 + 5;
int last[N];
int solve()
{
    int n, res = -1;
    cin >> n;
    vector<int> arr(n), ids(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        last[arr[i]] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (last[arr[i]] >= 0)
            res = max(res, n - (i - last[arr[i]]));
        last[arr[i]] = i;
    }
    return res;
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