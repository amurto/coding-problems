// https://codeforces.com/contest/762/problem/C
// Two strings

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

string solve()
{
    string a, b, ans = "";
    cin >> a >> b;
    int n = a.length(), m = b.length();
    int res = m;
    vector<int> pre(m), suf(m + 1);
    for (int idx = 0, i = 0; i < m; i++)
    {
        while (idx < n && a[idx] != b[i])
            idx++;
        pre[i] = idx;
        idx = min(idx + 1, n);
    }
    for (int idx = n - 1, i = m - 1; i >= 0; i--)
    {
        while (idx >= 0 && a[idx] != b[i])
            idx--;
        suf[i] = idx;
        idx = max(idx - 1, -1);
    }
    for (int i = 0; i < m; i++)
        if (pre[i] < n)
            res = min(res, m - i - 1);
    for (int i = m - 1; i >= 0; i--)
        if (suf[i] >= 0)
            res = min(res, i);
    suf[m] = n;
    for (int i = 0; i < m - 1; i++)
    {
        if (pre[i] < n)
        {
            int low = i + 1, high = m - 1, id = m - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (pre[i] < suf[mid + 1])
                {
                    id = min(id, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            res = min(res, id - i);
        }
    }
    if (res == 0)
        return b;
    if (res == m)
        return "-";
    for (int i = 0; i < m; i++)
        if (pre[i] < n && res == m - i - 1)
            return b.substr(0, i + 1);
    for (int i = m - 1; i >= 0; i--)
        if (suf[i] >= 0 && res == i)
            return b.substr(i, m - i);
    for (int i = 0; i < m - 1; i++)
    {
        if (pre[i] < n)
        {
            int low = i + 1, high = m - 1, id = m - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (pre[i] < suf[mid + 1])
                {
                    id = min(id, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if (res == id - i)
            {
                ans = b.substr(0, i + 1);
                if (id + 1 < m)
                    ans += b.substr(id + 1, m - id - 1);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}