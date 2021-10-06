// https://codeforces.com/contest/1333/problem/F
// Kate and imperfection

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

void solve()
{
    int n;
    cin >> n;
    vector<int> res(n + 1), lp(n + 1), pr;
    for (int i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 1, cur = 1; i <= n; i++)
    {
        int last = cur;
        bool pos = true;
        for (int j = 0; pos && j < (int)pr.size(); j++)
        {
            int num = i * pr[j];
            if (num > n || num / lp[num] != i)
                pos = false;
            if (pos)
                cur++;
        }
        for (int j = last + 1; j <= cur; j++)
            res[j] = i;
    }
    for (int i = 2; i <= n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}