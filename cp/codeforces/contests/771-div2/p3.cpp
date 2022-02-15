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
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1), pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = max(pre[i - 1], arr[i]);
    }
    suf[n] = arr[n];
    for (int i = n - 1; i > 0; i--)
        suf[i] = min(arr[i], suf[i + 1]);
    for (int i = 1; i <= n;)
    {
        int r = i + 1;
        while (r <= n && pre[r - 1] > suf[r])
            r++;
        i = r;
        res++;
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