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
    int n, res = 1;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        a[i] = min(a[i], n - i);
        b[i] = min(b[i], i - 1);
    }
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2, cur = 0;
        for (int i = 1; cur < mid && i <= n; i++)
        {
            if (a[i] + 1 + b[i] >= mid)
            {
                if (b[i] >= cur && mid - cur - 1 <= a[i])
                    cur++;
            }
        }
        if (cur == mid)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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