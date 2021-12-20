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
    string str;
    cin >> str;
    int n = (int)str.length(), val = 0, res = 1e9;
    vector<int> pre(n), suf(n);
    int cnt = 0;
    suf[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (str[i] == ')')
            suf[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            pre[i] = 0;
        else
            pre[i] = pre[i - 1];
        if (str[i] == '(')
        {
            pre[i] = i;
            cnt++;
        }
        else
            cnt--;
        if (cnt == 0 && i + 1 < n)
            res = min(res, suf[i + 1] - i - 1);
    }
    res = min(res, suf[0]);
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