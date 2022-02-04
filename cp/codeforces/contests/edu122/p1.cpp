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

int diff(int x, int y)
{
    int cnt = 0;
    if (x / 100 != y / 100)
        cnt++;
    if (x / 10 != y / 10)
        cnt++;
    if (x % 10 != y % 10)
        cnt++;
    return cnt;
}

int solve()
{
    int n, mn = 10, ans = 10000;
    cin >> n;
    int beg = 10, ed = 99;
    if (n >= 100)
    {
        beg = 100;
        ed = 999;
    }
    for (int i = beg; i <= ed; i++)
    {
        if (i % 7 == 0)
        {
            int dis = diff(n, i);
            if (dis < mn)
            {
                mn = dis;
                ans = i;
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
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}