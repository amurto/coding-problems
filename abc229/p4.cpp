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

bool calc(vector<int> &pre, int ans, int k, int n)
{
    for (int i = ans - 1; i < n; i++)
    {
        int sum = pre[i];
        if (i - ans >= 0)
            sum -= pre[i - ans];
        if (sum <= k)
            return true;
    }
    return false;
}

int solve()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    int n = str.length();
    vector<int> pre(n);
    pre[0] = (str[0] == '.');
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + (str[i] == '.');
    int low = 1, high = n, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calc(pre, mid, k, n))
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
    cout << solve() << "\n";
    return 0;
}